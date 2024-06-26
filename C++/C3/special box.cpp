#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class dim
{
    public:
	vector<int> d;
	int vol;
	bool operator < (const dim &o) const
	{
	    if(vol < o.vol)
		return true;
	    return false;
	}
	dim(int a, int b, int c)
	{
	    d.push_back(a);
	    d.push_back(b);
	    d.push_back(c);
	    vol = a*b*c;
	}
};

int main()
{
    int n, m;
    while(cin>>n>>m && n != 0)
    {
	int a, b, c, max;
	bool possible = false;
	cin>>a>>b>>c;
	dim haupt(a, b, c);
	sort(haupt.d.begin(), haupt.d.end());
	vector<dim> boxes;
	map<dim, int> ret;
	for(int x = 0; x < m; x++)
	{
	    cin>>a>>b>>c;
	    boxes.push_back(dim(a, b, c));
	    sort(boxes[x].d.begin(), boxes[x].d.end());
	    if(ret.count(boxes[x]) == 0)
		ret[boxes[x]] = 1;
	    else
		ret[boxes[x]]++;
	}
	sort(boxes.begin(), boxes.end());
	for(int x = 0; x < m;)
	{
	    if(haupt.d[0] <= boxes[x].d[0] && haupt.d[1] <= boxes[x].d[1] && haupt.d[2] <= boxes[x].d[2])
	    {
		cout<<"ret "<<ret[boxes[x]]<<endl;
		if(ret[boxes[x]] >= n)
		{
		    max = boxes[x].vol - haupt.vol;
		    possible = true;
		    break;
		}
	    }
	    x += ret[boxes[x]];
	}
	possible? cout<<max<<endl : cout<<"impossible"<<endl;
    }
    return 0;
}
