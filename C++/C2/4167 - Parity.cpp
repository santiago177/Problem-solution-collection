#include <iostream>

using namespace std;

int main()
{
    string s;
    while(cin>>s && s != "#")
    {
	int c = 0, ikn = s.size()-1;
	for(int a = 0; a < ikn; a++)
	    if(s[a] == '1')
		c++;
	if(s[ikn] == 'e')
	{
	    if(c % 2 == 0)
		s[ikn] = '0';
	    else
		s[ikn] = '1';
	}
	else
	{
	    if(c % 2 == 0)
		s[ikn] = '1';
	    else
		s[ikn] = '0';
	}
	cout<<s<<endl;
    }
}

