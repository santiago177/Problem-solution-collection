#include <iostream>
#include <queue>
#include <set>

using namespace std;

int main()
{
    string a, b, w, target;
    while(cin>>a>>b>>w>>target)
    {
	//cout<<a<<" "<<b<<" "<<w<<" "<<target<<endl;
	int max = target.size();
	bool answer = false;
	set<string> track;
	queue<string> q;
	q.push(w);
	if(w == target || a == target || b == target)
	    answer = true;
	while(!q.empty() && !answer)
	{
	    string current = q.front(), copy = current;
	    q.pop();
	    for(int g = 0; g < current.size(); g++)
	    {
		if(current[g] == 'a')
		    copy.replace(g, 1, a);
		else
		    copy.replace(g, 1, b);
		//cout<<copy<<endl;
		if(copy == target)
		{
		    answer = true;
		    break;
		}
		if(copy.size() < max && track.count(copy) == 0)
		{
		    q.push(copy);
		    track.insert(copy);
		}
		copy = current;
	    }
	    if(answer)
	    break;
	}
	if(answer)
	    cout<<"YES"<<endl;
	else
	    cout<<"NO"<<endl;
    }
}
