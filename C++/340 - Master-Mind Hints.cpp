#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, count = 0;
    bool first;
    while(1)
    {
        cin>>n;
        first = true;
        int ocur[10] = {0};
        int guess[10] = {0};
        int strong = 0, times = 0;
        vector<int> code;
        for(int a = 0; a < n; a++)
        {
            cin>>code[a];
            ocur[code[a]]++;
        }
        while(1)
        {
            int p;
            for(int a = 0; a < n; a++)
            {
                cin>>p;
                guess[p]++;
                if(code[a]==p)
                    strong++;

            }
            if(p == 0)
                break;
            for(int a = 1; a < 10; a++)
            {
                if(guess[p] > )
            }
        }
        if(vector[n-1] == 0)

    }
    return 0;
}
