#include<stdio.h>
#include<string.h>

int modin(int p)
{
    int x;
    p=p%26;
    for (x=1;x<26;x++)
        if ( (x*p)%26==1 )
            return x;
}

void main(){
    char a[10];
    int i,k1,k2;
    k1=3;
    k2=2;
    int pl[10],c1[10],enc[10],dec[10];
    printf("Enter the plain text:\n");
    scanf("%s",a);

    printf("Encoded Text:");
    for(i=0;i<strlen(a);i++){
        pl[i]=a[i]-65;
        c1[i]=(pl[i]*k1)%26;
        enc[i]=(c1[i]+k2)%26;
        printf("%c",enc[i]+65);
    }
    printf("\n\nDecoded Text:");

    int dk1=modin(k1);

    for(i=0;i<strlen(a);i++)
        dec[i]=(  ( (enc[i]-k2) %26 ) *dk1  )%26;

    for(i=0;i<strlen(a);i++)
        printf("%c",dec[i]+65);
    printf("\n");

}
	 