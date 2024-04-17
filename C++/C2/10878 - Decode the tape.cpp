#include <iostream>
#include <cstdio>
#include <cstdlib>

int main()
{
    //freopen("10878 - Decode the tape.in", "r", stdin);
    char s[12];
    std::string s2;
    getline(std::cin, s2);
    while(1)
    {
//        std::cout<<s2<<std::endl;
        getline(std::cin, s2);
        if(s2 == "___________")
            break;
        char ans = 0;
        if(s2[9] == 'o')
            ans += 1;
        if(s2[8] == 'o')
            ans += 2;
        if(s2[7] == 'o')
            ans += 4;
        if(s2[5] == 'o')
            ans += 8;
        if(s2[4] == 'o')
            ans += 16;
        if(s2[3] == 'o')
            ans += 32;
        if(s2[2] == 'o')
            ans += 64;
        if(s2[1] == 'o')
            ans += 128;
        printf("%c", ans);
    }
    return 0;
}
