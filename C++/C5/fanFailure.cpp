#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int fans[50], memo[50][50000];
int minim, minc;

int M(int a, int s)
{
    if(memo[a][s] != -1)
	return memo[a][s];
    if(a == 0)
    {
	if(s - fans[a] >= minim)
	    return 1;
	else
	    return 0;
    }
    /*else if(s - fans[a] < minim)
    {
	int ans = M(a-1, s);
	memo[a][s] = ans;
	return ans;
	return M(a-1, s);
    }*/
    if(s - fans[a] < minim)
	return 0;
    else
    {
	int max = 0;
	int minc = 1<<30;
	for(int b = a-1; b >= 0; b--)
	{
	    int temp = 1 + M(b, s - fans[a]);
	    if(temp > max)
		max = temp;
	}
	memo[a][s] = max;
	return max;
	/*int ans = 1 + M(a - 1, s - fans[a]);
	memo[a][s] = ans;
	return ans;*/
	//return 1 + M(a - 1, s - fans[a]);
    }
}

int main()
{
    memset(memo, -1, sizeof(int)*50*50000);
    int n, size, sum = 0;
    priority_queue<int> pq;
    cin>>size;
    for(int a = 0; a < size; a++)
    {
	cin>>fans[a];
	pq.push(fans[a]);
	sum += fans[a];
    }
    int count = size;
    cin>>n;
    minim = n;
    int cpy = sum;
    while(!pq.empty() && cpy - pq.top() >= minim)
    {
	count--;
	cpy -= pq.top();
	cout<<"top "<<pq.top()<<" "<<count<<endl;
	pq.pop();
    }
    cout<<M(size - 1, sum)<<endl;
    cout<<size - count<<endl;
    return 0;
}
