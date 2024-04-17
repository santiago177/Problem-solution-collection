#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<long, int> pii;

vector<vector<int> > memo;
vector<void *> dynamic;

int N;

/*int fun(int n, int stock, vector<int> &prices)
{
    int l, m, r;
    if(stock < 500 && memo[n][stock] != -1)
        return memo[n][stock];
    if(n==prices.size()-1)
    {
        m = 0;
        r = stock*prices[n];
        //cout<<"case "<<n<<" "<<max(m, r)<<" stock "<<stock<<endl; 
        int t = max(m, r);
        if(stock < 500)
            memo[n][stock] = t;
        return t;
    }
    l = fun(n+1, stock+1, prices) - prices[n];
    m = fun(n+1, stock, prices);
    r = fun(n+1, 0, prices) + prices[n] * stock;
    //cout<<"case "<<n<<" l "<<l<<" m "<<m<<" r "<<r<<" stock "<<stock<<endl;
    int t = max(l, max(m, r));
    if(stock < 500)
        memo[n][stock] = t;
    return t;
}*/

class node
{
    public:
	node *left, *right;
	long long num, low, high;
	int pos;
	node(vector<int> &array, int low, int high)
	{
	    this->low = low; this->high = high;
	    if(low == high)
	    {
		num = array[low];
		pos = low;
		left = NULL;
		right = NULL;
	    }
	    else
	    {
		//cout<<"low "<<low<<" (low + high)/2 "<< (low + high)/2<<" (low + high)/2 + 1 "<<(low + high)/2 + 1<<" high "<<high<<endl;
		node *n1 = new node(array, low, (low + high)/2);  
		node *n2 = new node(array, (low + high)/2 + 1, high);
		dynamic.push_back(n1);
		dynamic.push_back(n2);
		left = n1;
		right = n2;
		long long snum, spos;
		if(n1->num > n2->num)
		{
		    snum=n1->num;
		    spos=n1->pos;
		}
		else
		{
		    snum=n2->num;
		    spos=n2->pos;
		}
		num = snum;
		pos = spos;
	    }
	}
};

pii get(node *n, int low, int high) // funciona
{
    if(n -> low == low && n-> high == high)
	return make_pair(n->num, n->pos);
    else
    {
	if(high <= n -> left -> high)
	    return get(n -> left, low, high);
	if(low >= n -> right -> low)
	    return get(n -> right, low, high);

	pii s1 = get(n -> left, low, n -> left -> high);
	pii s2 = get(n -> right, n -> right -> low, high);
	if(s1.first > s2.first)
	    return s1;
	else
	    return s2;
    }
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T;
    cin>>T;
    for(int z=0; z < T; z++)
    {
	dynamic.clear();
        cin>>N;
        vector<int> prices(N);
        for(int a=0; a<N; a++)
            cin>>prices[a];
        
	node tree(prices, 0, N-1);
	
	int p_pos=0, n_pos;
        long long resta=0, total=0, count=0;
	pii init = get(&tree, 0, N-1);
	n_pos = init.second;
	while(1)
	{
	    count = 0;
	    resta = 0;
	    for(int i=p_pos; i<n_pos;i++)
	    {
		resta-=prices[i];
		count++;
	    }
	    long long temp = count*prices[n_pos];
	    total += (resta+temp);
	    p_pos = n_pos+1;
	    if(n_pos == N-1)
		break;
	    n_pos = get(&tree, n_pos+1, N-1).second;
	}
	
	cout<<total<<endl;

	for(int a = 0; a < dynamic.size(); a++)
	    delete (node*)dynamic[a];
    }
    return 0;
}

