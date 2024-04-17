#include <stdio.h>
#include <stdlib.h>

//void FooX(int matrix[][4], int par)
//{
//    int sum = 0, a;
//    if(par < 1)
//    {
//        for(a = 0; a < 4; a++)
//            sum += *(*(matrix)+a);
//        *(*(matrix+1)+2) = sum;
//    }
//    else if(par < 5)
//    {
//        *(*(matrix+1)+2) += *(*(matrix+3)+1);
//    }
//    else if(par < 10)
//    {
//        *(*(matrix+1)+2) =*(*(matrix+3)+3);
//    }
//    else
//    {
//        *(*(matrix+1)+2) -= *(*(matrix+2)+3);
//    }
//}
void FooX(int matrix[][4])
{
    int sum = 0, a, b;
    for(a = 0; a < 4; a++)
    {
        for(b = 0; b < 2; b++)
            sum += matrix [a][b];
    }
    matrix[1][0] = sum;
}

int main()
{
    int matrix[4][4] = {{1, 5, 2, 7}, {2, 3, 9, 12}, {4, 7, 5, 2}, {2, 2, 9, 32}};
    int p;

    FooX(matrix);
    printf("%d", matrix[0][0]);
    return 0;
}
