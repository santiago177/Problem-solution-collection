#include <iostream>
#include <cstdio>
#include <sstream>

using namespace std;

int main()
{
    freopen("Error Correction.in", "r", stdin);
    int n;
    int matrix[100][100];
    while(cin>>n && n!=0)
    {
        cin.ignore();
        for(int a = 0; a < n; a++)
        {
            string s;
            getline(cin, s);
            stringstream st(s);
            for(int b = 0; b < n; b++)
            {
                st>>matrix[a][b];
                //cout<<matrix[a][b]<<endl;
            }
        }
        int count, count2, x, y;
        bool on = true, ans = true;
        for(int a = 0; a < n && ans; a++)
        {
            count = 0;
            for(int b = 0; b < n && ans; b++)
                count += matrix[a][b];
//                cout<<" a = "<<a<<endl;
            if(count % 2 == 1 && on)
            {
                for(int c = 0; c < n && ans && on; c++)
                {
                    count2 = 0;
                    for(int d = 0; d < n && ans && on; d++)
                        count2 += matrix[d][c];
                    if(count2 % 2 == 1)
                    {
//                        cout<<" c = "<<c<<endl;
//                        cout<<"revise "<<a<<" "<<c<<endl;
                        if(matrix[a][c] == 1 && on)
                            matrix[a][c] = 0;
                        else
                            matrix[a][c] = 1;
                        x = a;
                        y = c;
                        on = false;
                    }
                }
                if(on)
                    ans = false;
            }
            else if(count % 2 == 1 && !on)
                ans = false;
        }
        for(int a = 0; a < n && ans; a++)
        {
            count = 0;
            for(int b = 0; b < n && ans; b++)
                count += matrix[b][a];
            if(count % 2 == 1 && on)
                ans = false;
        }
//        for(int a = 0; a < n; a++)
//        {
//            for(int b = 0; b < n; b++)
//                cout<<matrix[a][b];
//            cout<<endl;
//        }
        //Change bit (2,3)
        if(ans && on)
            cout<<"OK"<<endl;
        else if(ans && !on)
            cout<<"Change bit ("<<x+1<<","<<y+1<<")"<<endl;
        else
            cout<<"Corrupt"<<endl;

    }
    return 0;
}
