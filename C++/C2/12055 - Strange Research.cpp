#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>

using namespace std;

struct fuckthis
{
    char array[40];
    fuckthis()
    {
	for(int a = 0; a < 40; a++)
	    array[a] = 0;
    }
};

int todec(const vector<int> &digits)
{
    int t = 1, ret = 0;
    for(int a = digits.size()-1; a >= 0; a--)
    {
	ret += t*digits[a];
	t *= 10;
    }
    return ret;
}

int main()
{
    //freopen("12055 - Strange Research.in", "r", stdin);
    int n, q, last;
    char max;
    vector<int> digits;
    vector<string> strs;
    string s, p = "";
    cin>>n;
    vector<string> dictionary;
    map<string, fuckthis > diccount;
    map<string, fuckthis > qcount;
    map<string, set<string> > perm;
    map<string, int> dhighest;
    map<string, int> qhighest;
    for(int a = 0; a < n; a++)
    {
	//cout<<"check"<<endl;
	max = 0;
	cin>>s;
	dictionary.push_back(s);
	//cout<<s<<endl;
	//diccount[s] = vector<char>(50, 0);
	for(int b = 1; b < s.size()-1; b++)
	{
	    //cout<<"in"<<endl;
	    if(s[b]-'a' > max)
		max = s[b]-'a';
	    diccount[s].array[s[b]-'a']++;
	}
	dhighest[s] = max;
    }
    //cout<<"check"<<endl;
    cin>>s;
    for(int a = 0; a < s.size(); a++)
    {
	if(isdigit(s[a]))
	{
	    digits.push_back(s[a]-'0');
	    last = a+1;
	}
	else 
	    break;
    }
    //cout<<"last = "<<last<<endl;
    for(int a = last; a < s.size(); a++)
	p += s[a];
    strs.push_back(p);
    q = todec(digits);
    p = "";
    for(int a = 1; a < q; a++)
    {
	cin>>s;
	strs.push_back(s);
    }
    for(int a = 0; a < strs.size(); a++)
    {
	//cout<<"str = "<<strs[a]<<endl;
	max = 0;
	for(int b = 1; b < s.size()-1; b++)
	{
	    if(strs[a][b]-'a' > max)
		max = strs[a][b]-'a';
	    qcount[strs[a]].array[strs[a][b]-'a']++;
	}
	qhighest[strs[a]] = max;
    }
    int matches = 0;
    //cout<<"size = "<<strs.size()<<endl;
    for(int a = 0; a < strs.size(); a++)
    {
	//cout<<"out a = "<<a<<endl;
	matches = 0;
	//cout<<"current = "<<strs[a]<<endl;
	set<string> strmatch;
	for(int b = 0; b < dictionary.size(); b++)
	{
	    bool m = true;
	    if(qhighest[strs[a]] == dhighest[dictionary[b]] && strs[a][0] == dictionary[b][0] && strs[a][strs[a].size()-1] == dictionary[b][dictionary[b].size()-1] && strs[a].size() == dictionary[b].size())
	    {
		for(int c = 0; c <= qhighest[strs[a]] && m; c++)
		{
		    if(qcount[strs[a]].array[c] != diccount[dictionary[b]].array[c])
			m = false;
		}
		if(m)
		{
		    strmatch.insert(dictionary[b]);
		    matches++;
		}
	    }
	}
/*	1 aaaaa aaaaa
2 aaabb aabab
0
0*/
	if(matches > 0)
	    cout<<matches<<" "<<*strmatch.begin()<<" "<<*strmatch.rbegin()<<endl;
	else
	    cout<<0<<endl;
    }
    return 0;
}



