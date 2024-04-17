#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

int mod = (1LL<<31)-1;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, s, p, q;
    cin>>n>>s>>p>>q;
    int count = 1;
    vector<bool> numbers(mod-1, false);
    long long a = s&mod;
    numbers[a] = true;
    for(int i = 1; i < n; i++) {
        a = (a*p+q);
	a &= ((1LL << 31) - 1);
        if(!numbers[a]) {
            numbers[a] = true;
            count++;
        }
        else
            break;
    }
    cout<<count<<endl;
    return 0;
}


