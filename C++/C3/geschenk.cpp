#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int main()
{
    int n, m;
    while(cin>>n>>m && n != 0)
    {
	int top, bot, target = m-1;
	bool possible = false;
	bot = 0;
	top = n-1;
	queue<pair<int, int> >q;
	q.push(make_pair(0, 1));
	if(n >= 100)
	    possible = true;
	while(!q.empty() && !possible)
	{
	    int a, b, var;
	    pair<int, int> p = q.front();
	    q.pop();
	    //cout<<"current "<<p.first<<endl;
	    var = p.second + 1;
	    a = p.first + var;
	    b = p.first - var;
	    if(a == target || b == target)
	    {
		possible = true;
		break;
	    }
	    if(a <= top)
		q.push(make_pair(a, var));
	    if(b >= 0)
		q.push(make_pair(b, var));
	}
	possible? cout<<"Let me try!"<<endl : cout<<"Don't make fun of me!"<<endl;
    }
    return 0;
}