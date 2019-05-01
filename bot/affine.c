#include<stdio.h>
#include<string.h>
int main()
{
    char pt[100]; 
    char ct[strlen(pt)], p[strlen(pt)];
    int k1, k2, k1_inv;
    
    printf("Enter the plain text: ");
    gets(pt);
    printf("\nEnter the value of k1 and k2: ");
    scanf("%d %d", &k1,&k2);
    
    printf("\nThe encrypted text is: ");
    for(int i=0; i<strlen(pt); i++)
    {
        ct[i] = ((((k1 * (pt[i] - 'A')) + k2) % 26) + 'A');         //Encryption Formula
        printf("%c", ct[i]);
    }
    
    k1_inv = 0;
    int flag = 0;
    for(int i=0; i<26; i++)
    {
        flag = (k1 * i) % 26;           //checking multiplicative inverse (k1 * i) % 26 == 1
        if(flag == 1)
            k1_inv = i;
    }
    
    printf("\nDecrypted text is: ");
    for(int i=0; i<strlen(pt); i++)
    {
        p[i] = ((k1_inv * (ct[i] + 'A' - k2) % 26) + 'A');          //Decryption Formula
        printf("%c",p[i]);
    }
    return 0;
}