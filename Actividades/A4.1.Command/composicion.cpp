#include <iostream>

using namespace std;

template <int n>
class Repeat : public Repeat<n-1>
{
public:
    Repeat(){
        cout << n << '\n';
    }
};

template<>
class Repeat<0>
{
public:
    Repeat(){
        std::cout << "0" << '\n';
    }
};

int main() {
    Repeat<100> a;
    return 0;
}
