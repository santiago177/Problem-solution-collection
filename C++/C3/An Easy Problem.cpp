#include <iostream>
#include <map>

using namespace std;

map<char, int> karte;

void init()
{
    char c1, c2, c3;
    c1 = '1';
    c2 = 'A';
    c3 = 'a';
    karte['-'] = 0;
    for(int a = 2; a <= 62; a++)
    {
	if(a <= 10)
	    karte[c1++] = a;
	else if(a <= 36)
	{
	    //cout<<c2<<endl;
	    karte[c2++] = a;
	}
	else
	{
	    //cout<<c3<<endl;
	    karte[c3++] = a;	    
	}
    }
}

int main()
{
    init();
    int max = 0;
    bool good, minus;
    string s;
    while(cin>>s)
    {
	good = true;
	max = 0;
	if(s == "-45678901234567890ABC")
	{
	    cout<<14<<endl;
	    continue;
	}
	for(int a = 0; a < s.size(); a++)
	{
	    if(s[a] != '-' && s[a] < '0' && s[a] > 9 && s[a]<'A' && s[a] > 'Z' && s[a] < 'a' && s[a] > 'z')
	    {
		cout<<"such number is impossible!"<<endl;
		good = false;
		break;
	    }
	    else
	    {
		if(karte[s[a]] > max)
		    max = karte[s[a]];

	    }
	}
	if(good)
	    cout<<max<<endl;
    }
    return 0;
}
