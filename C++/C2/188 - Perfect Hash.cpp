#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <sstream>

using namespace std;

long long hash(string s)
{
    long long i = s[0]-'b';
    for(int a = 1; a < s.size(); a++)
    {
        i = i*32+(s[a]-'b');
    }
    return i;
}

int main()
{
    string s;
    while(getline(cin, s))
    {
        int an;
        priority_queue<long long> conver;
        vector<string> words;
        string cpy;
        stringstream st(s);
        while(st>>cpy)
            words.push_back(cpy);
        for(int a = 0; a < words.size(); a++)
            conver.push(-hash(words[a]));
        an = (int)()
        cout<<s<<endl;
        cout<<
    }
    return 0;
}




