/*
    Aaron Zajac
    A01023376
*/
#include <iostream>
using namespace std;

class Moviles{
public:
    bool boton;
    bool *cambio;
    int value;
    int *vCambio;

    virtual Moviles* clone() = 0;

    Moviles* encender(){
        cambio = &boton;
        *cambio  = true;
    }
    Moviles* apagar(){
        cambio = &boton;
        *cambio  = true;
    }
    Moviles* reiniciar(){
        vCambio = &value;
        vCambio  = 0;
    }
    Moviles* restaurar(){
        cambio = &boton;
        *cambio  = false;
        vCambio = &value;
        *vCambio  = 9;
    }
};

class Tablet : public Moviles
{
public:
    Moviles* clone(){

        return new Tablet(*this);
    }
};

class SmartPhone : public Moviles
{
public:
    Moviles* clone(){
        return new SmartPhone(*this);
    }
    Moviles* encender(){}
    Moviles* apagar(){}
    Moviles* reiniciar(){}
    Moviles* restaurar(){}
};

class SmartWatch : public Moviles
{
public:
    Moviles* clone(){
        return new SmartWatch(*this);
    }
    Moviles* encender(){}
    Moviles* apagar(){}
    Moviles* reiniciar(){}
    Moviles* restaurar(){}
};

int main(){
    Tablet* ipad = new Tablet;
    Smartphone* iphone = new SmartPhone;
    SmartWatch* apple = new SmartWatch;
}
