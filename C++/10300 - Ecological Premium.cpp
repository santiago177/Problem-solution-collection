#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    for(int a = 0; a < n; a++)
    {
        int f, ans = 0;
        cin>>f;
        for(int b = 0; b < f; b++)
        {
            int s, t, fr;
            cin>>s>>t>>fr;
            ans += s*fr;
        }
        cout<<ans<<endl;
    }
    return 0;
}
