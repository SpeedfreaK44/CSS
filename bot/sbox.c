#include<stdio.h>
#include<math.h>
void main()
{
	int S1[4][16] = 
    	{
		14,  4, 13,  1,  2, 15, 11,  8,  3, 10,  6, 12,  5,  9,  0,  7,
		0, 15,  7,  4, 14,  2, 13,  1, 10,  6, 12, 11,  9,  5,  3,  8,
		4,  1, 14,  8, 13,  6,  2, 11, 15, 12,  9,  7,  3, 10,  5,  0,
		15, 12,  8,  2,  4,  9,  1,  7,  5, 11,  3, 14, 10,  0,  6, 13
    	};
	int buff[4];
	int input[6] = {0,0,0,0,0,0};
	int row = (input[5] * pow(2,0)) + (input[0] * pow(2,1));
	int col = (input[4] * pow(2,0)) + (input[3] * pow(2,1)) + (input[2] * pow(2,2)) + (input[1] * pow(2,3));
	printf("row = %d\ncol = %d\n", row,col);
	int ansdecimal = S1[row][col];
	printf("decimal = %d\n",ansdecimal);
	int k, d;
	for(int i = 0, d = 3; i<4; i++, d--)							
	{
		k = ansdecimal >> i;
		if(k & 1)
	        	buff[d] = 1;
		else
		   	buff[d] = 0;
	}
	for(int i = 0; i<4; i++)
		printf("%d",buff[i]);
}
