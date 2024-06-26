#include <iostream>

using namespace std;

class Vehicle {
    protected:
	int weight, height;
    public:
	Vehicle (int a, int b) : weight(a), height(b) {}
	virtual void present() = 0;
};

class Bus: public Vehicle {
    public:
    void present() {
	cout<<"i'm a bus"<<endl;
    }
    Bus(int a, int b) : Vehicle(a, b) {}
};

class Train: public Vehicle {
    public:
    void present() {
	cout<<"i'm a train"<<endl;
    }
    Train(int a, int b) : Vehicle(a, b) {}
};


int main() {
    Vehicle * v1, * v2;
    Bus bus(500, 100);
    Train train(800, 100);
    v1 = &bus;
    v2 = &train;
    v1 -> present();
    v2 -> present();
    return 0;
}
