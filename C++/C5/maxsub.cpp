#include <iostream>
#include <cstdio>
#include <deque>
#include <utility>
#include <cstring>

using namespace std;
typedef pair<int, int> pii;


int maxm, maxs;
const int MIN = -1<<30;

pii memo[10001][10001];

pii solve(deque<int> &list, int index, int rem)//first = product second = sum
{
    if(index == list.size() || rem == 0)
    {
	pii k =  make_pair(1, 0);
	memo[index][rem] = k;
	return k;
    }
    int max = -1<<30, sum = 0;
    pii ans;
    for(int i=index+1; i<list.size()+1; i++)
    {
	if(i+rem > list.size()+1)
	    break;
	pii mem = memo[i][rem-1];
	pii k;
	if(mem.first == MIN)
	    k = solve(list, i, rem-1);
	else
	    k = mem;
	int t = list[index] * k.first;
	int r;
	if(index == 0)
	    r = k.second;
	else
	    r = list[index] + k.second;
	//printf("in index %d t %d rem %d\n", index, t, rem);
	if(t > max)
	{
	    max = t;
	    sum = r;
	}
    }
    //printf("index %d max %d rem %d\n", index, max, rem);
    if(max > maxm)
    {
	maxm = max;
	maxs = sum;
    }
    if(max == maxm && sum > maxs)
	maxs = sum;
    memo[index][rem] = make_pair(max, sum);
    return make_pair(max, sum);
}

int main()
{
    int N, K;
    while(cin>>N>>K && (N!=0 && K!=0))
    {
	maxm = MIN;
	maxs = 0;
	deque<int> list(N);
	for(int i=0; i<N; i++)
	    cin>>list[i];
	list.push_front(1);
	cout<<"max sum "<<maxs<<endl;
    }
    return 0;
}