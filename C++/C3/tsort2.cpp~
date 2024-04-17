#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;


vector<int> mergesort(int begin, int end, vector<int> liste)
{
    //cout<<"begin "<<begin<<" end "<<end<<endl;
    if(begin == end)
    {
	vector<int> j;
	j.push_back(liste[begin]);
	return j;
    }
    else
    {
	vector<int> n, m;
	n = mergesort(begin, (int)((begin+end)/2), liste);
	m = mergesort((int)((begin+end)/2)+1, end, liste);
	vector<int> p;
	int a = 0, b = 0;
	while(1)
	{
	    if(a == n.size())
	    {
		for(int c = b; c < m.size(); c++)
		    p.push_back(m[c]);
		break;
	    }
	    else if(b == m.size())
	    {
		for(int c = a; c < n.size(); c++)
		    p.push_back(n[c]);
		break;
	    }
	    else
	    {
		if(n[a] < m[b])
		    p.push_back(n[a++]);
		else
		    p.push_back(m[b++]);
	    }
	}
	return p;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> x(n);
    for(int a = 0; a < n; a++)
	scanf("%d", &x[a]);
    vector<int> p = mergesort(0, n-1, x);
    for(int a = 0; a < p.size(); a++)
	printf("%d\n", p[a]);
    return 0;
}

