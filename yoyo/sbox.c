#include <stdio.h>

int binToDec(char *arr, int size){
	int i;
	int val = 0;
	for(i=0;i<size;i++)
	{
		if(arr[i] & 1)
		{
			val += 1<<(size-i-1);
		}
	}

	return val;
}

void decToBin(int x)
{
	int i;
	x = (char)x;
	char mask = 8;
	for(i=0;i<4;i++)
	{
		if(mask & x)
		{
			printf("1");
		}
		else
		{
			printf("0");
		}
		mask = mask >> 1;
	}
	printf("\n");
}

void main()
{
	int sbox[4][16] = {{14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7},
						{0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8},
						{4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0},
						{15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13}};

	int input,i,r,c;
	char ch;
	char row[2];
	char col[4];

	scanf("%d",&input);
	ch = (char)input;
	printf("\n%d",ch);

	ch = ch & 0x3f;
	printf("\n%d",ch);

	row[0] = (char)(ch & 1<<5)>>5;
	row[1] = (char)ch & 1;

	for(i=0;i<4;i++){
		col[i] = (ch & 1<<(4-i))>>(4-i);
	}

	r = binToDec(row,2);
	c = binToDec(col,4);

	printf("\nr:%d  c:%d\n",r,c);
	decToBin(sbox[r][c]);
}