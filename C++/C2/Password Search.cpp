#include <iostream>
#include <map>

using namespace std;

int main()
{
    int n;
    string s;
    while(cin>>n>>s)
    {
	map<string, int> strs;
	for(int a = 0; a+n < s.size(); a++)
	{
	    string p;
	    for(int b = 0; b < n; b++)
		p += s[a+b];
	    if(strs.find(p) == strs.end())
		strs[p] = 1;
	    else
		strs[p]++;
	}
	int max = 0;
	string ans;
	for(map<string, int>::iterator it = strs.begin(); it != strs.end(); it++)
	{
	    if(it->second > max)
	    {
		max = it->second;
		ans = it->first;
	    }
	}
	
	cout<<ans<<endl;
    }
}
