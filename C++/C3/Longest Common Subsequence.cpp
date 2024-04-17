#include <iostream>
#include <vector>

using namespace std;

int max(int a, int b)
{
    if(a > b)
	return a;
    return b;
}

int main()
{
    string s, d;
    while(getline(cin, s))
    {
	getline(cin, d);
	int s1, s2;
	s1 = s.size();
	s2 = d.size();
	vector<vector<int> > tabelle(s1+1);
	for(int a = 0; a <= s1; a++)
	    tabelle[a] = vector<int>(s2+1, 0);
	for(int a = 1; a <= s1; a++)
	{
	    for(int b = 1; b <= s2; b++)
	    {
		if(s[a-1] == d[b-1])
		    tabelle[a][b] = tabelle[a-1][b-1] + 1;
		else
		    tabelle[a][b] = max(tabelle[a-1][b], tabelle[a][b-1]);
	    }
	}
	cout<<tabelle[s1][s2]<<endl;
	tabelle.clear();
    }
    return 0;
}