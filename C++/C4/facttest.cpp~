#include <iostream>
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
    int n, m;
    cin>>n>>m;
    vector<string> fotos;
    vector<vector<bool> > status;
    vector<bool> counted(n, false);
    for(int a = 0; a < m*2; a++)
    {
	string s;
	cin>>s;
	fotos.push_back(s);
    }
    for(int a = 0; a < n; a++)
	status.push_back(vector<bool>(n, true));
    for(int a = 0; a < fotos.size(); a += 2)
    {
	for(int b = 0; b < fotos[a].size(); b++)
	{
	    bool c1;
	    if(fotos[a][b] == '1')
	        c1 = true;
	    else
	        c1 = false;
	    for(int c = 0; c < fotos[a].size(); c++)
	    {
		bool c2;
		if(fotos[a+1][c] == '1')
		    c2 = true;
		else
		    c2 = false;
		//cout<<"b "<<b<<" c "<<c<<" c1 "<<c1<<" c2 "<<c2<<endl;
		if(status[b][c])
		    status[b][c] = !(c1 ^ c2);
	    } 
	}
	//cout<<"___________"<<endl;
    }
    cout<<endl;
    print(status);
    long total = 0;
    for(int a = 0; a < n; a++)
    {
	int on = 0;
	cout<<"a "<<a<<endl;
	for(int b = 0; b < n; b++)
	{
	    if(status[a][b]  && !counted[b])
	    {
		counted[b] = true;
		on++;
	    }
	}
	for(int b = 0; b < n; b++)
	    cout<<counted[b];
	cout<<endl;
	if(on > 1)
	    total += fact(on);
    }
    cout<<total<<endl;
    //cout<<fact(1000, 1000003)<<endl;
    return 0;
}

