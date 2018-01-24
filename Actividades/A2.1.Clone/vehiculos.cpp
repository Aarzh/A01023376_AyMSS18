#include <iostream>
#include <string>

using namespace std;

class Vehiculo
{
    virtual void ensamblado() = 0;
    virtual void hojalateria() = 0;
    virtual void pintura() = 0;
    virtual void entrega() = 0;
};

class Dodge : public Vehiculo{
public:
    void ensamblado(){
        cout << "Dodge ensamblado "<<endl;
    }
    void hojalateria(){
        std::cout << "Dodge Hojalateado" << '\n';
    }
    void pintura(){
        std::cout << "Dodge pintado " << '\n';
    }
    void entrega(){
        std::cout << "Dodge entregado " << '\n';
    }
};

class BMW : public Vehiculo{
public:
    void ensamblado(){
        cout << "BMW ensamblado "<<endl;
    }
    void hojalateria(){
        std::cout << "BMW Hojalateado" << '\n';
    }
    void pintura(){
        std::cout << "BMW pintado " << '\n';
    }
    void entrega(){
        std::cout << "BMW entregado " << '\n';
    }
};

class Creator
{
    template <class Tipo>
    Tipo* factoryMethod(){
        return new Tipo;
    }

public:
    template <class Tipo>
    Tipo* create()
    {
        Tipo* temporal;
        temporal = factoryMethod<Tipo>();
        temporal->ensamblado();
        temporal->hojalateria();
        temporal->pintura();
        temporal->entrega();
        return temporal;
    }
};
int main()
{
    Creator* c =  new Creator;
    Dodge* car1 = c->create<Dodge>();

    return 0;
}
