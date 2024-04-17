#include <iostream>
#include <cstdio>
#include <queue>
#include <stack>

using namespace std;

int main()
{
    //freopen("11995 - I Can Guess the Data Structure!.in", "r", stdin);
    //freopen("11995 - I Can Guess the Data Structure!.out", "w", stdout);
    bool st, qu, prq;
    int n;
    while(cin>>n)
    {
        int t, g;
        st = qu = prq = true;
        stack<int> s;
        queue<int> q;
        priority_queue<int> pq;
        for(int a = 0; a < n; a++)
        {
            cin>>t>>g;
            if(t == 1)
            {
                s.push(g);
                q.push(g);
                pq.push(g);
            }
            else
            {
                if(s.top() == g && st)
                    s.pop();
                else
                    st = false;
                if(q.front() == g && qu)
                    q.pop();
                else
                    qu = false;
                if(pq.top() == g && prq)
                    pq.pop();
                else
                    prq = false;
            }
        }
        if(st && !qu && !prq)
            cout<<"stack"<<endl;
        else if(qu && !st && !prq)
            cout<<"queue"<<endl;
        else if(prq && !st && !qu)
            cout<<"priority queue"<<endl;
        else if(!prq && !st && !qu)
            cout<<"impossible"<<endl;
        else
            cout<<"not sure"<<endl;
    }
    return 0;
}
