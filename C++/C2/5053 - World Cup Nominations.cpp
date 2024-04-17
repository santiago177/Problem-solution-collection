#include <iostream>

using namespace std;

int main()
{
    int n;
    while(cin>>n && n!=0)
    {
        cin.ignore();
        int teams[1001] = {0}, an = 0;
        string s;
        for(int a = 0; a < n; a++)
        {
            getline(cin, s);
            for(int b = 0; b < s.size(); b++)
            {
                if(s[a] == '1')
                {
                    teams[a]++;
                    teams[b]--;
                }
                else
                {
                    teams[a]--;
                    teams[b]++;
                }
            }
        }
        for(int a = 0; a < n; a++)
        {
//            cout<<teams[a]<<" ";
            if(teams[a] >= 0)
                an++;
        }
        cout<<an<<endl;
    }
    return 0;
}
