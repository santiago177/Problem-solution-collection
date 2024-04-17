#include <iostream>

using namespace std;

struct A {
    int a : 1;
};

int main()
{
    cout<<sizeof(A)<<endl;
    return 0;
}
