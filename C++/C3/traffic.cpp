#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    int n;
    while(cin>>n && n != 0)
    {
	double count = 0, dist, time;
	int vel = 0;
	int g = -1, h, prev;
	for(int a = 0; a < n; a++)
	{
	    if(g != -1)
	    {
		prev = h;
		cin>>g>>h;
		time = vel / 2.0;
		//cout<<"check1 "<<dist<<" "<<time<<" "<<vel<<" "<<count<<endl;
		if(time < g - prev)
		{
		    dist = vel * time - time * time;
		    vel = 0;
		    count += dist;
		    //cout<<dist<<" "<<time<<" "<<vel<<" "<<count<<endl;
		}
		else
		{
		    time = g - prev;
		    dist =  vel * time - time * time;
		    count += dist;
		    vel = vel - 2.0 * time;
		    //cout<<"check3 "<<dist<<" "<<time<<" "<<vel<<" "<<count<<endl;
		}
	    }
	    else
	    {
		cin>>g>>h;
	    }
	    time = h - g;
	    //cout<<h<<" "<<g<<endl;
	    if(vel + h - g >= 10)
	    {
		time = 10 - vel;
		dist = vel*time + 0.5 * time * time;
		vel = 10;
		count += dist;
		time = h - time - g;
		count += 10.0 * time;
		//cout<<dist<<" "<<time<<" "<<vel<<" "<<count<<endl;
		continue;
	    }
	    dist = vel * time + 0.5 * time * time;
	    vel = vel + time;
	    count += dist;
	    //cout<<dist<<" "<<time<<" "<<vel<<" "<<count<<endl;
	}
	printf("%.2lf\n", count);
    }
    return 0;
}
