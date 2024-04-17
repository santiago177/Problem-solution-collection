#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, cases = 0;
    while(cin>>n && n != 0)
    {
        int total = 0, rest = 0;
        vector<int> bricks(n);
        for(int a = 0; a < n; a++)
        {
            int t;
            cin>>t;
            bricks[a] = t;
            total += t;
        }
        total /= n;
        for(int a = 0; a < n; a++)
        {
            if(bricks[a] > total)
            {
                rest += bricks[a] - total;
            }
        }
//        Set #1
//The minimum number of moves is 5.
        cout<<"Set #"<<++cases<<endl;
        cout<<"The minimum number of moves is "<<rest<<"."<<endl<<endl;
    }
    return 0;
}
