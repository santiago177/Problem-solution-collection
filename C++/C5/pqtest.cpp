#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Comp {
    public:
	bool operator()(int a, int b) {
	    return a < b;
	}
};

bool compare(int a, int b) {
    return a < b;
}

int main() {

    priority_queue<int, deque<int>, bool(*)(int, int)> pqtest(compare);
    
    pqtest.push(2);
    pqtest.push(6);
    pqtest.push(5);
    pqtest.push(7);
    pqtest.push(1);
    pqtest.push(10);

    while(!pqtest.empty()) {
	cout<<pqtest.top()<<endl;
	pqtest.pop();
    }

    return 0;
}
