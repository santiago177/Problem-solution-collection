#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    string n;
    while(cin>>n)
    {
        bool pal = true;
        int s = n.size(), cpyindex, pos;
        char ref;
        for(int a = 0; a <= s/2 && pal; a++)
        {
            if(n[a]!=n[s-a-1])
            {
                pal = false;
                ref = n[s-a-1];
                pos = a;
                //cout<<"check"<<endl;
            }
        }
        for(int a = 0; a < s && !pal; a++)
        {
            if(n[a] == ref)
            {
                cpyindex = a-1-pos;
                if(cpyindex < 0)
                    cpyindex = -cpyindex-1;
                cout<<"index "<<cpyindex<<" ref "<<ref<<endl;
                break;
            }
        }
        for(int a = cpyindex; a >= 0 && !pal; a--)
            n.push_back(n[a]);
        cout<<n<<endl;
    }
    return 0;
}
