#include<stdio.h>
#include<string.h>
void main(){
    int sbox[4][16]={{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15},
                     {0,2,4,6,8,10,12,14,3,5,7,9,11,13,15,1},
                     {11,1,13,14,5,6,7,10,0,12,8,9,15,2,3,4},
                     {0,1,2,3,13,14,15,8,9,10,4,5,6,7,11,12}};

    int num;
    printf("Enter a number( upto 63 bits in decimal format):\n");
    scanf("%d",&num);

    int db[6];
    int i;
    int m;
    int row,col;
    m=num;

    for(i=5;i>=0;i--){
        db[i]=m%2;
        m=m/2;
    }
    for(i=0;i<6;i++)
        printf("%d",db[i]);

    col=(2*2*2)*(db[1])+(2*2)*(db[2])+(2)*(db[3])+(1)*(db[4]);
    row=(2)*(db[0])+(1)*(db[5]);

    printf("\nNumber substituted for given value is (6 bit to 4 bit conversion):%d\n",sbox[row][col]);

}
