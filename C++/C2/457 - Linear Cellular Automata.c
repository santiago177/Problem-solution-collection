#include <stdio.h>

int main()
{
    int n, z, dna[10], a, b;
    char blank[1];
    scanf("%d", &n);
    for(z = 0; z < n; z++)
    {

        fgets(blank, 1, stdin);
        if(z != 0)
            printf("\n");
        int chain[42], newc[42];
        for(b = 0; b < 42; b++)
            chain[b] = 0;
        chain[20] = 1;
        scanf("%d %d %d %d %d %d %d %d %d %d", &dna[0], &dna[1], &dna[2], &dna[3], &dna[4], &dna[5], &dna[6], &dna[7], &dna[8], &dna[9]);
        for(a = 0; a < 50; a++)
        {
            for(b = 1; b <= 40; b++)
            {
                if(chain[b] == 1)
                    printf(".");
                else if(chain[b] == 2)
                    printf("x");
                else if(chain[b] == 3)
                    printf("W");
                else
                    printf(" ");
            }
            printf("\n");
            for(b = 1; b <= 40; b++)
                newc[b] = dna[chain[b]+chain[b-1]+chain[b+1]];
            for(b = 1; b <= 40; b++)
                chain[b] = newc[b];

        }
    }
    return 0;
}
