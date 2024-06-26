#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<vector<int> >laptops;
    vector<bool> outdate(false, n);
    vector<pair<vector<int>, int> >last;
    for(int a = 0; a < n; a++)
    {
	vector<int> unit(4);
	int speed, ram, hdd, cost;
	cin>>speed>>ram>>hdd>>cost;
	unit[0] = speed;
	unit[1] = ram;
	unit[2] = hdd;
	unit[3] = cost;
	laptops.push_back(unit);
    }
    for(int a = 0; a < n; a++)
    {
	bool possible = true;
	for(int b = 0; b < n; b++)
	{
	    if(laptops[a][0] < laptops[b][0] && laptops[a][1] < laptops[b][1] && laptops[a][2] < laptops[b][2])
	    {
		possible = false;
		break;
	    }
	}
	if(possible)
	    last.push_back(make_pair(laptops[a], a+1));
    }
    int cheap = 1001, index;
    for(int a = 0; a < last.size(); a++)
    {
	if(last[a].first[3] < cheap)
	{
	   // cout<<"cheap = "<<last[a].first[0]<<" "<<last[a].first[1]<<" "<<last[a].first[2]<<" "<<last[a].first[3]<<endl;
	    cheap = last[a].first[3];
	    index = last[a].second;
	}
    }
    cout<<index;
    return 0;
}
