#include <stdio.h>
void main()
{
    int pbox[8][8] = {{58,58,42,34,26,18,10,2},
                      {60,52,44,36,28,20,12,4},
                      {62,54,46,38,30,22,14,6},
                      {64,56,48,40,32,24,16,8},
                      {57,49,41,33,25,17,9,1},
                      {59,51,43,35,27,19,11,3},
                      {61,53,45,37,29,21,13,5},
                      {63,55,47,39,31,23,15,7},
                      };

    char str[8];
    int i, x, j;
    int bit, row;

    for (i = 0 ; i <  8 ; i++)
    {
        scanf("%d", &x);
        str[i] = (char) x;
    }

    for (i = 0 ; i < 8 ; i++)
    {
        for (j = 0 ; j < 8 ; j++)
        {
            if (j % 4 == 0)
            {
                printf(" ");
            }
            bit = pbox[i][j];
            row = (bit - 1) / 8;
            printf("%d", (str[row] & 1 << (7-(bit-1) % 8)) >> (7 - (bit -1) % 8));
        }
    }
}