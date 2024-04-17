#include <iostream>
#include <cstdio>
#include <queue>
#include <stack>

using namespace std;

int main()
{
    //freopen("11995 - I Can Guess the Data Structure!.in", "r", stdin);
    int n;
    bool first = false;
    while(cin>>n)
    {
        first = true;
        bool is, iq, ipq;
        int com, num;
        stack<int> s;
        queue<int> q;
        priority_queue<int> pq;
        is = iq = ipq = true;
        for(int a = 0; a < n; a++)
        {
            cin>>com>>num;
            if(com == 1)
            {
                if(is)
                    s.push(num);
                if(iq)
                    q.push(num);
                if(ipq)
                    pq.push(num);

            }
            else
            {
                if(is)
                {
                    if(s.size() == 0)
                        is = false;
                    else if(s.top() == num)
                        s.pop();
                    else
                        is = false;
                }
                if(iq)
                {
                    if(q.size() == 0)
                        iq = false;
                    else if(q.front() == num)
                        q.pop();
                    else
                        iq = false;
                }
                if(ipq)
                {
                    if(pq.size() == 0)
                        ipq = false;
                    else if(pq.top() == num)
                        pq.pop();
                    else
                        ipq = false;
                }
            }
        }
        if(is&&!iq&&!ipq)
            printf("stack\n");
        else if(!is&&iq&&!ipq)
            printf("queue\n");
        else if(!is&&!iq&&ipq)
            printf("priority queue\n");
        else if(!is&&!iq&&!ipq)
            printf("impossible\n");
        else
            printf("not sure\n");
    }
    return 0;
}














