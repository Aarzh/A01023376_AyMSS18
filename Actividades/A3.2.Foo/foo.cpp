#include <iostream>
using namespace std;

class Foo{
    int value;
    int * pointer;
public:
    explicit Foo(int value=0) : value(value), pointer(new int[value]){cout<<"Param Const"<<endl;}
    Foo(const Foo& val){cout<< "Copy cons "<<endl;}
    Foo(Foo&& temp){}
    Foo& operator=(const Foo& ref){
        cout<<"Copy assign"<<endl;
        Foo temp(ref);
        swap(value, temp.value);
        swap(pointer, temp.pointer);
        return *this;
    }

    //Rvalue references
    Foo& operator = (Foo&& temp){
        cout<<"Move assign"<<endl;
        swap(value, temp.value);
        swap(pointer, temp.pointer);
        return *this;
    }

};

int main(){
    Foo a(5);
    Foo b;
    b = Foo(15);

}