#include <iostream>
#include <map>
#include <vector>

using namespace std;
int main()
{

    string s = "a";
    map<string, vector<int> >mp;
    mp[s] = vector<int>(50, 0);	
    return 0;
}
