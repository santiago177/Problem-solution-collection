#include <iostream>

using namespace std;

void append(string &ns, int c, int par)
{
    string temp = "";
    if(par == 1)
    {
	if(c > 2)
	{
	    while(1)
	    {
		temp += '#';
		if(c > 255)
		    c -= 255;
		else
		    break;
	    }
	    temp += (char)(c);
	}
	else
	{
	    if(c == 1)
		ns += '0';
	    else
		ns += "00";
	}
	ns += temp;
	return;
    }
    else
    {
	if(c > 2)
	{
	    while(1)
	    {
		temp += '$';
		if(c > 255)
		    c -= 255;
		else
		    break;		
	    }
	    temp += (char)(c);
	}
	else
	{
	    if(c == 1)
		ns += ' ';
	    else
		ns += "  ";
	}
	ns += temp;
	return;
    }
}

int main()
{
    int n;
    string s;
    cin>>n;
    cin.ignore();
    for(int z = 0; z < n; z++)
    {
	getline(cin, s);
	string ns = "";
	int zco, sco;
	bool zo, so;
	zo = so = false ;
	zco = 0; sco = 0;
	for(int a = 0; a < s.size(); a++)
	{
	    if(s[a] == '0')
	    {
		if(so)
		{
		    so = false;
		    append(ns, sco, 2);
		    sco = 0;
		}
		if(!zo)
		    zo = true;
		zco++;
	    }
	    else if(s[a] == ' ')
	    {
		if(zo)
		{
		    zo = false;
		    append(ns, zco, 1);
		    zco = 0;
		}
		if(!so)
		    so = true;
		sco++;
	    }
	    else
	    {
		string temp = "";
		if(zo)
		{
		    zo = false;
		    append(ns, zco, 1);
		    zco = 0;
		}
		else if(so)
		{
		    so = false;
		    append(ns, sco, 2);
		    sco = 0;
		}
		ns += s[a];
	    }
	}
	if(zo)
	    append(ns, zco, 1);
	if(so)
	    append(ns, sco, 2);
	cout<<ns<<endl;
    }
    return 0;
}
