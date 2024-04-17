#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class task
{
    public:
    int n, name;
    task(int j)
    {
	name = j;
	n = 0;
    }
    bool operator < (const task p)const
    {
	if(n > p.n)
	    return true;
	if(n == p.n)
	    if(name > p.name)
		return true;
	return false;
    }
};

int main()
{
    int n, m;
    while(cin>>n>>m && n != 0 && m != 0)
    {
	vector<task> list;
	for(int a = 0; a < n; a++)
	    list.push_back(task(a+1));
	for(int a = 0; a < m; a++)
	{
	    int x, y;
	    cin>>x>>y;
	    list[x-1].n++;
	    list[y-1].n--;
	}
	sort(list.begin(), list.end());
	for(int a = 0; a < n; a++)
	{
	    //cout<<"la = "<<list[a].name<<" "<<list[a].n<<endl;
	    if(a != n-1)
		cout<<list[a].name<<" ";
	    else
		cout<<list[a].name<<endl;
	}
    }    
    return 0;
}
