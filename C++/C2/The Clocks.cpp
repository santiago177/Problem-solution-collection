#include <iostream>
#include <queue>
#include <stack>
#include <set>
#include <vector>
#include <map>

using namespace std;

void start_moves(string *moves)
{
    moves[0] = "ABDE";
    moves[1] = "ABC";
    moves[2] = "BCEF";
    moves[3] = "ADG";
    moves[4] = "BDEFH";
    moves[5] = "CFI";
    moves[6] = "DEGH";
    moves[7] = "GHI";
    moves[8] = "EFHI";
}

vector<int> cast(vector<int> s, string move)
{
    for(int a = 0; a < move.size(); a++)
    {
	int ind = move[a] -'A';
	s[ind] = (s[ind] + 1) % 4;
    }
    return s;
}

bool fill_target(vector<int> &clocks)
{
    for(int a = 0; a < clocks.size(); a++)
	clocks[a] = 0;
}

int main()
{
    bool found = false;
    string moves[9];
    vector<int> target(9);
    set<vector<int> > states;
    map<vector<int>, pair<vector<int>, int> > path;
    vector<int> clocks(9);
    for(int a = 0; a < 9; a++)
    {
	int t;
	cin>>t;
	clocks[a] = t;
    }
    start_moves(moves);
    fill_target(target);
    queue<vector<int> > q;
    q.push(clocks);
    states.insert(clocks);
    vector<int> current;
    while(!q.empty() && !found)
    {
	//cout<<found<<endl;
	vector<int> p = q.front();
	if(p == target)
	{
	    current = p;
	    break;
	}
	for(int a = 0; a < p.size(); a++)
	    cout<<p[a];
	cout<<endl;
	q.pop();
	for(int a = 0; a < 9; a++)
	{
	    vector<int> t = cast(p, moves[a]);
	    if(states.find(t) == states.end())
	    {
		if(t == target)
		{
		    states.insert(t);
		    path[t] = make_pair(p, a+1);
		    //cout<<"in"<<endl;
		    found = true;
		    current = t;
		    break;
		}
		q.push(t);
		states.insert(t);
		path[t] = make_pair(p, a+1);
	    }
	}
	if(found)
	    break;
    }
    //cout<<"out"<<endl;
    stack<int> fin;
    while(1)
    {
	if(current == clocks)
	    break;
	fin.push(path[current].second);
	current = path[current].first;
    }
    bool first = false;
    while(!fin.empty())
    {
	if(first)
	cout<<" "<<fin.top();
	else
	{
	    cout<<fin.top();
	    first = true;
	}
	fin.pop();

    }
    return 0;
}
