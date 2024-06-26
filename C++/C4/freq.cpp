#include <iostream>
#include <map>
#include <cstdio>

using namespace std;

int main()
{
    freopen("freq.in", "r", stdin);
    int n;
    cin>>n;
    cin.ignore();
    for(int a = 0; a < n; a++)
    {
	int count = 0;
	string s;
	getline(cin, s);
	map<char, int> wo;
	for(char b = 'a'; b <= 'z'; b++)
	    wo[b] = 0;
	for(int b = 0; b < s.size(); b++)
	{
	    if(isupper(s[b]) || islower(s[b]))
	    {
		s[b] = tolower(s[b]);
		wo[s[b]]++;
		if(wo[s[b]] > count)
		    count = wo[s[b]];
	    }
	}
	//cout<<count<<endl;
	for(char b = 'a'; b <= 'z'; b++)
	{
	    //cout<<b<<" "<<wo[b]<<endl;
	    if(wo[b] == count)
		cout<<b;
	}
	cout<<endl;
    }
    return 0;
}
