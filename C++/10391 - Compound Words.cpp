#include <iostream>
#include <cstdio>
#include <set>
#include <vector>

using namespace std;

int main()
{
    freopen("10391 - Compound Words.in", "r", stdin);
    //freopen("10391 - Compound Words.out", "r", stdout);
    string s;
    vector<string> words;
    set<string> comp;
    while(cin>>s)
    {
        words.push_back(s);
    }
    for(int a = 0; a < words.size(); a++)
    {
        for(int b = 0; b < words.size(); b++)
        {
            for(int c = b+1; c < words.size(); c++)
            {
                    if(words[a] == words[b]+words[c] || words[a] == words[c]+words[b] && b != a && c != a)
                        comp.insert(words[a]);
            }
        }
    }
    for(set<string>::iterator it = comp.begin(); it != comp.end(); it++)
    {
        cout<<*it<<endl;
    }
    return 0;
}
