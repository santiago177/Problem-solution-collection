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
        if(operand.top() == '|')
        {
            o1 = values.top();
            values.pop();
            o2 = values.top();
            values.pop();
            values.push(o2 || o1);
            operand.pop();
        }
        else if(operand.top() == '&')
        {
            o1 = values.top();
            values.pop();
            o2 = values.top();
            values.pop();
            values.push(o2 && o1);
            operand.pop();
        }
        else if(operand.top() == '!')
        {
            o1 = values.top();
            values.pop();
            values.push(!o1);
            operand.pop();
        }
        else if(operand.top() == '(')
        {
            operand.pop();
            break;
        }
        else if(operand.empty())
            break;
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
        for(int a = 0; a < exp.size(); a++)
        {
            if(exp[a] == '|' || exp[a] == '&' || exp[a] == '!' || exp[a] == '(')
                operand.push(exp[a]);
            else if(exp[a] == 'F')
                values.push(false);
            else if(exp[a] == 'V')
                values.push(true);
            else if(exp[a] == ')' || !operand.empty())
                evaluate(values, operand);
        }
        if(values.top())
        cout << "Expression "<< ++cont <<": V"<<endl;
        else
        cout << "Expression "<< ++cont <<": F"<<endl;
        values.pop();
    }
    return 0;
}
