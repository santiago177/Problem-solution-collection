#include <iostream>
#include <stack>
#include <cstdio>

using namespace std;

void evaluate(stack<bool> &values, stack<char> &operand)
{
    bool o1;
    bool o2;
    while(1)
    {
        if(operand.empty())
            break;
        else if(operand.top() == '(')
        {
            operand.pop();
            if(!operand.empty() && operand.top() == '!')
            {
                operand.pop();
                o1 = values.top();
                values.pop();
                values.push(!o1);
            }
            if(!operand.empty() && operand.top() == '&')
            {
                operand.pop();
                o1 = values.top();
                values.pop();
                o2 = values.top();
                values.pop();
                values.push(o2 && o1);
            }
            break;
        }
        else if(operand.top() == '|')
        {
            operand.pop();
            o1 = values.top();
            values.pop();
            /*if(operand.top() == '!')
            {
                operand.pop();
                o1 = !o1;
            }*/
            o2 = values.top();
            values.pop();
            /*if(operand.top() == '!')
            {
                operand.pop();
                o2 = !o2;
            }*/
            values.push(o2 || o1);
        }
        /*else if(operand.top() == '&')
        {
            o1 = values.top();
            values.pop();
            if(operand.top() == '!')
            {
                operand.pop();
                o1 = !o1;
            }
            o2 = values.top();
            values.pop();
            if(operand.top() == '!')
            {
                operand.pop();
                o2 = !o2;
            }
            values.push(o2 && o1);
            operand.pop();
        }*/
        /*else if(operand.top() == '!')
        {
            o1 = values.top();
            values.pop();
            values.push(!o1);
            operand.pop();
        } */
    }
}
int main()
{
    //freopen("booleans.in", "r", stdin);
    //freopen("booleans.out", "w", stdout);
    int cont = 0;
    stack<bool> values;
    stack<char> operand;
    string exp;
    while(getline(cin, exp))
    {
        bool negate = false;
        bool y = false;
        bool o1, o2;
        for(int a = 0; a < exp.size(); a++)
        {
            if(exp[a] == '|' || exp[a] == '&' || exp[a] == '!' || exp[a] == '(')
            {
                if(exp[a] == '&')
                {
                    y = true;
                    continue;
                }
                if(exp[a] == '!')
                {
                    negate = true;
                    continue;
                }
                if(exp[a] == '(')
                {
                    if(negate)
                    {
                        operand.push('!');
                        negate = false;
                    }
                    if(y)
                    {
                        operand.push('&');
                        y = false;
                    }
                }
                operand.push(exp[a]);
            }
            if(exp[a] == 'F')
            {
                if(negate)
                {
                    values.push(true);
                    negate = false;
                    if(y)
                    {
                        o1 = values.top();
                        values.pop();
                        o2 = values.top();
                        values.pop();
                        values.push(o2 && o1);
                        y = false;
                    }
                    continue;
                }
                values.push(false);
                if(y)
                {
                    o1 = values.top();
                    values.pop();
                    o2 = values.top();
                    values.pop();
                    values.push(o2 && o1);
                    y = false;
                    continue;
                }
            }
            if(exp[a] == 'V')
            {
                if(negate)
                {
                    values.push(false);
                    negate = false;
                    if(y)
                    {
                        o1 = values.top();
                        values.pop();
                        o2 = values.top();
                        values.pop();
                        values.push(o2 && o1);
                        y = false;
                    }
                    continue;
                }
                values.push(true);
                if(y)
                {
                    o1 = values.top();
                    values.pop();
                    o2 = values.top();
                    values.pop();
                    values.push(o2 && o1);
                    y = false;
                    continue;
                }
            }
            if(exp[a] == ')')
                evaluate(values, operand);
        }
        while(!operand.empty())
            evaluate(values, operand);
        if(values.top())
        cout << "Expression "<< ++cont <<": V"<<endl;
        else
        cout << "Expression "<< ++cont <<": F"<<endl;
        values.pop();
    }
    return 0;
}
