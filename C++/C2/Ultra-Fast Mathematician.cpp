#include <iostream>

using namespace std;

int main()
{
    bool ans[100];
    string a, b;
    cin>>a>>b;
    for(int c = 0; c < a.size(); c++)
	ans[c] = (a[c]-'0') ^ (b[c]-'0');
    for(int c = 0; c < a.size(); c++)
	cout<<ans[c];

    return 0;
}
