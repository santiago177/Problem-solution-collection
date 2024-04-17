#include <iostream>

using namespace std;

int main()
{
    goto fin;
    cout<<"not in goto"<<endl;
fin:
    cout<<"out"<<endl;
    return 0;
}
