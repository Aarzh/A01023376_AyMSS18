#!/usr/bin/env python
import os
from json import dumps
from flask import Flask, g, Response, request

from neo4j.v1 import GraphDatabase, basic_auth

app = Flask(__name__, static_url_path='/static/')

password = os.getenv("NEO4J_PASSWORD")

driver = GraphDatabase.driver('bolt://localhost',auth=basic_auth("neo4j", "admin"))

def get_db():
    if not hasattr(g, 'neo4j_db'):
        g.neo4j_db = driver.session()
    return g.neo4j_db

@app.teardown_appcontext
def close_db(error):
    if hasattr(g, 'neo4j_db'):
        g.neo4j_db.close()

@app.route("/")
def get_index():
    return app.send_static_file('index.html')

def serialize_products(prod):
    return {
        'id': prod['id'],
        'title': prod['title'],
        'precio': prod['precio']
    }

def serialize_mPrimas(cast):
    return {
        'name': cast[0],
        'price': cast[1]
    }

@app.route("/graph")
def get_graph():
    db = get_db()
    results = db.run("MATCH (m:Productos)<-[:INGREDIENTE]-(a:M_Primas) "
             "RETURN m.title as prod, collect(a.name) as cast "
             "LIMIT {limit}", {"limit": request.args.get("limit", 100)})
    nodes = []
    rels = []
    i = 0
    for record in results:
        nodes.append({"title": record["prod"], "label": "prod"})
        target = i
        i += 1
        for name in record['cast']:
            actor = {"title": name, "label": "actor"}
            try:
                source = nodes.index(actor)
            except ValueError:
                nodes.append(actor)
                source = i
                i += 1
            rels.append({"source": source, "target": target})
    return Response(dumps({"nodes": nodes, "links": rels}),
                    mimetype="application/json")


@app.route("/search")
def get_search():
    try:
        q = request.args["q"]
    except KeyError:
        return []
    else:
        db = get_db()
        results = db.run("MATCH (prod:Productos) "
                 "WHERE prod.title =~ {title} "
                 "RETURN prod", {"title": "(?i).*" + q + ".*"}
        )
        return Response(dumps([serialize_products(record['prod']) for record in results]),
                        mimetype="application/json")


@app.route("/prod/<title>")
def get_prod(title):
    db = get_db()
    results = db.run("MATCH (prod:Productos {title:{title}}) "
             "OPTIONAL MATCH (prod)<-[r]-(person:M_Primas) "
             "RETURN prod.title as title,"
             "collect([person.name, "
             "         head(split(lower(type(r)), '_')), r.roles]) as cast "
             "LIMIT 1", {"title": title})

    result = results.single();
    return Response(dumps({"title": result['title'],
                           "cast": [serialize_mPrimas(member)
                                    for member in result['cast']]}),
                    mimetype="application/json")


if __name__ == '__main__':
    app.run(port=8080)