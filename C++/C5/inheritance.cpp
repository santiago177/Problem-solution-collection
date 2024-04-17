#include <iostream>

using namespace std;

class A
{
    protected:
        void func(int  & a)
        {
            a=a*2;
        }
 };

class B
{
    protected:
        void func(int  & a)
        {
            a=a*3;
        }
 };

class C
{
    protected:
        void func(int  & a)
        {
            a=a*5;
        }
};

class D : public A, public B, public C
{

    int val;
    public:
    //Initially, val is 1
    D()
    {
	val=1;
    }


    //Implement this function
    void update_val(int new_val)
    {
	A::func(new_val);
	B::func(new_val);
	C::func(new_val);
    }

};

int main() {

    D obj;
    
    return 0;
}
