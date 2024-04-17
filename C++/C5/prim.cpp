#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>

class Node;
class Compare;

using namespace std;

typedef pair<Node*, int*> pni;



class Node {
    public:
	vector<pni> list;
	Node* parent;
	set<int> adj;
	int key, id;
	Node(int size) {
	    key = 0;
	    id = 0;
	}
};

class Compare {
    public:
	bool operator()(Node* n1, Node* n2) {
	    if(n1->key == n2->key)
		return n1->id < n2->id;
	    return n1->key < n2->key;
	}
};

int main() {
    int N, M, sum = 0;
    cin>>N>>M;
    vector<Node*> graph(N+1);
    for(int a = 0; a <= N; a++) {
	Node* n = new Node(N+1);
	graph[a] = n;
    }
    for(int z = 0; z < M; z++) {
	int a, b, c;
	cin>>a>>b>>c;
	if(graph[a]->adj.find(b) != graph[a]->adj.end()) {
	    for(int i = 0; i < graph[a]->list.size(); i++) {
		Node* v = graph[a]->list[i].first;
		if(v->id == b) {
		    if(c < *(graph[a]->list[i].second)) {
			*(graph[a]->list[i].second) = c;
		    }
		    break;
		}
	    }
	    continue;
	}
	int *k = new int;
	*k = c;
	graph[a]->list.push_back(make_pair(graph[b], k));
	graph[a]->adj.insert(b);
	graph[a]->id = a;
	graph[b]->list.push_back(make_pair(graph[a], k));
	graph[b]->adj.insert(a);
	graph[b]->id = b;
    }
    int S;
    cin>>S;
    set<Node*, Compare> pq;
    for(int i = 1; i <= N; i++) {
	if(i != S)
	   graph[i]->key = 1<<30;
	graph[i]->parent = NULL;
	pq.insert(graph[i]);
    }
    while(!pq.empty()) {
	Node* u = *pq.begin();
	pq.erase(pq.begin());
	//cout<<"current "<<u->id<<endl;
	for(int i = 0; i < u->list.size(); i++) {
	    Node * v = u->list[i].first;
	    //cout<<"visiting "<<u->list[i].first->id<<" dist "<<u->list[i].second<<" key "<<u->list[i].first->key<<endl;
	    if(pq.find(v) != pq.end() && *(u->list[i].second) < u->list[i].first->key) {
		v->key = *(u->list[i].second);
		for(set<Node*, Compare>::iterator it = pq.begin(); it != pq.end(); it++) {
		    if((*(it))->id == v->id){
			pq.erase(it);
			break;
		    }
		}
		pq.insert(v);
		v->parent = u;
		//cout<<"added "<<u->list[i].second<<endl;
	    }
	}
    }
    for(int i = 1; i <= N; i++) {
	if(graph[i]->parent != NULL)
	{
	    for(int j = 0; j < graph[i]->list.size(); j++) {
		if(graph[i]->parent->id == graph[i]->list[j].first->id)
		    sum += *(graph[i]->list[j].second);
	    }
	}
    }
    cout<<sum<<endl;
    
    return 0;
}
