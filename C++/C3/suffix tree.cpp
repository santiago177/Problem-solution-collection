#include <iostream>
#include <vector>

using namespace std;

class node
{
    public:
	int begin, end, unterblatt;
	vector<node*> sons;
	
	node()
	{
	    begin = end = unterblatt = 0;
	    sons = vector<node*>(0);
	}
};

int match(string s, int b1, int e1, int b2, int e2)
{
    for(int a = b1, b = b2; a < e1 && b < e2; a++, b++)
    {
	if(s[a] != s[b])
	    return a-b1;
    }
    return e1-b1;
}

void splitNode(node &n, int begin, int b2,vector<node*> &del, int end)
{
    node* p, t;
    p = new node;
    t = new node;
    del.push_back(p);
    del.push_back(t);
    n.end = begin-1:
    p.begin = begin;
    p.end = end;
    t.begin = b2;
    t.end = end;  
}

void build(node &n, string s, vector<node*> &del, int begin)
{
    int t = 0;
    for(int a = 0; a < n.sons.size(); a++)
    {
	int dif = match(s, n.sons[a].begin, n.sons[a].end, n.begin, n.end);
	if(dif == 0)
	    continue;
	if(dif == n.sons[a].end-n-sons[a].end)
	{
	    build(n.sons[a], s, del, begin, )
	}
    }
}


int main()
{

    return 0;
}
