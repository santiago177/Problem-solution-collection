#include <iostream>

const int limit = 5*1e7;
const int mod = (1LL<<31)-1;

using namespace std;

int main() {
    int a;
    for(int i = 0; i < limit; i++) {
	a = i % mod;
    }

    return 0;
}


