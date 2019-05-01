#include<stdio.h>
void main()
{
    int msg, n, k, buff[448], buff1[64], buff2[512], d, i;
    printf("Enter the character :");
    scanf("%c",&msg);
    n = msg; 
	for(i=0, d=7 ;i<=7;i++, d--)							//decimal to 8bit binary
	{
		k = n >> i;
		if(k & 1)
			buff[d]=1;
		else
			buff[d]=0;
	}
    printf("Before Padding\n");
	for (i=0;i<8;i++)
		printf("%d",buff[i]);                   //binary of character
		
	buff[8] = 1;                //padding extra 1 
	printf("\nYour message contains %d bits.\n",i);
	printf("\nThe message will be padded to make it 448 mod 512 bits long.");
	printf("\nSince your message is %d bits we will add %d because 448 mod 512 = 448.", i, 448-i);
	printf("\nWe will add 1 and %d zeros", 448-i-1);
	int temp = i;
	for(i=temp+1; i<448; i++)
	    buff[i] = 0;
	printf("\nAfter appending all 448 bits: ");
	for(i=0; i<448; i++)
	    printf("%d",buff[i]);
	
	printf("\nNow padding 64 bit: ");
	for (i=0;i<56;i++)
        buff1[i] = 0;                                       //appending 0 
	for(i=0, d=7 ;i<=7;i++, d--)							//decimal to 8bit binary
	{
		k = temp >> i;
		if(k & 1)
			buff1[56+d]=1;                      //calculating binary of message length(bits)
		else
			buff1[56+d]=0;
	}
	for(i=0;i<64;i++)
	    printf("%d", buff1[i]);
	for(i=0;i<448;i++)
	    buff2[i] = buff[i];
	for(i=0;i<64;i++)
	    buff2[448+i] = buff1[i];
	printf("\nThe 512 bits after padding 64 and 448 bits together: ");
	for(i=0;i<512;i++)
	    printf("%d",buff2[i]);
}