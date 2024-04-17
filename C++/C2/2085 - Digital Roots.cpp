#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string s;
    while(cin >> s && s != "0")
    {
        int sum = 11;
        while(sum >= 10)
        {
            sum = 0;
            for(int a = 0; a < s.size(); a++)
                sum += s[a] - '0';
            string p = "";
            int temp = sum;
            while(temp > 0)
            {
                p += (temp % 10) + '0';
                temp /= 10;
            }
            //cout<<"p= "<<p<<endl;
            s = p;
        }
        if(sum != 11)
        cout<<sum<<endl;
        else
        cout<<s<<endl;
    }
    return 0;
}
