#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int main()
{
    long long n;
    cin>>n;
    long long c = n;
    vector<int> digits;
    while(c!=0)
    {
        digits.push_back(c%10);
        c /= 10;
    }
    priority_queue<long long> pq;
    for(int a = 0; a < digits.size(); a++)
    {
        long long neu = 0;
        for(int b = 0, j = 0; b < digits.size(); b++)
        {
            if(b != a)
            {
                neu += (long long)(pow(10,j)*digits[b]);
                j++;
//                cout<<"newc "<<neu;
            }
        }
        pq.push(neu);
//        cout<<"ne "<<neu<<endl;
    }
    cout<<pq.top();
    return 0;
}
