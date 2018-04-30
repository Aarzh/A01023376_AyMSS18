#include <iostream>
using namespace std;

template<class T>
class Collection{
	public:
		
};

template<class T>
class Iterator{
	Collection c;
	public:
		Iterator(Collection<T> cc){
			c = cc;
		}
		bool hasNext(){
			if(){
				
			}
			return false;
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