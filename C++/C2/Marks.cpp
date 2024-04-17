#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m, total = 0;
    int best[100] = {0};
    vector<string> notes;
    cin>>n>>m;
    for(int a = 0; a < n; a++)
    {
	string s;
	cin>>s;
	notes.push_back(s);
    }
    for(int a = 0; a < m; a++)
    {
	int max = 0;
	for(int b = 0; b < n; b++)
	{
	    if(notes[b][a]-'0' > max)
		max = notes[b][a]-'0';
	}
	for(int b = 0; b < n; b++)
	    if(notes[b][a]-'0' == max)
		best[b]++;
    }
    for(int a = 0; a < n; a++)
	if(best[a] > 0)
	    total++;
    cout<<total;
    return 0;
}
