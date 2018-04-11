#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Videojuego{
private:
    string name;
    int price;
    int serial_number;
    static Videojuego* instancia;

    Videojuego();
public:

    static Videojuego* getInstancia();

    virtual void concepto() = 0;
    virtual void disenio() = 0;
    virtual void plan() = 0;
    virtual void produccion() = 0;
    virtual void pruebas() = 0;
};

Videojuego* Videojuego::instancia = 0;

Videojuego* Videojuego::getInstancia(){
    if (instancia == 0)
    {
        instancia = new Videojuego();
    }

    return instancia;
}

Videojuego::Videojuego(){}

class strategy : public Videojuego{
    public:
    void concepto(){
        cout<<"Building Concept "<<endl;
    }
    void disenio(){
        cout<<"Building desing "<<endl;
    }
    void plan(){
        cout<<"Building planification "<<endl;
    }
    void produccion(){
        cout<<"Building Production "<<endl;
    }
    void pruebas(){
        cout<<"Building open beta "<<endl;
    }
};

class adventure : public Videojuego{
    public:
    void concepto(){
        cout<<"Building Concept "<<endl;
    }
    void disenio(){
        cout<<"Building desing "<<endl;
    }
    void plan(){
        cout<<"Building planification "<<endl;
    }
    void produccion(){
        cout<<"Building Production "<<endl;
    }
    void pruebas(){
        cout<<"Building open beta "<<endl;
    }
};

class learning : public Videojuego{
    public:
    void concepto(){
        cout<<"Building Concept "<<endl;
    }
    void disenio(){
        cout<<"Building desing "<<endl;
    }
    void plan(){
        cout<<"Building planification "<<endl;
    }
    void produccion(){
        cout<<"Building Production "<<endl;
    }
    void pruebas(){
        cout<<"Building open beta "<<endl;
    }
};

class Prototype{
    protected:
    string type;
    string mode;
    int priority;

    public:
        virtual Prototype* clone() = 0;
        
        string getType(){
            return type;
        }

        string getMode(){
            return mode;
        }

        int getPriority(){
            return priority;
        }
};

class strategyPrototype : public Prototype{
    public:
    strategyPrototype(int num){
        type = "Lucha";
        mode = "arcade";
        priority = num;
    }

    Prototype* clone(){
        return new strategyPrototype(*this);
    }
};

class adventurePrototype : public Prototype{
    public:
    adventurePrototype(int num){
        type = "Platform";
        mode = "graphic";
        priority = num;
    }

    Prototype* clone(){
        return new adventurePrototype(*this);
    }
};

class learningPrototype : public Prototype{
    public:
    learningPrototype(int num){
        type = "Language";
        mode = "music";
        priority = num;
    }

    Prototype* clone(){
        return new learningPrototype(*this);
    }
};

class ArrayVideogames;
class Proxy{
private:
    ArrayVideogames* a;
    int indx;
public:
    Proxy(ArrayVideogames* a, int indx){
        this->a = a;
        this->indx = indx;
    }
    void operator=(string, int);
};

class ArrayVideogames{
    Videojuego * array;
    int size;
public:
    ArrayVideogames(){
        int size = 100;
        array = new Videojuego[size];
    }
    Proxy operator[](Videojuego obj, int idx){
        if(idx<0){
            cout<<"No existen indices negativos"<<endl;
        }
        return Proxy(this, idx);
    }
    Videojuego& setGet(int idx){
        return array[idx];
    }
};

void Proxy:: operator=(Videojuego obj, int indx){
    if(obj->price[indx]<0){
            cout<<"No existen precios negativos"<<endl;
        }else{
            a->setGet(indx) = obj->name;
        }
}

class Inventario{
    vector < Videojuego > inv;
    void insert(Videojuego obj){
        inv.push_back(obj);
    }
    void deleteLast(){
        inv.pop_back();
    }
    void deleteSerialNumber(Videojuego obj){
        for(int i = 0; i<inv.size; i++){
            if(inv->serial_number[i] == obj->serial_number){
                inv.erase(inv[i]);
            }else{
                cout<<"No se encuentra su Videojuego"<<endl;
            }
        }
    }
    void deletebyName(string name){
        for(int i = 0; i<inv.size; i++){
            if(inv->name[i] == name){
                inv.erase(inv[i]);
            }else{
                cout<<"No se encuentra su Videojuego"<<endl;
            }
        }
    }

    void searchElementbyName(string name){
        for(int i = 0; i<inv.size; i++){
            if(inv->name[i] == name){
                cout<<"Juego en la posicion: "<<i<<endl;
            }else{
                cout<<"No se encuentra su Videojuego"<<endl;
            }
        }
    }

