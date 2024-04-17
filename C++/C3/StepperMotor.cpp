#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <cmath>

using namespace std;

typedef priority_queue<pair<int, int> > pqpii;

class StepperMotor 
{
    public:
    
    int shortest(int p1, int p2, int steps)
    {
	if((p1 < 0 && p2 >= 0) ||( p1 >= 0 && p2 < 0))
	{
	    if(p1 < 0)
		p1 = steps + p1;
	    if(p2 < 0)
		p2 = steps + p2;
	    int d1, d2;
	    d1 = abs(p1 - p2);
	    d2 = -abs((steps + p1) - p2);
	    if(d1 < -d2)
		return d1;
	    if(-d2 < d1)
		return d2;
	    return d1;
	}
	cout<<"p1 = "<<p1<<" p2 = "<<p2<<endl;
	if(p1 < 0)
	    p1 = steps + p1;
	if(p2 < 0)
	    p2 = steps + p2;
	if(p1 > p2)
	{
	    int d1, d2;
	    d1 = p2 - p1;
	    d2 = steps - abs(d1);
	    if(abs(d1) == d2)
		return d2;
	    return d1;
	}
	int d1, d2;
	d1 = p2 - p1;
	return d1;
    }
    int trans(int n, int steps, int low, int upp)
    {
	if(n > 0)
	{
	    int copy = n % steps;
	    if(copy <= upp)
		return copy;
	    return copy - steps;
	}
	int copy = -n % steps;
	copy *= -1;
	if(copy >= low)
	    return copy;
	return steps + copy;
    }

    int rotateToNearest(int n, int current, vector <int> target) 
    {
	int low, upp;
	low = -(n-1)/2;
	upp = n/2;
	pqpii moves;
	if(current < low || current > upp)
	    current = trans(current, n, low, upp);
	cout<<"current = "<<current<<endl;
	for(int a = 0; a < target.size(); a++)
	{
	    int rounded;
	    if(target[a] < low || target[a] > upp)
		rounded = trans(target[a], n, low, upp);
	    else
		rounded = target[a];
		cout<<"rounded = "<<rounded<<endl;
	    int mov = shortest(current, rounded, n);
	    cout<<"mov = "<<mov<<endl;
	    moves.push(make_pair(-abs(mov), mov));
	}
	pair<int, int> m1, m2;
	m1 = moves.top();
	moves.pop();
	m2 = moves.top();
	if(m1.first == m2.first)
	{
	    if(m1.second > m2.second)
		return m1.second;
	    return m2.second;
	}
	return m1.second;
    }
};

