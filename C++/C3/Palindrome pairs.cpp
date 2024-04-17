#include <iostream>
#include <vector>

using namespace std;

bool test(string s)
{
    for(int a = 0; a < s.size()/2; a++)
	if(s[a] != s[s.size()-a-1])
	    return false;
    return true;
}

string toString(string s, int a, int b)
{
    string p = "";
    for(int c = a; c <= b; c++)
	p += s[c];
    return p;
}

/*int sums(vector<vector<bool> > mat, int i, int lb)
{
    int s = 0;
    for(int a = lb; a <= i; a++)
	s += mat[a][i];
    return s;
}

int sum2(vector<vector<bool> > m1, int *m2, int i)
{
    int s = 0;
    for(int a = 1; a <= i; a++)
	s += m1[a][i] * m2[a-1];
    return s;
}*/

int sum1[2000], sum2[2000];

int main()
{    
    string s;
    int si[2000];
    int ans[2000];
    cin>>s;
    int size = s.size();
    vector<vector<bool> > pn(size);
    for(int a = 0; a < size; a++)
    {
	pn[a] = vector<bool>(size);
	for(int b = a; b < size; b++)
	{
	    string p = toString(s, a, b);
	    if(test(p))
	    {
		pn[a][b] = true;
	    }
	}
    }
    si[0] = 1;
    sum1[0] = 0;
    for(int a = 1; a < size; a++)
    {
	sum1[a] = sum1[a-1] + pn[a][a];
	si[a] = si[a-1] + sum1[a];
    }
    ans[0] = 1;
    sum2[0] = 0;
    for(int a = 1; a < size; a++)
    {
	sum2[a] = sum2[a-1] + pn[a][a] * si[a-1];
	ans[a] = ans[a-1] + sum2[a];
    }
    cout<<ans[size-1]-1<<endl;
    return 0;
}
