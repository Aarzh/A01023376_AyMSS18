#include <iostream>
using namespace std;

class Prototype
{
public:
    virtual Prototype* clone() = 0;
};

class Concrete1 : public Prototype
{
public:
    Prototype* clone(){
        /*Concrete1 copia = *this; //esto esta "bien" pero es un Dangling pointer (que se borra la variable al salir del metodo)
        return &copia;//devuelve la direccion del objecto que acabamos de crear*/
        return new Concrete1(*this);

    }
};

int main()
{
    Concrete1* c1 = new Concrete1;
}
