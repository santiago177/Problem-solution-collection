#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

class matrix
{
    public:
    vector<vector<long long> > matx;
    matrix(int n)
    {
        vector<vector<long long> > p(n);
        matx = p;
    }
    matrix()
    {}
};

int dot(matrix m1, matrix m2, int row, int col)
{
    int an = 0;
    for(int a = 0; a < m1.matx.size(); a++)
    {
            an += m1.matx[row][a] * m2.matx[a][col];
    }
   // cout<<"M = "<<an%m<<endl;
    return an;
}

matrix product(matrix m1, matrix m2)
{
    matrix res = m1;
    for(int a = 0; a < m1.matx.size(); a++)
    {
        for(int b = 0; b < m1.matx.size(); b++)
            res.matx[a][b] = dot(m1, m2, a, b);
    }
    return res;
}


void calc(vector<matrix> &vr, int k, matrix matx)
{
    vr[0] = matx;
    for(int a = 1; a < k; a++)
        vr[a] = product(vr[a-1], matx);
}

int main()
{
    int n, k, d, m;
    scanf("%d %d %d", &n, &k, &m);
    matrix matx(n);

    for(int a = 0; a < n; a++)
    {
        for(int b = 0; b < n; b++)
        {
            scanf("%d", &d);
            matx.matx[a].push_back(d);

        }
    }

    vector<matrix> vr(k+1);
//    matx = product(matx, matx, m);
//    for(int a = 0; a <n; a++)
//    {
//        for(int b = 0; b <n; b++)
//            cout<<matx.matx[a][b];
//        cout<<endl;
//    }
//    cout<<endl;
    calc(vr, k, matx);
    for(int a = 1; a < k; a++)
    {
        for(int b = 0; b < n; b++)
        {
            for(int c = 0; c < n; c++)
            {
                matx.matx[b][c] += vr[a].matx[b][c]%m;
                matx.matx[b][c] %= m;
            }
        }
    }
    for(int a = 0; a < n; a++)
    {
        for(int b = 0; b < n; b++)
        {
            if(b != 0)
                cout<<" "<<matx.matx[a][b];
            else
                cout<<matx.matx[a][b];
        }
        cout<<endl;
    }
    return 0;
}







