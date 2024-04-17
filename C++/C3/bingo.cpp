#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

int main()
{
    int n, m;
    while(cin>>n>>m && n != 0)
    {
	set<int> nums;
	vector<int> bag;
	int cont;
	bool correct = false;
	for(int a = 0; a < m; a++)
	{
	    int t;
	    cin>>t;
	    bag.push_back(t);
	    nums.insert(t);
	}
	cont = nums.size();
	if(cont == n+1)
	    correct = true;
	for(int a = 0; a < m && !correct; a++)
	{
	    for(int b = a+1; b < m && !correct; b++)
	    {
		int t = abs(bag[a]-bag[b]);
		if(nums.count(t) == 0)
		{
		    cont++;
		    nums.insert(t);
		}
		if(cont == n+1)
		    correct = true;
	    }
	}
	if(correct)
	    cout<<"Y"<<endl;
	else
	    cout<<"N"<<endl;
    }
    return 0;
}
