#include <cstdio>
#include <iostream>
#include <cmath>
#include <utility>

using namespace std;

long double dot(pair<long double, long double> a, pair<long double, long double> b)
{
    return (long double)(a.first*b.first)+(long double)(a.second*b.second);
}

bool triangleTest(pair<long double, long double> a, pair<long double, long double> b, pair<long double, long double> c, pair<long double, long double> p)
{
    pair<long double, long double> v0 = make_pair(c.first - a.first, c.second - a.second);
    pair<long double, long double> v1 = make_pair(b.first - a.first, b.second - a.second);
    pair<long double, long double> v2 = make_pair(p.first - a.first, p.second - a.second);
    long double dot00 = dot(v0, v0);
    long double dot01 = dot(v0, v1);
    long double dot02 = dot(v0, v2);
    long double dot11 = dot(v1, v1);
    long double dot12 = dot(v1, v2);
//    cout<<"divisor "<<divisor<<endl;
    //cout<<"dot00 "<<dot02<<endl;
    //cout<<"v0 "<<v0.first<<" "<<v0.second<<endl;
//    u = (dot11 * dot02 - dot01 * dot12) * invDenom
//    v = (dot00 * dot12 - dot01 * dot02) * invDenom
    // Check if point is in triangle
//return (u >= 0) && (v >= 0) && (u + v < 1)
//cout<<"this "<<(dot00 * dot11 - dot01 * dot01)<<endl;
    long double u = (dot11 * dot02 - dot01 * dot12)/(dot00 * dot11 - dot01 * dot01);
    long double v = (dot00 * dot12 - dot01 * dot02)/(dot00 * dot11 - dot01 * dot01);
    //cout<<u<<" "<<v<<endl;
    return (u >= 0) && (v >= 0) && (u + v <= 1);
}
//long double cross(pair<long double, long double> a, pair<long double, long double> b)
//{
//    return (a.first*b.second)-(a.second*b.first);
//}
//bool sameSide(pair<long double, long double> p1, pair<long double, long double> p2, pair<long double, long double> a, pair<long double, long double> b)
//{
//    pair<long double, long double> v0 = make_pair(b.first-a.first, b.second-a.second);
//    pair<long double, long double> v1 = make_pair(p1.first-a.first, p1.second-a.second);
//    pair<long double, long double> v2 = make_pair(p2.first-a.first, p2.second-a.second);
//    long double cp1 = cross(v0, v1);
//    long double cp2 = cross(v0, v2);
//    return cp1*cp2  >= 0;
//}
//bool triangleTest(pair<long double, long double> p, pair<long double, long double> a, pair<long double, long double> b, pair<long double, long double> c)
//{
//    return sameSide(p, a, b, c) && sameSide(p, b, a, c) && sameSide(p, c, a, b);
//}
bool is_equal(long double d1, long double d2)
{
    long double epsilon = 0.0000000000001;
        if(abs(d1-d2)<epsilon)
                return true;
        return false;
}

int main()
{
    freopen("143 - Orchard Trees.in", "r", stdin);
    long double vx[3], vy[3];
    //scanf("%lf %lf %lf %lf %lf %lf", &a, &b, &c, &d, &e, &f
    //scanf("%lf %lf %lf %lf %lf %lf", vx[0], vy[0], vx[1], vy[1], vx[2], vy[2])
    while(cin>>vx[0]>>vy[0]>>vx[1]>>vy[1]>>vx[2]>>vy[2] && !(is_equal(vx[0], 0.0) && is_equal(vx[1], 0.0) && is_equal(vx[2], 0.0) && is_equal(vy[0], 0.0) && is_equal(vy[1], 0.0) && is_equal(vy[2], 0.0)))
    {
        //cout<<"ja"<<endl;
//        cout<<vx[0]<<" "<<vy[0]<<" "<<vx[1]<<" "<<vy[1]<<" "<<vx[2]<<" "<<vy[2]<<endl;
//        if(vy[1] == 0 && vy[2] == 0 && vy[3] == 0 && vx[0] == 0 && vx[1] == 0 && vx[2] == 0)
//            break;
        int cont = 0;
        int max_x = -1, max_y = -1, min_x = 200, min_y = 200;
        for(int a = 0; a < 3; a++)
        {
            if(vx[a] > max_x)
                max_x = vx[a] + 1;
            if(vy[a] > max_y)
                max_y = vy[a] + 1;
            if(vx[a] < min_x)
                min_x = vx[a] - 1;
            if(vy[a] < min_y)
                min_y = vy[a] - 1;
        }
        for(int a = min_x; a <= max_x; a++)
        {
            for(int b = min_y; b <= max_y; b++)
            {
                //cout<<a<< " "<<b<<endl;
                if(triangleTest(make_pair(vx[1], vy[1]), make_pair(vx[2], vy[2]),make_pair(vx[0], vy[0]),make_pair(a, b)))
                    cont++;
            }
        }
        //cout<<"ch "<<1<<endl;
        printf("%4d\n", cont);
    }
    return 0;
}













