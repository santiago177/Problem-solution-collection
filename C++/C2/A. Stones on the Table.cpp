#include <iostream>

using namespace std;

int main()
{
    int n, c = 0;
    bool r, g, b;
    r = g = b = false;
    string s;
    cin>>n;
    cin>>s;
    for(int a = 0; a < n; a++)
    {
        cout<<"current "<<s[a]<<endl;
        cout<<r<<" "<<g<<" "<<b<<endl;
        if(s[a] == 'R')
        {
            if(r)
                c++;
            else
            {
                r = true;
                g = b = false;
            }
        }
        else if(s[a] == 'G')
        {
            if(g)
                c++;
            else
            {
                g = true;
                r = b = false;
            }
        }
        else
        {
            if(b)
                c++;
            else
            {
                b = true;
                r = g = false;
            }
        }
    }
    cout<<c;
    return 0;
}
