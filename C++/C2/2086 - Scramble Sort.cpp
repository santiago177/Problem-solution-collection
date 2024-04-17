#include <iostream>
#include <algorithm>
#include <deque>
#include <cstdio>
#include <vector>
#include <map>

using namespace std;

int todec(const string &digits)
{
    int t = 1, ret = 0, start;
    if(digits[0] == '-')
	start = 1;
    else 
	start = 0;
    for(int a = digits.size()-1; a >= start; a--)
    {
	ret += t*(digits[a]-'0');
	t *= 10;
    }
    if(digits[0] == '-')
	ret *= -1;
    return ret;
}

string lowstring(const string &s)
{
    string p = "";
    for(int a = 0; a < s.size(); a++)
	p += tolower(s[a]);
    return p;
}

string uvahp(int u)
{
    string p = "";
    deque<char> nums;
    int s = u;
    if(u < 0)
    {
	s *= -1;
	p = "-";
    }
    //cout<<"u = "<<u<<" s = "<<s<<endl;
    while(s != 0)
    {
	nums.push_front((s % 10) + '0');
	s /= 10;
    }
    for(int a= 0; a < nums.size(); a++)
	p += nums[a];
    if(u == 0)
	p = "0";
    return p;
}

int main()
{
    //freopen("2086 - Scramble Sort.in", "r", stdin);
    string s;
    while(getline(cin, s) && s != ".")
    {
	//vector<int> posregister;
	int icount = 0, scount = 0;
	vector<string> words;
	vector<string> fin;
	vector<bool> isString;
	map<string, string> prev;
	vector<string> strs;
	vector<int> ints;
	string p = "";
	//cout<<"s = "<<s<<endl;
	for(int a = 0; a < s.size(); a++)
	{
	   // cout<<"s[a] = "<<s[a]<<endl;
	    //cout<<"p = "<<p<<endl;
	    if(s[a] == '.')
	    {
		words.push_back(p);
		//cout<<"to insert p = "<<p<<endl;
		if(isdigit(p[0]) || p[0] == '-')
		    isString .push_back(false);
		else
		    isString .push_back(true);
		break;
	    }
	    else if(s.substr(a, 2) == ", ")
	    {
		words.push_back(p);
		//cout<<"to insert p = "<<p<<endl;
		if(isdigit(p[0]) || p[0] == '-')
		    isString .push_back(false);
		else
		    isString .push_back(true);
		p = "";
		a++;
	    }
	    else 
		p += s[a];
	}
	for(int a = 0; a < words.size(); a++)
	{
	    if(isString[a])
	    {
		string h = lowstring(words[a]);
		strs.push_back(h);
		prev[h] = words[a];
	    }
	    else
		ints.push_back(todec(words[a]));
	}
	//cout<<"size = "<<words.size()<<endl;
	sort(strs.begin(), strs.end());
	sort(ints.begin(), ints.end());
	/*for(int a = 0; a < ints.size(); a++)
	{
	    cout<<ints[a]<<endl;
	}
	for(int a = 0; a < isString.size(); a++)
	    cout<<isString[a]<<endl;*/
	for(int a = 0; a < words.size(); a++)
	{
	    if(a != words.size() -1)
	    {
		if(isString[a])
		    cout<<prev[strs[scount++]]<<", ";
		else
		    cout<<uvahp(ints[icount++])<<", ";
	    }
	    else
	    {
		if(isString[a])
		    cout<<prev[strs[scount++]]<<"."<<endl;
		else
		    cout<<uvahp(ints[icount++])<<"."<<endl;
	    }
	}
    }
    return 0;
}
