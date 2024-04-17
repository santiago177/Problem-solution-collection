#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    //freopen("11221 - Magic square palindromes.in", "r", stdin);
    int n;
    scanf("%d", &n);
    cin.ignore();
    for(int z = 0; z < n; z++)
    {
        printf("Case #%d:\n", z+1);
        int letters = 0;
        bool magic = true;
        string s;
        vector<char> words;
        getline(cin, s);
        for(int a = 0; a < s.size(); a++)
        {
            if(isalpha(s[a]))
            {
                words.push_back(s[a]);
                letters++;
            }
        }
        if(sqrt(letters)-(int)sqrt(letters) > 0)
        {
            printf("No magic :(\n");
            continue;
        }
        int rows = (int)sqrt(letters);
        for(int a = 0; a < words.size() && magic; a++)
        {
            if(words[a] != words[words.size()-1-a])
                magic = false;
        }
        if(magic)
            printf("%d\n", rows);
        else
            printf("No magic :(\n");
    }
    return 0;
}





