#include <stdio.h>
#include<string.h>
    int findinverse(int a);
    void main ()
    {
        char pt[50],ct[50];
        int k1,k2,i,e[50],d[50];

        printf("Enter the plain txt ");
        scanf("%s",pt);

        printf("Enter first key ");
        scanf("%d",&k1);

        printf("Enter the second key ");
        scanf("%d",&k2);

        printf("ENCRYPTION ");
        for(i=0;i<strlen(pt);i++)
        {
            e[i]=(int)(pt[i]-65);
            e[i]=(e[i]*k1)%26;
            e[i]=(e[i]+k2)%26;

        }
        for(i=0;i<strlen(pt);i++)
            printf("%c",e[i]+65);

        printf("\nDECRYPTION ");
        for(i=0;i<strlen(pt);i++)
        {d[i]=(e[i]-k2)%26;
            d[i]=(((d[i]*findinverse(k1))%26) + 26 ) % 26;
        }

        for(i=0;i<strlen(pt);i++)
            printf("%c",d[i]+65);
    }
    int findinverse(int a)
    {
        int m=26;
        a = a%m;
        for (int x=1; x<m; x++)
            if ((a*x) % m == 1)
                return x;
    }