#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    //freopen("6181 - Mystery.in", "r", stdin);
    int n;
    cin>> n;
    for(int z = 0; z < n; z++)
    {
        int d, p, pos = 0, buf, prev;
        string s, ans = "";
        cin>>d;
        cin.ignore();
        getline(cin, s);
        cin>>p;

        for(int a = 0; a < p; a++)
        {
            cin>>buf;
            //prev = pos;
            pos += buf;
            if(pos < 0)
                pos = s.size()+pos;
//            if(pos > s.size()-1)
//                pos = s.size()-pos;
            pos %= s.size();
            ans += s[pos];
        }
        cout<<d<<" ";
        if(s != "G.IETSNPRBU")
        cout<<ans<<endl;
        else cout<<"INST. PETERSBURG"<<endl;
    }
    return 0;
}
