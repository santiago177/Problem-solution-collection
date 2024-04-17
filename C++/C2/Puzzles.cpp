#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    vector<int> zahlen;
    cin>>n>>m;
    for(int a = 0; a < m; a++)
    {
	int t;
	cin>>t;
	zahlen.push_back(t);
    }
    int dif = 1<<30;
    n--;
    sort(zahlen.begin(), zahlen.end());
    for(int a = 0; a+n < m; a++)
    {
	if(zahlen[a+n] - zahlen[a] < dif)
	    dif = zahlen[a+n] - zahlen[a];
	if(dif == 0)
	    break;
    }
    cout<<dif<<endl;
    return 0;
}