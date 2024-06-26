#include <iostream>

using namespace std;

class Complex {

    public:
    int a, b;
    Complex(int na, int nb) : a(na), b(nb) { }
    friend ostream& operator<<(ostream& ost, const Complex& cp);
};

ostream& operator<<(ostream& ost, const Complex& cp) {
    ost<<cp.a<<" + i"<<cp.b;
    return ost;
}

int main() {
    
    Complex cp(2, 3);
    cout<<cp<<endl;

    return 0;
}
