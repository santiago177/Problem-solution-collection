#include <set>
#include <cstdio>
#include <iostream>
#include <sstream>

using namespace std;

string filter(string s)
{
    string ret = "";
    for(int a = 0; a < s.size(); a++)
        ret += tolower(s[a]);
    return ret;
}

int main()
{
    //freopen("10815 - Andy's First Dictionary.in", "r", stdin);
    string s, s2;
    set<string> dictionary;
    while(getline(cin, s))
    {
        string c = "";
        bool open = false;
        for(int a = 0; a < s.size(); a++)
        {
            if(isalpha(s[a]))
            {
                open = true;
                c += s[a];
            }
            else if(open)
            {
                c = filter(c);
                if(c != "")
                    dictionary.insert(c);
                open = false;
                c = "";
            }
        }
        c = filter(c);
        if(c != "")
            dictionary.insert(c);
    }
    for(set<string>::iterator it = dictionary.begin(); it != dictionary.end(); it++)
    {
        cout<<*it<<endl;
    }
}
