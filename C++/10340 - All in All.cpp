#include <iostream>
#include <queue>

using namespace std;

int main()
{
    string s1, s2;
    while(cin>>s1>>s2)
    {
        queue<char> q;
        for(int a = 0; a < s1.size(); a++)
            q.push(s1[a]);
        for(int a = 0; a < s2.size() && !q.empty(); a++)
        {
            if(s2[a] == q.front())
                q.pop();
        }
        q.empty()?cout<<"Yes"<<endl:cout<<"No"<<endl;
    }
    return 0;
}
