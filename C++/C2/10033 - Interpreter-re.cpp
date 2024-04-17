#include <iostream>
#include <cstdio>

using namespace std;

void interpreter(int inst, int *ram, int *reg, int &cont)
{
    int i[3], c;
    for(int a = 0; a < 3; a++)
    {
        //printf("inst = %d\n", inst);
        c = inst % 10;
        inst = inst/10;
        i[2-a] = c;
        //printf("c = %d\n", inst);
        //printf("i[%d] = %d\n", 2-a, i[2-a]);
    }
    if(i[0] == 1)
        cont++;
    if(i[0] == 2)
    {
        reg[i[1]] = i[2];
        reg[i[1]] %= 1000;
        cont++;
    }
    if(i[0] == 3)
    {
        reg[i[1]] += i[2];
        reg[i[1]] %= 1000;
        cont++;
    }
    if(i[0] == 4)
    {
        reg[i[1]] *= i[2];
        reg[i[1]] %= 1000;
        cont++;
    }
    if(i[0] == 5)
    {
        reg[i[1]] = reg[i[2]];
        reg[i[1]] %= 1000;
        cont++;
    }
    if(i[0] == 6)
    {
        reg[i[1]] += reg[i[2]];
        reg[i[1]] %= 1000;
        cont++;
    }
    if(i[0] == 7)
    {
        reg[i[1]] *= reg[i[2]];
        reg[i[1]] %= 1000;
        cont++;
    }
    if(i[0] == 8)
    {
        reg[i[1]] = ram[reg[i[2]]];
        cont++;
    }
    if(i[0] == 9)
    {
        ram[reg[i[2]]] = reg[i[1]];
        cont++;
    }
    if(i[0] == 0)
    {
            cont++;
    }
}

int main()
{
    //freopen("10033 - Interpreter.in", "r", stdin);
    int n = 0;
    cin>>n;
    for(int z = 0; z < n; z++)
    {
        int inst, cont = 1;
        int ram[1000] = {0}, reg[10] = {0};
        while(cin>>inst)
        {
            interpreter(inst, ram, reg, cont);
            //printf("inst = %d\n", inst);
        }
        printf("%d", cont);
    }
    return 0;
}