    void searchElementbySerialNumber(int serial){
        for(int i = 0; i<inv.size; i++){
            if(inv->serial_number[i] == serial){
                cout<<"Juego en la posicion: "<<i<<endl;
            }else{
                cout<<"No se encuentra su Videojuego"<<endl;
            }
        }
    }

    void raisePrecio(float precio, int indx){
        inv->price[indx] = inv->price[indx]*precio;
        cout<<"Precio final: "<<inv->price[indx]<<endl;
    }

    void decreasePrecio(float precio, int indx){
        inv->price[indx] = inv->price[indx]/precio;
        cout<<"Precio final: "<<inv->price[indx]<<endl;
    }

    void printInvTotal(){
        cout<<"Total de inventario: "<<inv.size<<endl;
    }

    int swap(int el1, int el2)
	{
		int temp=inv->price[el1];
		array->price[el1]=array->price[el2];
		array->price[el2]=temp;
	}

    void sortMayorAMenor(){
        int cont;
        for (int i = 0; i < inv.size; ++i)
		{
			int min=i;
			for (int j = 0; j < inv.size; ++j)
			{
				if (inv->price[j]<inv->price[min])
				{
					min=j;
					cont++;
				}
			}
			swap(i, min);
		} 
    }

    void sortMenorAMayor(){
        int cont;
        for (int i = 0; i < inv.size; ++i)
		{
			int min=i;
			for (int j = 0; j < inv.size; ++j)
			{
				if (inv->price[j]<inv->price[min])
				{
					min=j;
					cont++;
				}
			}
			swap(min, i);
		} 
    }


    void printInventario(){
        for(int i= 0; i<inv.size(); i++){
            cout<<inv[i]<<endl;
        }
    }
    void searchByIndex(int idx){
        cout<<inv[idx]<<endl;
    }
};

class Subject {
    vector < class Observer * > views;
    string value;
  public:
    void attach(Observer *obs) {
        views.push_back(obs);
    }
    void speak(string msg) {
        value = msg;
        notifyAll();
    }
    string getMsg() {
        return value;
    }
    void notifyAll();
};

class Observer {
    // 2. "dependent" functionality
    Subject *model;
    string denom;
  public:
    Observer(Subject *mod, string msg) {
        model = mod;
        denom = msg;
        // 4. Observers register themselves with the Subject
        model->attach(this);
    }
    virtual void update() = 0;
  protected:
    Subject *getSubject() {
        return model;
    }
    string getMsg() {
        return denom;
    }
};

void Subject::notifyAll() {
  // 5. Publisher broadcasts
  for (int i = 0; i < views.size(); i++)
    views[i]->update();
}

int main(){
    Inventario a;
    int sn = 12345;
    string name = "Ariel";
    cout<<"///// Bienvenido a Jueg A.S./////"<<endl;
    cout<<"Como primer paso, debemos agregar algunos juegos a tu inventario "<<endl;
    a.insert(obj);
    cout<<"Ahora procedamos al menu principal: "<<endl;
    while(true){
        int resp;
        cout<<"1. Agregar Videojuegos"<<endl;
        cout<<"2. Eliminar el ultimo videojuego "<<endl;
        cout<<"3. Eliminar por Numero de serie "<<endl;
        cout<<"4. Eliminar por nombre "<<endl;
        cout<<"5. Buscar por nombre "<<endl;
        cout<<"6. Buscar por numero de serie "<<endl;
        cout<<"7. Incrementar precio de videojuegos"<<endl;
        cout<<"8. Decrementar precio de videojuegos"<<endl;
        cout<<"9. Imprimir el inventario total "<<endl;
        cout<<"10. Ordenar de mayor a menor por precios"<<endl;
        cout<<"11. Ordenar de menor a mayor por precios"<<endl;
        cout<<"12. Imprimir el tamanio del inventario total "<<endl;
        cin>>resp;
        if(resp == 1){
            a.insert(obj);
        }else if(resp == 2){
            a.deleteLast();
        }else if(resp == 3){
            a.deleteSerialNumber(obj);
        }else if(resp == 4){
            a.deletebyName(name);
        }else if(resp ==5){
            a.searchElementbyName(name);
        }else if(resp == 6){
            a.searchElementbySerialNumber(sn);
        }else if(resp == 7){
            a.raisePrecio(1.13, 2);
        }else if(resp == 8){
            a.decreasePrecio(1.13, 2);
        }else if(resp == 9){
            a.printInvTotal();
        }else if(resp == 10){
            a.sortMayorAMenor();
        }else if(resp == 11){
            a.sortMenorAMayor();
        }else if(resp == 12){
            a.printInventario();
        }else{
            return 0;
        }
    }
    return 0;
}