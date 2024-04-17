#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    //freopen("340 - Master-Mind Hints.in", "r", stdin);
    int n, cont = 0;
    int code[1001], guess[1001];
    while(cin>>n && n != 0)
    {
        int ncode[10] = {0};
        printf("Game %d:\n", ++cont);
        for(int a = 0; a < n; a++)
        {
            cin>>code[a];
            ncode[code[a]]++;
        }
        while(1)
        {
            int occurrence[10] = {0}, strong = 0, total = 0;
            bool out = false;
            for(int a = 0; a < n; a++)
            {
                cin>>guess[a];
                if(guess[a] == 0)
                    out = true;
                occurrence[guess[a]]++;
                if(guess[a] == code[a])
                    strong++;
            }
            if(out)
                break;
            for(int a = 1; a < 10; a++)
            {
                if(occurrence[a] > ncode[a])
                    total += ncode[a];
                else
                    total += occurrence[a];
            }
            printf("    (%d,%d)\n", strong, total-strong);
        }
    }
    return 0;
}
