#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    double penetration;
    vector<double> temperature;
    while(cin>>penetration && penetration != 999)
	temperature.push_back(penetration);
    for(int a = 0; a < temperature.size()-1; a++)
	printf("%.2lf\n", temperature[a+1]-temperature[a]);
    printf("End of Output\n");
    return 0;
}
