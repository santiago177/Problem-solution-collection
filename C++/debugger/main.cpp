#include <iostream>
#include <stack>
#include <cstdio>

using namespace std;

void eval(stack<bool> &value, stack <char> &oper)
{
    bool o1, o2;
    while(1)
    {
        if(oper.empty())
            return;
        else if(oper.top() == '(')
        {
            oper.pop();
            if(!oper.empty() && oper.top() == '!')
            {
                o1 = value.top();
                value.pop();
                value.push(!o1);
                oper.pop();
            }
            if(!oper.empty() && oper.top() == '&')
            {
                o1 = value.top();
                value.pop();
                o2 = oper.top();
                value.pop();
                value.push(o1 && o2);
                oper.pop();
            }
            return;
        }
        else if(oper.top() == '|')
        {
            o1 = value.top();
            value.pop();
            o2 = value.top();
            value.pop();
            value.push(o1 || o2);
            oper.pop();
        }
    }
}
int main()
{
    //freopen("booleans.in", "r", stdin);
    //freopen("booleans.out", "w", stdout);
    string exp;
    int cont = 0;
    stack<bool> value;
    stack<char> oper;
    bool And = false;
    bool negate = false;
    bool o1, o2;
    while(getline(cin, exp))
    {
        for(int a = 0; a < exp.size(); a++)
        {
            if(exp[a] == '|')
                oper.push(exp[a]);
            else if(exp[a] == '!')
                negate = true;
            else if(exp[a] == '&')
                And = true;
            else if(exp[a] == '(')
            {
                if(And)
                    oper.push('&');
                if(negate)
                    oper.push('!');
                oper.push(exp[a]);
                And = false;
                negate = false;
            }
            else if(exp[a] == 'F')
            {
                value.push(false);
                if(negate)
                {
                    value.pop();
                    value.push(true);
                    negate = false;
                }
                if(And)
                {
                    o1 = value.top();
                    value.pop();
                    o2 = value.top();
                    value.pop();
                    value.push(o1 && o2);
                    And = false;
                }
            }
            else if(exp[a] == 'V')
            {
                value.push(true);
                if(negate)
                {
                    value.pop();
                    value.push(false);
                    negate = false;
                }
                if(And)
                {
                    o1 = value.top();
                    value.pop();
                    o2 = value.top();
                    value.pop();
                    value.push(o1 && o2);
                    And = false;
                }
            }
            else if(exp[a] == ')')
                eval(value, oper);
        }
        while(!oper.empty())
            eval(value, oper);
        if(value.top())
        cout <<"Expression "<<++cont<<": V"<<endl;
        else
        cout <<"Expression "<<++cont<<": F"<<endl; //Expression 1: F

    }
    return 0;
}
