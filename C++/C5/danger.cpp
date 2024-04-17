#include <iostream>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

int convert(int x, int y, int z)
{
    int ans = x*10 + y;
    ans *= pow(10, z);
    return ans;
}

int calc(int num)
{
    //vector<int> circle(num, 0);
    int power = (int)(log(num)/log(2));
    int ans = (num - pow(2, power)) * 2 + 1;
    return ans;
}

int main()
{
    string s;
    while(1)
    {
	cin>>s;
	if(s == "00e0")
	    break;
	int x, y, z;
	x = s[0] - '0';
	y = s[1] - '0';
	z = s[3] - '0';
	int num = convert(x, y, z);
	int ans = calc(num);
	cout<<ans<<endl;
    }
    return 0;
}


