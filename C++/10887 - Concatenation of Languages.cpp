#include <iostream>
#include <cstdio>
#include <vector>
#include <set>

using namespace std;

int main()
{
    freopen("10887 - Concatenation of Languages.in", "r", stdin);
    int n;
    cin>>n;
    for(int a = 0; a < n; a++)
    {
        set<string> conc;
        int t, j;
        cin>>t>>j;
        cin.ignore();
        vector<string> l1(t);
        vector<string> l2(j);
        for(int b = 0; b < t; b++)
        {
            getline(cin, l1[b]);
            //cout<<l1[a]<<endl;
        }
        for(int b = 0; b < j; b++)
        {
            getline(cin, l2[b]);
            //cout<<l2[a]<<endl;
        }
        for(int b = 0; b < t; b++)
        {
            for(int c = 0; c < j; c++)
            {
//                cout<<"l1 "<<l1[b]<<endl;
//                cout<<"l2 "<<l2[c]<<endl;
//                cout<<"inserted "<<l1[b]+l2[c]<<endl;
                conc.insert(l1[b]+l2[c]);
            }
        }
//        Case 1: 6
//
//Case 2: 1
        cout<<"Case "<<a+1<<": "<<conc.size()<<endl;
    }
    return 0;
}
