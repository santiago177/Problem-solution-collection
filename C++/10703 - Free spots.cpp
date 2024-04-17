#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int h, w, sb;
    int matrix[501][501];
    char blank[1];
    while(scanf("%d %d %d", &h, &w, &sb))
    {

        if(h == 0 && w == 0 && sb == 0)
            break;
        int cont = 0;
        for(int a = 1; a <= h; a++)
        {
            for(int b = 1; b <= w; b++)
                matrix[a][b] = 0;
        }
        for(int a = 0; a < sb; a++)
        {
            int p1x, p1y, p2x, p2y, minx, maxx, miny, maxy;
            scanf("%d %d %d %d", &p1x, &p1y, &p2x, &p2y);
            if(p1x < p2x){
                minx = p1x;
                maxx = p2x;
            }
            else
            {
                minx = p2x;
                maxx = p1x;
            }
            if(p1y < p2y)
            {
                miny = p1y;
                maxy = p2y;
            }
            else
            {
                miny = p2y;
                maxy = p1y;
            }
            for(int b = minx; b <= maxx; b++)
            {
                for(int c = miny; c <= maxy; c++)
                    matrix[b][c] = 1;
            }
//            for(int a = 1; a <= h; a++)
//            {
//                for(int b = 1; b <= w; b++)
//                {
//                    cout<<matrix[a][b];
//                }
//                cout<<endl;
//            }
        }
        for(int a = 1; a <= h; a++)
        {
            for(int b = 1; b <= w; b++)
            {
                if(matrix[a][b] == 1)
                    cont++;
            }
        }
        cont = h*w-cont;
//        There is no empty spots.
//There is one empty spot.
//There are 83470 empty spots.
        if(cont == 0)
        {
            cout<<"There is no empty spots."<<endl;
        }
        else if(cont == 1)
        {
            cout<<"There is one empty spot."<<endl;
        }
        else
        {
            cout<<"There are "<<cont<<" empty spots."<<endl;
        }
        fgets(blank, 1, stdin);
    }
    return 0;
}
