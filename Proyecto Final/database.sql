---------- 1 ----------
CREATE (NopSalad:Productos {title:'Ensalada de nopales', precio:32})
CREATE (Nopal:M_Primas {name:'Nopales', price:12})
CREATE (Jitomate:M_Primas {name:'Jitomate', price:10})
CREATE (Cilantro:M_Primas {name:'Cilantro', price:5})
CREATE (Cebolla:M_Primas {name:'Cebolla', price:5})
CREATE
  (Nopal)-[:INGREDIENTE]->(NopSalad),
  (Jitomate)-[:INGREDIENTE]->(NopSalad),
  (Cebolla)-[:INGREDIENTE]->(NopSalad),
  (Cilantro)-[:INGREDIENTE]->(NopSalad)

---------- 2 ----------
CREATE (HotDog:Productos {title:'Perro Caliente', precio:52})
CREATE (Ketchup:M_Primas {name:'Ketchup', price:12})
CREATE (Mayonesa:M_Primas {name:'Mayonesa', price:10})
CREATE (Mostaza:M_Primas {name:'Mostaza', price:5})
CREATE (Salchicha:M_Primas {name:'Salchicha', price:5})
CREATE (Medias:M_Primas {name:'Medias Lunas', price:5})
CREATE
  (Ketchup)-[:INGREDIENTE]->(HotDog),
  (Mayonesa)-[:INGREDIENTE]->(HotDog),
  (Salchicha)-[:INGREDIENTE]->(HotDog),
  (Mostaza)-[:INGREDIENTE]->(HotDog),
  (Medias)-[:INGREDIENTE]->(HotDog)
---------- 3 ----------
CREATE (LemWater:Productos {title:'Agua de Limon', precio:18})
CREATE (Water:M_Primas {name:'Agua', price:7})
CREATE (Lemon:M_Primas {name:'Limon', price:7})
CREATE (Sugar:M_Primas {name:'Azúcar', price:4})
CREATE
  (Water)-[:INGREDIENTE]->(LemWater),
  (Lemon)-[:INGREDIENTE]->(LemWater),
  (Sugar)-[:INGREDIENTE]->(LemWater)

CREATE (Menu1:Productos{title:'Menu combo', precio:70})
CREATE
  (HotDog)-[:COMPUESTO]->(Menu1),
  (LemWater)-[:COMPUESTO]->(Menu1)
---------- 4 ----------
CREATE (Menu2:Productos{title:'Menu Llenador', precio:102})
CREATE (HotDog:M_Primas{name:'Perro Caliente', price: 52})
CREATE (PepWater:M_Primas{name:'Agua de Pepino', price: 18})
CREATE (NopSalad:M_Primas{name:'Ensalada de nopales', price: 32})
CREATE
  (HotDog)-[:COMPUESTO]->(Menu2),
  (PepWater)-[:COMPUESTO]->(Menu2),
  (NopSalad)-[:COMPUESTO]->(Menu2)
---------- 5 ----------
CREATE (PepWater:Productos {title:'Agua de pepino', precio:18})
CREATE (Water:M_Primas {name:'Agua', price:7})
CREATE (Pepino:M_Primas {name:'Pepino', price:7})
CREATE (Sugar:M_Primas {name:'Azúcar', price:4})
CREATE
  (Water)-[:COMPUESTO]->(PepWater),
  (Pepino)-[:COMPUESTO]->(PepWater),
  (Sugar)-[:COMPUESTO]->(PepWater)
---------- 6 ----------
CREATE (Cereal:Productos {title:'Cereal con leche', precio:38})
CREATE (Milk:M_Primas {name:'Leche', price:17})
CREATE (Oats:M_Primas {name:'Oats', price:10})
CREATE (Sugar:M_Primas {name:'Azúcar', price:11})
CREATE
  (Milk)-[:INGREDIENTE]->(Cereal),
  (Oats)-[:INGREDIENTE]->(Cereal),
  (Sugar)-[:INGREDIENTE]->(Cereal)
---------- 7 ----------
CREATE (Quesadilla:Productos {title:'Quesadillitas', precio:28})
CREATE (Tortil:M_Primas {name:'Tortillas', price:16})
CREATE (Ques:M_Primas {name:'Queso', price:12})
CREATE
  (Tortil)-[:INGREDIENTE]->(Quesadilla),
  (Ques)-[:INGREDIENTE]->(Quesadilla)
---------- 8 ----------
CREATE (Tco:Productos {title:'Tacos de pollo', precio:42})
CREATE (Pollo:M_Primas {name:'Pollo deshebrado', price:26})
CREATE
  (Tortil)-[:INGREDIENTE]->(Tco),
  (Pollo)-[:INGREDIENTE]->(Tco)
---------- 9 ----------
CREATE (TcoCar:Productos {title:'Tacos de carne', precio:38})
CREATE (Carne:M_Primas {name:'Carne deshebrado', price:22})
CREATE
  (Tortil)-[:INGREDIENTE]->(TcoCar),
  (Carne)-[:INGREDIENTE]->(TcoCar)
