#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

struct point
{
    int x, y;
    point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};

int dot(point p1, point p2)
{
    return p1.x*p2.x+p1.y*p2.y;
}

bool test(point p, point v1, point v2, point v3)
{
    //A = v1
    int a, b, c, d, e;
    double u, v;
    point vec1(v2.x-v1.x,v2.y-v1.y);
    point vec2(v3.x-v1.x,v3.y-v1.y);
    point vec3(p.x-v1.x,p.y-v1.y);
    a = dot(vec1, vec1);
    b = dot(vec1, vec2);
    c = dot(vec1, vec3);
    d = dot(vec2, vec2);
    e = dot(vec2, vec3);
    u = (double)(d*c-b*e)/(a*d-b*b);
    v = (double)(a*e-b*c)/(a*d-b*b);
    //cout<<"d*c = "<<d*c<<"b = "<<b<<endl;
    return (u >= 0.0) && (v >= 0.0) && (u + v <= 1.0);
}

int main()
{
//    point t1(1,2), t2(0,-1), t3(3,0), p(3,0);
//    //cout<<p1.x<<" "<<p1.y;
//    if(test(p, t1, t2, t3))
//        cout<<"ja";
//    else
//        cout<<"nein";
//    freopen("points.in", "r", stdin);
//    freopen("points.out", "w", stdout);
    string nad;
    int n;
    while(cin>>n)
    {
        //cout<<"n = "<<n<<endl;
        bool flag1;
        vector<point> polygon;
        vector<point> points;
        for(int a = 0; a < n; a++)
        {
            int x, y;
            cin >> x >> y;
            point p(x,y);
            polygon.push_back(p);
        }
        cin>>n;
        for(int a = 0; a < n; a++)
        {
            int x, y;
            cin >> x >> y;
            point p(x,y);
            points.push_back(p);
        }
        for(int a = 0; a < points.size(); a++)
        {
            flag1 = true;
            for(int b = 1; b < polygon.size() && flag1; b++)
            {
                for(int c = b+1; c < polygon.size() && flag1; c++)
                {
                    if(test(points[a], polygon[0], polygon[c], polygon[b]))
                        flag1 = false;
                }
            }
            if(flag1)
                cout<<"outside"<<endl;
            else
                cout<<"inside"<<endl;
        }
        polygon.clear();
        points.clear();
//        if(!flag2)
//        {
//            for(int a = 0; a < points.size(); a++)
//                if(points[a].x == polygon[0].x && points[a].y == polygon[0].y)
//                cout<<"inside"<<endl;
//                else
//                (a==points.size()-1)?cout<<"outside":cout<<"outside"<<endl;
//        }
    }
    return 0;
}

