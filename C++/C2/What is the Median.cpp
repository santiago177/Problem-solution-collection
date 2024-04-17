#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    long long n;
    vector<long long> numbers;
    while(cin>>n)
    {
	numbers.push_back(n);
	int size = numbers.size();
	sort(numbers.begin(), numbers.end());
	if(size % 2 == 1)
	    cout<<numbers[(size+1)/2-1]<<endl;
	else
	    cout<<int((numbers[size/2-1]+numbers[size/2])/2)<<endl;
    }
    return 0;
}
