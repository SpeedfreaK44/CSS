Pbox:
#include <stdio.h>

void main(){
	int x;
	int bit;
	int row;
	int pbox[8][8] = {{58,50,42,34,26,18,10,2},
					  {60,52,44,36,28,20,12,4},
					  {62,54,46,38,30,22,14,6},
					  {64,56,48,40,32,24,16,8},
					  {57,49,41,33,25,17,9,1},
					  {59,51,43,35,27,19,11,3},
					  {61,53,45,37,29,21,13,5},
					  {63,55,47,39,31,23,15,7}};
	char s[8];

	for(int i=0;i<8;i++){
		scanf("%d",&x);
		s[i] = (char)x;
	}

	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if(j%4==0){
				printf(" ");
			}
			bit = pbox[i][j];
			row = (bit-1)/8;
			printf("%ld",(s[row] & 1L<<(7 - ((bit-1)%8)))>>(7 - ((bit-1)%8)));
		}	
	}	
}

OUTPUT:

SpeedfreaK@DESKTOP-87GKBN0:/mnt/c/Sem 6/CSS/expt 2$ gcc pbox.c                                                            SpeedfreaK@DESKTOP-87GKBN0:/mnt/c/Sem 6/CSS/expt 2$ ./a.out                                                               1                                                                                                                      
35                                                                                                                     
69                                                                                                                    
103                                                                                                                     
137                                                                                                                     
171                                                                                                                     
205                                                                                                                    
239                                                                                                                     
1100 1100 0000 0000 1100 1100 1111 1111 1111 0000 1010 1010 1111 0000 1010 1010

Sbox:

PROGRAM:
#include <stdio.h>

int binToDec(char *x, int size){
	int val=0;
	char mask = (char)1;

	for(int i=0;i<size;i++){
		if((mask & x[i]) == 1){
			val += (int)(mask<<(size-i-1));
		}
	}
	printf("%d\n",val);
	return val;
}

void decToBin(int x){

	char mask = (char)8;
	x = (char)x;
	while(mask > 0){
		if((x & mask) == 0){
			printf("0");
		}
		else{
			printf("1");
		}

		mask = mask >> 1;
	}
	printf("\n");
}

void main(){
	int sbox[4][16] = {{14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7},
						{0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8},
						{4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0},
						{15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13}};

	char s;
	int x;
	scanf("%d",&x);
	s = (char)x;
	char row[2];
	char col[4];
	int r;
	int c;

	s = s & 0x3f;


	row[0] = (char)(s & 1<<5)>>5;
	row[1] = (char)s & 1<<0;

	for(int i=0;i<4;i++){
		col[i] = (char)((s & 1<<(4-i))>>(4-i));
		// printf("%d\n",col[i]);
	}


	r = binToDec(row,(int)sizeof(row)/(sizeof(row[0])));
	c = binToDec(col,(int)sizeof(col)/(sizeof(col[0])));

	decToBin(sbox[r][c]);
	// printf("%d\n",(s & (1<<3))>>3);
}

OUTPUT:

SpeedfreaK@DESKTOP-87GKBN0:/mnt/c/Sem 6/CSS/expt 2$ gcc sbox.c                                                            SpeedfreaK@DESKTOP-87GKBN0:/mnt/c/Sem 6/CSS/expt 2$ ./a.out                                                               18                                                                                                                      
0                                                                                                                      
9                                                                                                                       
1010