---------- 10 ----------
CREATE (TcoMix:Productos {title:'Tacos Mixtos', precio:48})
CREATE
  (Tortil)-[:INGREDIENTE]->(TcoMix),
  (Carne)-[:INGREDIENTE]->(TcoMix),
  (Pollo)-[:INGREDIENTE]->(TcoMix)
---------- 11 ----------
CREATE (QuesadillaTin:Productos {title:'Quesadilla de tinga', precio:42})
CREATE (Sals:M_Primas {name:'Salsa de tomate y huajillo', price:2})
CREATE
  (Tortil)-[:INGREDIENTE]->(QuesadillaTin),
  (Pollo)-[:INGREDIENTE]->(QuesadillaTin),
  (Sals)-[:INGREDIENTE]->(QuesadillaTin)
---------- 12 ----------
CREATE (QuesHongos:Productos {title:'Quesadilla de hongos', precio:22})
CREATE (Hong:M_Primas {name:'Hongos', price:8})
CREATE
  (Tortil)-[:INGREDIENTE]->(QuesHongos),
  (Hong)-[:INGREDIENTE]->(QuesHongos)
---------- 13 ----------
CREATE (SalsRoja:Productos {title:'Salsa roja', precio:25})
CREATE (Chile:M_Primas {name:'Chile serrano', price:5})
CREATE
  (Jitomate)-[:INGREDIENTE]->(SalsRoja),
  (Chile)-[:INGREDIENTE]->(SalsRoja),
  (Cebolla)-[:INGREDIENTE]->(SalsRoja),
  (Cilantro)-[:INGREDIENTE]->(SalsRoja)
---------- 14 ----------
CREATE (SalsVer:Productos {title:'Salsa Verde', precio:25})
CREATE (Tomate:M_Primas {name:'Tomate', price:5})
CREATE
  (Tomate)-[:INGREDIENTE]->(SalsVer),
  (Chile)-[:INGREDIENTE]->(SalsVer),
  (Cebolla)-[:INGREDIENTE]->(SalsVer),
  (Cilantro)-[:INGREDIENTE]->(SalsVer)
---------- 15 ----------
CREATE (ZanhChil:Productos {title:'Zanahorias con chile', precio:25})
CREATE (Zanh:M_Primas {name:'Zanahorias', price:20})
CREATE (ChilTaj:M_Primas {name:'Chile tajin', price:5})
CREATE
  (Zanh)-[:INGREDIENTE]->(ZanhChil),
  (ChilTaj)-[:INGREDIENTE]->(ZanhChil)
---------- 16 ----------
CREATE (JicChil:Productos {title:'Jicamas con chile', precio:25})
CREATE (Jic:M_Primas {name:'Jicamas', price:20})
CREATE (ChilTaj:M_Primas {name:'Chile tajin', price:5})
CREATE
  (Jic)-[:INGREDIENTE]->(JicChil),
  (ChilTaj)-[:INGREDIENTE]->(JicChil)
---------- 17 ----------
CREATE (PepChil:Productos {title:'Pepinos con chile', precio:25})
CREATE (Pep:M_Primas {name:'Pepinos', price:20})
CREATE (ChilTaj:M_Primas {name:'Chile tajin', price:5})
CREATE
  (Pep)-[:INGREDIENTE]->(PepChil),
  (ChilTaj)-[:INGREDIENTE]->(PepChil)
---------- 18 ----------
CREATE (CafeAm:Productos {title:'Café americano', precio:18})
CREATE (Water:M_Primas {name:'Agua', price:7})
CREATE (Caff:M_Primas {name:'Café', price:7})
CREATE (Sugar:M_Primas {name:'Azúcar', price:4})
CREATE
  (Water)-[:INGREDIENTE]->(CafeAm),
  (Caff)-[:INGREDIENTE]->(CafeAm),
  (Sugar)-[:INGREDIENTE]->(CafeAm)
---------- 19 ----------
CREATE (Creps:Productos {title:'Crepas de chocolate', precio:38})
CREATE (TortiH:M_Primas {name:'Tortillas de harina', price:18})
CREATE (Choc:M_Primas {name:'Chocolate', price:20})
CREATE
  (TortiH)-[:INGREDIENTE]->(Creps),
  (Choc)-[:INGREDIENTE]->(Creps)
---------- 20 ----------
CREATE (CrepsCaj:Productos {title:'Crepas de Cajeta', precio:38})
CREATE (TortiH:M_Primas {name:'Tortillas de harina', price:18})
CREATE (Caj:M_Primas {name:'Cajeta', price:20})
CREATE
  (TortiH)-[:INGREDIENTE]->(CrepsCaj),
  (Caj)-[:INGREDIENTE]->(CrepsCaj)

----------- QUERYS ----------
match (m:M_Primas) return m
match (p:Productos) return p
match (p:Productos) where p.title = 'nombre' return p
match (p:Productos) where p.precio = 'precio' return p
match (p:Productos) return p.precio
