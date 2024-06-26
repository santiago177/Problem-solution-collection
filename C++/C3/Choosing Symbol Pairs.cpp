#include <iostream>
#include <map>

using namespace std;

typedef long long ll;

int main()
{
    string s;
    cin>>s;
    map<char, long> counts;
    ll antwort = 0;
    for(int a = 0; a < s.size(); a++)
    {
	if(counts.count(s[a]) == 0)
	    counts[s[a]] = 1;
	else
	    counts[s[a]]++;
    }
    for(map<char, long>::iterator it = counts.begin(); it != counts.end(); it++)
	antwort += (it->second)*(it->second);
    cout<<antwort;
    return 0;
}
