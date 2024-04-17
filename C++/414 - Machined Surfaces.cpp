#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    //freopen("414 - Machined Surfaces.in", "r", stdin);
    int n;
    while(cin>>n && n!=0)
    {
        int cont;
        vector<string> lines(n);
        vector<int> xperl(n);
        cin.ignore();
        for(int a = 0; a < n; a++)
            getline(cin, lines[a]);
        priority_queue<int> max;
        for(int a = 0; a < n; a++)
        {
            cont = 0;
            for(int b = 0; b < 25; b++)
            {
                if(lines[a][b] == 'X')
                    cont++;
            }
            xperl[a] = cont;
            max.push(cont);
        }
        cont = 0;
        //cout<<"top "<<max.top()<<endl;
        for(int a = 0; a < n; a++)
            cont += max.top()-xperl[a];
        cout<<cont<<endl;
    }
    return 0;
}










