#include <iostream>
#include <cmath>

using namespace std;

const double PI = 2*acos(0);

    double distance(double lat1, double lon1, double lat2, double lon2)
    {
	//radius * acos(sin(lat1) * sin(lat2) + cos(lat1) * cos(lat2) * cos(lon1 - lon2))
	lat1 = lat1/180*PI;
	lat2 = lat2/180*PI;
	lon1 = lon1/180*PI;
	lon2 = lon2/180*PI;
	cout<<double(sin(lat1) * sin(lat2) + cos(lat1) * cos(lat2) * cos(lon1 - lon2))<<endl;
	double ans = 4000 * acos(sin(lat1) * sin(lat2) + cos(lat1) * cos(lat2) * cos(lon1 - lon2));
	return ans;
    }


int main()
{
    double lat1, lon1, lat2, lon2;
    cout<<"PI = "<<PI<<endl;
    cin>>lat1>>lon1>>lat2>>lon2;
    double ans = distance(lat1, lon1, lat2, lon2);
    cout<<ans;
    return 0;
}
