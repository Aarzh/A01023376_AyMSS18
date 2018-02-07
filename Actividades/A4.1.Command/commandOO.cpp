/*
    MADE BY: AARON ZAJAC
    GITHUB: AARZAJ
    MAT: A01023376
*/
#include <iostream>
#include <string>

using namespace std;

class Person;

class Command
{
    // 1. Create a class that encapsulates an object and a member function
    // a pointer to a member function (the attribute's name is "func")
    Person *object; //
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

class Person
{
    string name;
    Command cmd;
public:
    Person(string n, Command c): cmd(c)
    {
        name = n;
    }
    void passOn()
    {
        cout << name << " is passing on" << endl;
        cmd.execute();
    }
    void talk()
    {
        cout << name << " habla" << endl;
        cmd.execute();
    }
    void listen()
    {
        cout << name << " escucha" << endl;
    }
};

int main()
{
    Person aaron("Aaron", Command());
    Person ariel("Ariel", Command(&aaron, &Person::passOn));
  ariel.talk();
}
