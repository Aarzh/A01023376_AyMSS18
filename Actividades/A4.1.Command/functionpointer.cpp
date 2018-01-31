#include <iostream>

using namespace std;

int suma(int a, int b){
    return a+b;
}

int resta(int a, int b){
    return a-b;
}

template<class T>
T duplica(T a)
{
    return a*2;
}

typedef int (*f)(int, int);
f getOperation(char o){
    if (o == 'r') {
        return resta;
    }else{
        return suma;
    }
}

template <class T, class function>
T doTemplateFunction(T a, T b, function f){
    return f (a,b);
}

template<class function>
function getTemplateOperation(char S){
    if (S == 'r') {
        return resta;
    }else if (S == 'd') {
        return duplica;
    }{
        return suma;
    }
}
int operacion(int a, int b, int (*f)(int, int))
{
    return f(a,b);
}

int main()
{
    cout << operacion(2, 2, suma)<< endl;
    cout << operacion(2, 2, resta)<< endl;
    //getOperation('S');
    cout << doTemplateFunction(2, 2, suma) << '\n';
    cout << getTemplateOperation<int (*)(int, int)> ('r')(2,2) << '\n';
    cout << getTemplateOperation<int (*)(int)> ('d')(2) << '\n';
}
