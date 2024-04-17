#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int k, c;
    bool out = false;
    string s, p;
    cin>>k;
    cin>>s;
    p = s;
    if(s.size() % k != 0)
        out = true;
    c = s.size()/k;
    string r;
    do
    {
        r = "";
        for(int a = 0; a < p.size(); a += c)
            r += p.substr(a, a+c);
        if(r == s)
            break;
    }while(next_permutation(p, p+p.size()))
    return 0;
}
