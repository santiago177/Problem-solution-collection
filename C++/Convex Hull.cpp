#include <iostream>
#include <queue>

using namespace std;

struct point
{
    int x;
    int y;
    bool operator < ()
};

int main()
{
    int n, min_y = 1001;
    point min_p, aux;
    cin >> n;
    priority_queue<point> q;
    for(int a = 0; a < n; a++)
    {
        int x, y;
        cin >> x >> y;
        aux.x = x;
        aux.y = y;
        q.push_back(aux);
        if(y < min_y)
        {
            min_p = aux;
        }
    }
    while(!q.empty())
    {
        cout << q.top().x << q.top().y << endl;
        q.pop();
    }

    return 0;
}
