#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main()
{
    int n;
    while(cin>>n && n!=0)
    {
        int an = 0;
        for(int a = 1; a < n; a++)
        {
            //cout<<"a = "<<a<<endl;
            int insertions = 1;
            bool rev[101] = {0};
            stack<int> s;
            rev[0] = true;
            //cout<<"push "<<0<<endl;
            int b = 0, it = 0;
            while(insertions < n)
            {
                b = 0;
                while(b < a)
                {
                    it++;
                    it%=n;
                    if(!rev[it])
                        b++;
                }
                if(it == 12 && insertions+1 < n)
                    break;
                s.push(it);
                rev[it] = true;
                //cout<<"push "<<it<<endl;
                insertions++;

            }
            //cout<<"front = "<<s.top()<<endl;
            if(!s.empty() && s.top() == 12)
            {
                an = a;
                break;
            }
        }
        cout<<an<<endl;
    }
    return 0;
}
