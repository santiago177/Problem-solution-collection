#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <set>

using namespace std;

typedef long long ll;



int main() {
    int N, R;
    while(cin>>N>>R) {
	bool ans = true;
	vector<int> intersection(N, 0);
	vector<vector<int> > graph(N);
	for(int i = 0; i < R; i++) {	    
	    int a, b;
	    cin>>a>>b;
	    intersection[a]++;
	    graph[a].push_back(b);
	    intersection[b]++;		
	    graph[b].push_back(a);	    
	}
	vector<bool> visited(N, false);
	visited[0] = true;
	queue<int> q;
	set<int> nodes;
	int start = 0;
	for(int i = 0; i < N; i++) {
	    if(intersection[i] != 0) {
		start = i;
		break;
	    }
	}
	q.push(start);
	while(!q.empty()) {
	    int p = q.front();
	    q.pop();
	    nodes.insert(p);
	    for(int i = 0; i < graph[p].size(); i++) {
		int t = graph[p][i];
		if(!visited[t]) {
		    visited[t] = true;
		    q.push(t);
		}
	    }
	}

	for(int i = 0; i < N && ans; i++) {
	    if(intersection[i] != 0 && nodes.count(i) == 0)
		ans = false;
	    if(intersection[i] % 2 == 1 || R == 0) {
		ans = false;
		break;
	    }
	}
	if(ans)
	    cout<<"Possible"<<endl;
	else
	    cout<<"Not Possible"<<endl;
    }

    return 0;
}
