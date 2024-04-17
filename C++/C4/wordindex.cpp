#include <iostream>
#include <cstdio>
#include <set>
#include <map>
#include <queue>

using namespace std;

map<string, int> word_list_indexed;
vector<string> word_list;


void fill()
{
    queue<string> q;
    for(char a = 'a'; a <= 'z'; a++)
    {
	string t = "";
	t += a;
	//cout<<'"'<<t<<"\", ";
	q.push(t);
	word_list.push_back(t);
    }
    while(!q.empty())
    {
	string t = q.front();
	string copy;
	//cout<<copy<<endl;
	q.pop();
	for(char a = t[t.size()-1]+1; a <= 'z'; a++)
	{
	    copy = t;
	    copy += a;
	    if(copy.size() <= 5)
	    {
		//cout<<copy<<endl;
		q.push(copy);
		word_list.push_back(copy);
	    }
	}
    }
}

void fill2()
{
    for(int a = 0; a < word_list.size(); a++)
	word_list_indexed[word_list[a]] = a+1;
}

int main()
{
    //freopen("wordindex.t", "w", stdout);
    fill();
    fill2();
    string input;
    while(cin>>input)
    {
	if(word_list_indexed.count(input) == 0)
	    cout<<0<<endl;
	else
	    cout<<word_list_indexed[input]<<endl;
    }
    return 0;
}






















