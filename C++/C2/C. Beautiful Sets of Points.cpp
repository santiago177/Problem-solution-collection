#include <iostream>
#include <cmath>
#include <vector>
#include <utility>

using namespace std;

double euclid(int x1, int y1, int x2, int y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main()
{
    bool points[101][101] = {0};
    int m, n, cont = 0;
    cin>>n>>m;
    vector<pair<int, int> > cords;
    for(int a = 0; a <= n; a++)
    {
        for(int b = 0; b <= m; b++)
        {
            if(points[a][b])
                continue;
            for(int c = a; c <= n; c++)
            {
                for(int d = b; d <= m; d++)
                {
//                    cout<<"p1 "<<a<<" "<<b<<" p2 "<<c<<" "<<d<<endl;
                    double p = euclid(a, b, c, d);
                    int t = p;
//                    cout<<"t = "<<t<<" p= "<<p<<endl;
                    if(p-t == 0 && !(a == c && b == d))
                    {
//                        cout<<"no"<<endl;
                        points[c][d] = true;
                    }
                }
            }
        }
    }
    for(int a = 0; a <= n; a++)
    {
        for(int b = 0; b <= m; b++)
            if(!points[a][b])
            {
                cont++;
                cords.push_back(make_pair(a, b));
            }
    }
    cout<<cont<<endl;
    for(int a = 0; a < cords.size(); a++)
        cout<<cords[a].first<<" "<<cords[a].second<<endl;
    return 0;
}
