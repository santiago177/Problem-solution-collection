#include <iostream>
#include <cstdio>
#include <utility>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, vector<int> > pivi;

int matrix[5][5];

int main()
{
    //freopen("taxi.in", "r", stdin);
    for(int a = 0; a < 5; a++)
    {
	for(int b = 0; b < 5; b++)
	    cin>>matrix[a][b];
    }
    int dist = 0;
    vector<vector<int> > order;
    vector<int> distances;
    priority_queue<pivi> pq;
    int p1, p2, p3;
    vector<int> q;
    for(int a = 1; a < 4; a++)
    {
	p1 = a;
	for(int b = 1; b < 4; b++)
	{
	    if(p1 == b)
		continue;
	    p2 = b;
	    for(int c = 1; c < 4; c++)
	    {
		if(p2 == c || p1 == c)
		    continue;
		p3 = c;
		dist = matrix[0][p1] + matrix[p1][p2] + matrix[p2][p3] + matrix[p3][4];
		q.push_back(0);
		q.push_back(p1);
		q.push_back(p2);
		q.push_back(p3);
		q.push_back(4);
		//order.push_back(q);
		//distances.push_back(dist);
		pq.push(make_pair(-dist, q));
		q.clear();
	    }
	}
    }
    /*while(!pq.empty())
    {
	pivi p = pq.top();
	pq.pop();
	cout<<p.first<<endl;
	for(int a = 0 ; a < p.second.size(); a++)
	    cout<<p.second[a]+1<<" ";
    }*/

    while(!pq.empty())
    {
	pivi p = pq.top();
	pq.pop();
	if(p.second[3] == 2)
	    continue;
	cout<<-p.first<<endl;
	for(int a = 0 ; a < 4; a++)
	    cout<<p.second[a]+1<<" ";
	cout<<p.second[4]+1;
	break;
    }
    return 0;
}
