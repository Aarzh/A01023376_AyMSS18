#include <iostream>
using namespace std;

class Prueba{

public:
	int *val;
	int val2;
    Prueba(){
    	cout <<"Default Constructor"<<endl;
    }
    Prueba(int val) : val(new int (2)), val2(val){
    	cout << "Params " <<val<<endl;
    }
    Prueba(const Prueba& temp){	//copy constructor
    	val2 = *(temp.val);
    	val = new int (*(temp.val));
    }
};

int main()
{
	Prueba p;
	Prueba* z = new Prueba(2);
	cout<< "before "<<*(z->val)<<endl;
	Prueba w = *z;
	cout<< "copy "<<*(w.val)<<endl;
	*(w.val) = 8;
	cout<<"orginal z"<< *(z->val)<<endl;
	cout<<"copia w "<<*(w.val) <<endl;
	return 0;
}
