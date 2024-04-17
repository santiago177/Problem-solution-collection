#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool test(vector<string> &codes)
{
    for(int a = 0; a < codes.size(); a++)
    {
        for(int b = a+1; b < codes.size(); b++)
        {
            if(codes[a].size() <= codes[b].size())
            {
                if(codes[a] == codes[b].substr(0, codes[a].size()))
                    return false;
            }
        }
    }
    return true;
}

int main()
{
    int cont = 0;
    string s;
    vector<string> codes;
    while(cin>>s)
    {
        codes.push_back(s);
        if(s == "9")
        {
            //Set 1 is immediately decodable
            sort(codes.begin(), codes.end());
            if(test(codes))
                cout<<"Set "<<++cont<<" is immediately decodable"<<endl;
            else
                cout<<"Set "<<++cont<<" is not immediately decodable"<<endl;
            codes.clear();
        }
    }
    return 0;
}
