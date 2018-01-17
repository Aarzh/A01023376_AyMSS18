#include <iostream>
#include <time.h>

using namespace std;

class Clock
{
private:
    static Clock* instance;
    Clock(){}

public:
    static Clock *getInstance(){
        if (instance == 0)
        {
            instance = new Clock;
        }
        return instance;
    }
    time_t t= time(0);

    void getDate(){
        struct tm * now = localtime( & t );
        cout << (now->tm_year + 1900) << '-' << (now->tm_mon + 1) << '-'<<  now->tm_mday<< endl;
    }
};

Clock* Clock::instance = 0;

int main() {

    Clock* instance1 = Clock::getInstance();
    instance1->getDate();
    Clock* instance2 = Clock::getInstance();
    instance2->getDate();
    cout<<instance1<<endl;
    cout<<instance2<<endl;


    return 0;
}
