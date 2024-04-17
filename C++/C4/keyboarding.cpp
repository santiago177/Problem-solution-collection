#include <iostream>
#include <cstdio>
#include <queue>
#include <utility>
#include <deque>
#include <cmath>
#include <vector>

using namespace std;

pair<int, int> offset[4];

void fill()
{
    offset[0] = (1, 0);
    offset[1] = (0, 1);
    offset[2] = (-1, 0);
    offset[3] = (0, -1);
}

void update(vector<vector<bool> > &visited)
{
    for(int a = 0; a < visited.size(); a++)
    {
	for(int b = 0; b < visited[a].size(); b++)
	    visited[a][b] = false;
    }
}

int main()
{
    freopen("keyboarding.in", "r", stdin);
    fill();
    int r, c;
    cin>>r>>c;
    deque<string> keyboard;
    vector<vector<bool> > visited;
    string word;
    for(int a = 0; a < r; a++)
    {
	string in;
	cin>>in;
	keyboard.push_back(in);
    }
    string top = "";
    cin>>word;
    for(int a = 0; a < r; a++)
    {
	keyboard[a] = '!' + keyboard[a] + '!';
	visited.push_back(vector<bool> (keyboard[0].size(), false));
    }
    for(int a = 0; a < c+2; a++)
	top += '!';
    keyboard.push_front(top);
    keyboard.push_back(top);
    visited.push_back(vector<bool> (keyboard[0].size(), false));
    visited.push_back(vector<bool> (keyboard[0].size(), false));
    for(int a = 0; a < visited.size(); a++)
    {
	//cout<<keyboard[a]<<endl;
	for(int b = 0; b < visited[a].size(); b++)
	{
	    if(visited[a][b])
		cout<<'T';
	    else
		cout<<'F';
	}
	cout<<endl;
    }
    int cx, cy;
    int totalc = 0;
    cx = cy = 0;
    for(int h = 0; h < word.size(); h++)
    {
	int cc = 0;
	queue<pair<int, int> > q;
	visited[cx][cy] = true;
	q.push_back(make_pair(cx, cy));
	if()
	{
	}
	while(q.empty())
	{
	    pair<int, int> p = q.front();
	    q.pop();
	    for(int a = 0; a < 4; a++)
	    {
		pair<int, int> t = p;
		t.first += offset[a].first;
		t.second += offset[b].second;
		if();
	    }
	}
	update(visited);
    }
    return 0;
}














