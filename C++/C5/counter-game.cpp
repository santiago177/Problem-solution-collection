#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std; 

typedef unsigned long long ull;

unsigned long long TOP = 1ULL<<63;

bool power_of_2(ull n) {
    return n != 0 && !(n&(n-1));
}

ull get_largest_pow(ull n) {
    ull k = 1;
    //cout<<"get largest "<<n<<endl;
    while(k < n) {
        k <<= 1;
	//cout<<"k = "<<k<<endl;
	if(k==TOP)
	    break;
    }
    if(k == TOP)
	return k;
    return k >> 1;
}

string get_winner(ull n) {
    short win = 0;
    ull k = 0;
    while(n > 1) {
        if(power_of_2(n))
	{
            n >>= 1;
	    //cout<<"pow of 2 "<<n<<endl;
	}
        else {
	    //cout<<"not pow of 2 "<<k<<" "<<n<<endl;
            if(k == 0)
                k = get_largest_pow(n);
	    while(k > n)
		k >>= 1;
            n -= k;
            k >>= 1;
        }
        win ^= 1;
    }
    if(win == 0)
        return "Richard";
    else
        return "Louise";
}

int main() {
    //freopen("counter-game.out", "w", stdout);
    int T;
    cin>>T;
    ull e = 1ULL<<63;
    //cout<<"test "<<TOP<<" "<<e<<endl;
    for(int z = 0; z < T; z++) {
        ull n;
        cin>>n;
        cout<<get_winner(n)<<endl;
    }
    return 0;
}
