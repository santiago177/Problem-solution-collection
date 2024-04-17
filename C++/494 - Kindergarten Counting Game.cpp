#include <iostream>
#include <cstdio>

using namespace std;
int main()
{
    //freopen("494 - Kindergarten Counting Game.in", "r", stdin);
    string s;
    while(getline(cin, s))
    {
        bool open = false;
        int count = 0;
        for(int a = 0; a < s.size(); a++)
        {
            if(isalpha(s[a]) && !open)
                open = true;
            if(open && (s[a] == ' ' || !isalpha(s[a])))
            {
                count++;
                open = false;
            }
        }
        if(open)
            count++;
        cout<<count<<endl;
    }
    return 0;
}
