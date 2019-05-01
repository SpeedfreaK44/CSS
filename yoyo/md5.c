#include <stdio.h>
#include <string.h>

void lengthBits(int len)
{
    unsigned long int length;
    length = len * 8;
    printf("\nPadding Length Bits:\n");
    unsigned long int i;
    for (i = 1ull << 63; i > 0; i = i >> 1)
    {
        (length & i) ? printf("1"):printf("0");
    }
    printf("\n");
}

void padding(int len)
{
    int padding_len, i;
    padding_len = (448 - len*8) % 512;
    printf("\nPadding Bits: %d\n", padding_len);
    for (i = 1; i <= padding_len; i++)
    {
        if (i == 1)
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
        if (i % 8 == 0)
        {
            printf(" ");
        }
    }
    printf("\n");
    lengthBits(len);
}

void asciiToBin(char *str)
{
    int i, j, len, x;
    len = strlen(str);
    for (i = 0; i < len; i++)
    {
        x = 0x80;
        for (j = 0; j < 8; j++)
        {
            (str[i] & x) ? printf("1"):printf("0");
            x = x >> 1;
        }
        if (j % 8 == 0)
        {
            printf("  ");
        }
    }
    printf("\n");
    padding(len);
}

void main()
{
    char input[100];
    gets(input);
    asciiToBin(input);
}