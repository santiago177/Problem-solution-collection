#include <iostream>

using namespace std;

int main()
{
    int n; 
    char trans[26];
    cin>>n;
    cin.ignore();
    for(int z = 0; z < n; z++)
    {
	string s, caststr;
	getline(cin, s);
	getline(cin, caststr);
	for(int a = 0; a < 26; a++)
	    trans[a] = caststr[a];
	cout<<z+1<<" ";
	for(int a = 0; a < s.size(); a++)
	{
	    if(s[a] != ' ')
		cout<<trans[s[a]-'A'];
	    else
		cout<<" ";
	}
	cout<<endl;
    }
    return 0;
}
