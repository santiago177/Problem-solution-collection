#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n;
    cin>>n;
    for(int z = 0; z < n; z++)
    {
        int h, j, y = 0, start;
        int array[1002];
        bool right = true;
        array[0] = -1;
        cin>>h>>j;
        array[h+1] = -1;
        for(int a = 1; a <= h; a++)
        {
            cin>>array[a];
            if(array[a] == 2)
            {
                array[a] = 1;
                start = a;
            }
            if(array[a] == 3)
            {
                right = false;
                start = a;
                array[a] = 1;
            }
        }
        int current = start;
        while(j)
        {
            int next;
            if(right)
                next = current+1;
            else
                next = current-1;
            if(array[next] == -1)
            {
                right = !right;
                continue;
            }
            current = next;
//            cout<<"current "<<current<<endl;
            if(array[current] == 0)
                y++;
            j--;
        }
        cout<<y<<endl;
    }
    return 0;
}



