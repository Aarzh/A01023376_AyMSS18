/*
    Aaron Zajac
    A01023376
*/
#ifndef TAREA1_H_INCLUDED
#define TAREA1_H_INCLUDED
#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>

using namespace std;

class Hora{

public:

Hora(){}
~Hora(){}

void obtenerHora(){
    auto t = time(nullptr);
    auto tm = *localtime(&t);

    ostringstream oss;
    oss << put_time(&tm, "%d-%m-%Y %H-%M-%S");
    auto str = oss.str();

    cout << str << endl;
}
};
#endif // TAREA1_H_INCLUDED
