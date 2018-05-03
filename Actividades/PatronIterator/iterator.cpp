#include <iostream>
using namespace std;

class IntCollection;

class IntIterator{
	protected:
		IntCollection* collection;
		int cont;
	public:
		virtual bool hasNext() = 0;
		virtual int next() = 0; //Regresa un apuntador del objeto.
};

class IntCollection{
	public:
		virtual void add(int element) = 0;
		virtual int at(int position) = 0;
		virtual IntIterator* getIterator() = 0;
		virtual int getNumElements() = 0;
		
};

class IntArray;

class ArrayIterator: public IntIterator{
	public:
		ArrayIterator(IntArray* intArray){
			collection = (IntCollection*)intArray;
			cont = 0;
		}
		
		int next(){
			return collection -> at(cont++);
		}
		bool hasNext(){
			if(cont >= collection-> getNumElements()){
				return false;
			}
			return true;
		}
		
		
		
};

class IntArray: public IntCollection{
	int* array;
	int size;
	int numElems;
	public:
		friend class ArrayIterator;
		IntArray(){
			size = 10;
			numElems = 0;
			array = new int[10];
		}
		
		void add(int element){
			if(numElems >= size){
				cout << "SI LI ACABU IL ISPACIU JUBEN"<< endl;
				return;
			}
			array[numElems++] = element;
			
		}
		
		int at(int position){
			if (size <= position || size < 0) {
				cout << "indice no valido" << endl;
				throw "out_of_range";
			}
			return array[position];
		}
		IntIterator* getIterator(){
			return new ArrayIterator(this);
		}
		int getNumElements(){
			return numElems;
		}
};


int main(){
	IntCollection* c = new IntArray;
	c->add(4);
	c->add(3);
	c->add(2);
	c->add(1);
	c->add(6);
	
	IntIterator* i = c-> getIterator();
	while (i->hasNext()) {
		cout << i -> next() << " ";
	}
}