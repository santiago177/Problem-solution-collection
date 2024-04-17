#include <iostream>

using namespace std;

int main()
{
    int msg = 0x29c3;
    int key = 0x3226;
    int msg2 = 0x2943;
    int key2;
    int result = msg ^ key;
    key2 = msg2 ^ result;
    cout<<key2<<endl;
    return 0;
}
