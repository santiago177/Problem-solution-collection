#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int MOD = 1000003;

long fact(int n)
{
    if(n == 1)
	return 1;
    return (n * fact(n-1)) % MOD;
}


void print(vector<vector<bool> > &status)
{
    for(int a = 0; a < status.size(); a++)
    {
	for(int b = 0; b < status[a].size(); b++)
	    cout<<status[a][b];
	cout<<endl;
    }
}



int main()
{
    //freopen("apparatus.in", "r", stdin);
    int n, m;
    bool impossible = false;
    scanf("%d %d", &n, &m);
    vector<string> fotos;
    vector<vector<bool> > status;
    vector<int> row_count(n, n), col_count(n, n);
    vector<bool> counted(n, false);
    for(int a = 0; a < m*2; a++)
    {
	string s;
	cin>>s;
	fotos.push_back(s);
    }
    for(int a = 0; a < n; a++)
	status.push_back(vector<bool>(n, true));
    //Start of the processing
    for(int a = 0; a < fotos.size() && !impossible; a += 2)//Photos for
    {
	for(int b = 0; b < fotos[a].size() && !impossible; b++)//Row for
	{
	    bool c1;
	    if(fotos[a][b] == '1')
	        c1 = true;
	    else
	        c1 = false;
	    for(int c = 0; c < fotos[a].size() && !impossible; c++)//Column for
	    {
		bool c2;
		if(fotos[a+1][c] == '1')
		    c2 = true;
		else
		    c2 = false;
		if(status[b][c])
		{ 
		    status[b][c] = !(c1 ^ c2);
		    if(!status[b][c])
		    {
			row_count[b]--;
			col_count[c]--;
		    }
		    if(row_count[b] == 0 || col_count[c] == 0)
			impossible = true;
		}
	    } 
	}
    }
    long long total = 1;
    for(int a = 0; a < n && !impossible; a++)
    {
	int on = 0;
	//cout<<"a "<<a<<endl;
	for(int b = 0; b < n; b++)
	{
	    if(status[a][b]  && !counted[b])
	    {
		counted[b] = true;
		on++;
	    }
	}
	if(on > 1)
	{
	    total *= fact(on);
	    total %= MOD;
	}
	//cout<<total<<endl;
    }
    if(impossible)
	printf("0\n");
    else
	printf("%lld", total);
    return 0;
}

