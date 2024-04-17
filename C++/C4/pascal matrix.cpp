#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<long long> vll;

ll comb(int row, int col)
{
    ll n1 = 1, n2 = 1;
    if(row == col)
	return 1;
    if(col > row)
	return 0;
    for(int a = row-col+1; a <= row; a++)
    {
	n1 *= a;
    cout<<n1<<endl;
    if(n1 == 0)
	break;
    }
    for(int a = 1; a <= col; a++)
	n2 *= a;
    return n1/n2;    
}

int main()
{
    int cs;
    cin>>cs;
    for(int z = 0; z < cs; z++)
    {
	int k, p, r, c;
	cin>>k>>p>>r>>c;
	cout<<comb(100000, 5000)<<endl;
	vll row(r+1), col(r+1);
	for(int a = 0; a < r+1; a++)
	{
//	    row[a] = 
	}
    }
    return 0;
}
