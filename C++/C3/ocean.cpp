#include <iostream>
#include <cmath>
#include <set>

using namespace std;

long long todec(string s)
{
    int c;
    for(int a = 0; a < s.size(); a++)
    {
	if(s[a] == '#')
	{
	    c = a;
	    break;
	}
    }
    int pw = c - 1;
    long long ant = 0;
    for(int a = 0; a < c; a++)
	ant += pow(2, pw--)*(s[a]-'0');
    return ant;
}

int main()
{
    string s;
    while(cin>>s)
    {
	string t;
	t = s;
	while(t[t.size()-1] != '#')
	{
	    cin>>t;
	    s += t;
	}
	long long zahl = todec(s);
	if(zahl % 131071 == 0)
	    cout<<"YES"<<endl;
	else
	    cout<<"NO"<<endl;
    }
    return 0;
}