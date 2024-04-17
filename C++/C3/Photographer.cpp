#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int k1, k2;

class photo
{
    public:
	int a, b, id;
	long long calc;
	photo(int g, int h, int j)
	{
	    a = g;
	    b = h;
	    id = j;
	    calc = k1 * a + k2 * b;
	}
	bool operator < (const photo & anderes) const
	{
	    int p, t;
	    p = k1 * a + k2 * b;
	    t = k1 * anderes.a + k2 * anderes.b;
	    if(p < t)
		return true;
	    else
		return false;
	}
};

int main()
{
    int n, clients = 0;
    long long d, cont = 0;
    queue<int> st;
    cin>>n>>d;
    cin>>k1>>k2;
    vector<photo> zuf;
    for(int a = 0; a < n; a++)
    {
	int b, c;
	cin>>b>>c;
	photo p(b, c, a+1);
	zuf.push_back(p);
    }
    sort(zuf.begin(), zuf.end());
    for(vector<photo>::iterator it = zuf.begin(); it != zuf.end(); it++)
    {
	//cout<<(*it).a<<" "<<(*it).b<<" "<<(*it).id<<endl;
	cont += (*it).calc;
	if(cont <= d)
	{
	    st.push((*it).id);
	    clients++;
	}
	else
	    break;

    }
    cout<<clients<<endl;
    while(!st.empty())
    {
	int p = st.front();
	st.pop();
	if(st.empty())
	    cout<<p;
	else
	    cout<<p<<" ";
    }
    return 0;
}
