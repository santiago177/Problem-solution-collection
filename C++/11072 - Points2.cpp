#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <cmath>


using namespace std;

int lx, ly;


struct point
{
    int x, y;
    point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    point()
    {}
    double euclid(const point p) const
    {
        return sqrt((p.x)*(p.x)+(p.y)*(p.y));
    }

    bool operator<(const point &p) const
    {
        double a, b;
        if(this->x == lx && this->y == ly)
            return true;
        if(p.x == lx && p.y == ly)
            return false;
        int r = this->x - lx, q = this->y - ly;
        a = atan2(r, q);
        r = p.x-lx;
        q = p.y-ly;
        b = atan2(r, q);
        if(a > b)
            true;
        else if(a == b)
        {
            point r(this->x, this->y);
                if(euclid(p) > (euclid(r)))
                    return true;
                else
                    return false;
        }
        else
            return false;
    }
};

bool turn(const point &a, const point &b, const point &c){
    double z = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    if(z > 0)
        return true;
    else
        return false;
}

void graham_scan(vector<point> &vertices)
{
    deque<point> d;
    vector<point> fin;
    d.push_front(vertices[0]);
    d.push_front(vertices[1]);
//    for(int a = 2; a < points.size(); a++)
//        {
//            Point top = hull.pop();
//            while(turn(hull.peek(), top, points.get(a)) < 0)
//                top = hull.pop();
//            hull.push(top);
//            hull.push(points.get(a));
//        }
    point top;
    for(int a = 2; a < vertices.size(); a++)
    {
        top = d.front();
        d.pop_front();
        while(turn(d.front(), top, vertices[a]))
        {
            top = d.front();
            d.pop_front();
        }
        d.push_front(top);
        d.push_back(vertices[a]);
    }
    while(!d.empty())
    {
        top = d.back();
        d.pop_back();
        fin.push_back(top);
    }
        vertices = fin;
}

int main()
{
    int n;
    vector<point> vertices;
    vector<point> points;
    while(cin>>n)
    {
        int min = 100000;
        for(int a = 0; a < n; a++)
        {
            int x, y;
            cin>>x>>y;
            point p(x,y);
            if(p.y < min)
            {
                lx = p.x;
                ly = p.y;
                min = p.y;
                //cout<<"lx= "<<lx<<" ly= "<<ly<<"min = "<<min<<endl;
            }
            vertices.push_back(p);
        }
        sort(vertices.begin(), vertices.begin()+n);
        graham_scan(vertices);
        cout<<"hull"<<endl;
        for(int a = 0; a < n; a++)
        {
            cout<<vertices[a].x<<" "<<vertices[a].y<<endl;
        }
//        if(vertices[0] < vertices[1])
//            cout<<"true"<<endl;
//        else
//            cout<<"false"<<endl;
        vertices.clear();
        points.clear();
    }
    return 0;
}


