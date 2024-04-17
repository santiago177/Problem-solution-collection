#include <iostream>
#include <cstdio>

using namespace std;

string no_numbers(string s)
{
    string an = "";
    for(int a = 0; a < s.size(); a++)
        if(!isdigit(s[a]))
            an += s[a];
    return an;
}

string opposite_case(string s)
{
    string an = "";
    for(int a = 0; a < s.size(); a++)
    {
        if(isalpha(s[a]))
        {
            if(islower(s[a]))
                an += toupper(s[a]);
            else
                an += tolower(s[a]);
        }
        else
            an += s[a];
    }
    return an;
}

int main()
{
    freopen("5047 - Arbiter Login.in", "r", stdin);
    int n;
    cin>>n;
    for(int z = 0; z < n; z++)
    {
        string p, e, nonum;
        string opcase, nonopcase;
        cin>>p>>e;
        nonum = no_numbers(p);
        opcase = opposite_case(p);
        nonopcase = opposite_case(nonum);
//        Case 1: Login successful.
        cout<<"Case "<<z+1<<":";
        if(p == e)
            cout<<" Login successful."<<endl;
        else if(e == opcase)
            cout<<" Wrong password. Please, check your caps lock key."<<endl;
        else if(e == nonum)
            cout<<" Wrong password. Please, check your num lock key."<<endl;
        else if(e == nonopcase)
            cout<<" Wrong password. Please, check your caps lock and num lock keys."<<endl;
        else
            cout<<" Wrong password."<<endl;
//        cout<<p<<endl;
//        cout<<nonum<<endl;
//        cout<<opcase<<endl;
//        cout<<nonopcase<<endl;
//        cout<<endl;
    }
    return 0;
}
