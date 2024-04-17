#include <iostream>
#include <utility>
#include <vector>
#include <cmath>
#include <sstream>
#include <queue>

using namespace std;

typedef vector<pair<int, double> > vecpid;
typedef pair<int, double> pid;
typedef pair<int, int> pii;

const double PI = 2*acos(0);

class AirTravel
{
	
    public:
    
	double distance(double lat1, double lon1, double lat2, double lon2)
    {
	//radius * acos(sin(lat1) * sin(lat2) + cos(lat1) * cos(lat2) * cos(lon1 - lon2))
	lat1 = lat1/180*PI;
	lat2 = lat2/180*PI;
	lon1 = lon1/180*PI;
	lon2 = lon2/180*PI;
	double ans = 4000 * acos(sin(lat1) * sin(lat2) + cos(lat1) * cos(lat2) * cos(lon1 - lon2));
	return ans;
    }

    double shortestTrip(vector <int> latitude, vector <int> longitude, vector <string> edges, int origin, int destination) 
    {
	vecpid graph[20];
	double weight[20];
	bool visited[20] = {0};
	for(int a = 0; a < edges.size(); a++)
	{
	    vector<int> zahl;
	    stringstream st(edges[a]);
	    int t;
	    while(st >> t)
		zahl.push_back(t);
	    pii start = make_pair(latitude[a], longitude[a]);
	    for(int b = 0; b < zahl.size(); b++)
	    {
		pii dest = make_pair(latitude[zahl[b]], longitude[zahl[b]]);
		double dist = distance(start.first, start.second, dest.first, dest.second);
		pid i = make_pair(zahl[b], dist);
		graph[a].push_back(i);
	    }
	    weight[a] = 1<<30;
	}
	priority_queue<pid> min;
	int current = origin;
	double dist;
	weight[origin] = 0;
	//Dijkstra
	while(1)
	{
	    visited[current] = true;
	    if(current == destination) break;
	    for(int a = 0; a < graph[current].size(); a++)
	    {
		pid p = graph[current][a];
		dist = weight[current] + p.second;
		if(!visited[p.first] && dist < weight[p.first])
		{
		    min.push(make_pair(-dist, p.first));
		    weight[p.first] = dist;
		}
	    }
	    if(min.empty())
		break;
	    current = min.top().second;
	    min.pop();
	}
	if(visited[destination])
	    return weight[destination];
	else
	    return -1;
    }
};