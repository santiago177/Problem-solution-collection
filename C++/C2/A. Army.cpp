#include <iostream>

using namespace std;

int main()
{
    int n, array[100], a, b, c = 0;
    cin>>n;
    for(int f = 1; f < n; f++)
        cin>>array[f];
    cin>>a>>b;
    for(int f = a; f < b; f++)
        c += array[f];
    cout<<c;
    return 0;
}
