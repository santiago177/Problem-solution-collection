#include <iostream>

using namespace std;

class MyClass {
    private:
	int a;
    public:
	MyClass(int n) : a(n) { }
	MyClass(const MyClass& copy) : a(copy.a) {}
	friend ostream& operator<< (ostream& ost, const MyClass& mc);
};

ostream& operator<< (ostream& ost, const MyClass& mc) { 
    ost<<mc.a;
    return ost;
}

int main() {
    MyClass mc(5);
    MyClass copy(mc);
    cout<<mc<<endl;
    cout<<copy<<endl;
    return 0;
}
