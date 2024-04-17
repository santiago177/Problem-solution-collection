#include <iostream>
#include <cstdio>
#include <list>
#include <map>
#include <vector>
#include <utility>

using namespace std;

int main()
{
//    list<int> p1, p2;
//    p1.push_back(1);
//    p2.push_back(2);
//    p1.push_back(2);
//    p2.push_back(1);
//    p1.sort();
//    p2.sort();
//    if(p1 == p2)
//        cout<<"si"<<endl
    //freopen("156 - Ananagrams.in", "r", stdin);
    map<string, bool> isanagram;
    map<string, list<char> > comp;
    vector<pair<string, list<char> > > strs;
    //vector<list<char> >comp;
    string s;
    while(cin>>s && s != "#")
    {
        //cout<<s<<endl;
        isanagram[s] = true;
        for(int a = 0; a < s.size(); a++)
        {
            comp[s].push_back(tolower(s[a]));
        }
        comp[s].sort();
    }
    for(map<string, list<char> >::iterator it = comp.begin(); it != comp.end(); it++)
    {
        strs.push_back(make_pair(it->first, it->second));
    }
    for(int a = 0; a < strs.size(); a++)
    {
        //cout<<strs[a].first<<endl;
        for(int b = a+1; b < strs.size(); b++)
        {
            if(strs[a].second == strs[b].second)
            {
                //cout<<"check"<<endl;
                isanagram[strs[a].first] = false;
                isanagram[strs[b].first] = false;
            }
        }
    }
    for(map<string, bool>::iterator it = isanagram.begin(); it != isanagram.end(); it++)
    {
        //cout<<it->first<<endl;
        if(it->second)
            cout<<it->first<<endl;
    }
    return 0;
}





