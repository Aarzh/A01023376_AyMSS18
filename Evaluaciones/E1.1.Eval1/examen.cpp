/*
    MADE BY: AARON ZAJAC
    GITHUB: AARZAJ
    MAT: A01023376
*/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class Person{
public:
    Person(string id, string name, string lastname, string type, string mail, string number, string street, string numC, string colonia){
        this->id = id;
        this->name = name;
        this->lastname = lastname;
        this->type = type;
        this->mail = mail;
        this->number = number;
        this->street = street;
        this->numC = numC;
        this->colonia = colonia;
    };

    string id;
    string name;
    string lastname;
    string type;
    string mail;
    string number;
    string street;
    string numC;
    string colonia;

};

class Creator{
public:
    virtual Person* factoryMethod(string id, string name, string lastname, string type, string mail, string number, string street, string numC, string colonia) = 0;
    Person* createPerson(string id, string name, string lastname, string type, string mail, string number, string street, string numC, string colonia){
        Person* myPerson = factoryMethod(id, name, lastname, type, mail, number, street, numC, colonia);
        return myPerson;
    }
};

class ConcreteCreator : public Creator{
    Person* factoryMethod(string id, string name, string lastname, string type, string mail, string number, string street, string numC, string colonia)
    {
        return new Person(id, name, lastname, type, mail, number, street, numC, colonia);
    }
    
};
class Prototype{
public:
    virtual Prototype* clone() = 0;
};

class Concrete1 : public Prototype
{
public:
    Prototype* clone(){
        
        return new Concrete1(*this);

    }
};

class Methods;

class Command
{
    Person *object;
    void(Person:: *func)();
  public:
    Command(Person *obj = 0, void(Person:: *meth)() = 0)
    {
        object = obj;
        func = meth;
    }
    void execute()
    {
        (object ->*func)();
    }
};

class Methods
{
    string name;
    Command cmd;
public:
    Methods(string n, Command c): cmd(c)
    {
        name = n;
    }
    void call()
    {
        cout << "Calling to " <<name<< endl;
    }
    void sms()
    {
        cout <<"Message to "<<name<< endl;
    }
    void mail()
    {
        cout << "Mailing to " <<name<< endl;
    }
    void contactAll(){
        call();
        sms();
        mail();
    }
};


class Email : public Person{
public:
    string from;
    string to;
    string subject;
    string body;
};

class Sms : public Person{
public:
    long int number;
    string text;
};

class Call : public Person{
public:
    long int number;
    string name;
    string msg;
};

void createContact ()
{
    Creator* persona = new ConcreteCreator();
    vector <Person> *clientes = new vector<Person>();
    ifstream file ( "customers.csv" );
    string id;
    string name;
    string lastname;
    string type;
    string mail;
    string number;
    string street;
    string numC;
    string colonia;
    while ( file.good() )
    {
        getline ( file, id, ',' );
        getline ( file, name, ',' );
        getline ( file, lastname, ',' );
        getline ( file, type, ',' );
        getline ( file, mail, ',' );
        getline ( file, number, ',' );
        getline ( file, street, ',' );
        getline ( file, numC, ',' );
        getline ( file, colonia, ',' );

        Person* p = persona->factoryMethod(id, name, lastname, type, mail, number, street, numC, colonia);
        clientes->push_back(*p);
    }
    file.close();
    return;
}

int main(){
    createContact();
    Concrete1* c = new Concrete1;
    Methods aaron("Aaron", Command());
    aaron.contactAll();
    return 0;
}