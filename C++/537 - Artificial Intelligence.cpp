#include <iostream>
#include <cstdio>
#include <sstream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    cin.ignore();
    bool p, i, v;
    double vp, vi, vv;
    char val, s[];
    string s1, s2;
    for(int a = 0; a < n; a++)
    {
        getline(cin, s1);
        stringstream st(s1);
        while(st>>s2)
        {
            for(int b = 0; b < s2.size(); b++)
            {
                if(s2[b] == '=')
                {

                }
            }
        }
    }
    return 0;
}
