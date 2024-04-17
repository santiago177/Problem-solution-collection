#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

unsigned long long to10(string num, int base)
{
    unsigned long long an = 0, pw = 0;
    for(int a = num.size()-1; a >= 0; a--)
    {
        an += pow(base, pw++)*(num[a]-'0');
        //cout<<an<<endl;
    }
    return an;
}

int main()
{
    //freopen("6173 - B-Casting.in", "r", stdin);
    int n;
    cin>>n;
    for(int z = 0; z < n; z++)
    {
        int d, b;
        unsigned long long an;
        string num;
        cin>>d>>b>>num;
        an = to10(num, b);
        cout<<d<<" "<<an%(b-1)<<endl;
    }
    return 0;
}
