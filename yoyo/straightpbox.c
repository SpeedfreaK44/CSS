#include<stdio.h>
#include<string.h>
#include<stdint.h>
#include<stdlib.h>

/*void binary(int k)
{
	int bin_num[8],i=0;
	while(k>0)
	{
		bin_num[i]=k%2;
		k=k/2;
		i++
	}
	puts(bin_num);
}*/
void main()
{
	int matrix[8][8]={
		{58,56,42,34,26,18,10,2},
		{60,52,44,36,28,20,12,4},
		{62,54,46,38,30,22,14,6},
		{64,56,48,40,32,24,16,8},
		{57,49,41,33,25,17,9,1},
		{59,51,43,35,27,19,11,3},
		{61,53,45,37,29,21,13,5},
		{63,55,47,39,31,23,15,7},
	};

	int i,k,t,bin_num[8];
	int output[64]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63};
	/*int output[8][8]={
		{0,1,2,3,4,5,6,7},
		{8,9,10,11,12,13,14,15},
		{16,17,18,19,20,21,22,23},
		{24,25,26,27,28,29,30,31},
		{32,33,34,35,36,37,38,39},
		{40,41,42,43,44,45,46,47},
		{48,49,50,51,52,53,54,55},
		{56,57,58,59,60,61,62,63},
	};*/
	char plaintext[8];
	int matrix_i=0,matrix_j=0;	

	//taking input
	printf("Enter a plaintext:");
	gets(plaintext);

//calculating binary
	for(i=0;i<8;i++)
	{
		int j=0;
		printf("%c\n",plaintext[i]);
		k=(int)(plaintext[i]);
		while(k>0)
		{
			bin_num[j]=k%2;
			k=k/2;
			//j--;
			t=matrix[matrix_i][matrix_j];
			printf("binary:%d\n",bin_num[j]);
			//printf("%d\n",t );
			printf("t:%d\n", output[t]);
			output[t-1]=bin_num[j];
			printf("Output:%d\n", output[t-1]);
			/*printf("t:%d\n", output[(int)((t)/8)][(int)((t)%8)]);
			output[(int)((t)/8)][(int)((t)%8)]=bin_num[j];
			printf("output:%d \t %d\t %d\t\n", (int)((t)/8),(int)((t)%8),output[(int)((t)/8)][(int)((t)%8)]);
			*/
			j++;
			matrix_j++;
		}
		matrix_i++;
		printf("\n");
	//print binary number
		for (int w =j-1; w >= 0; w--)
		{
			printf("%d\t",bin_num[w] );
		}
		/*for(int w=j-1;w>=0;w--)
		{
			printf("%d ", bin_num[w]);
		}*/
		printf("\n");
	}

	for (int rows = 0; rows < 8; rows++)
	{
		for (int columns = 0; columns < 8; columns++)
		{
			printf("%d\t",matrix[rows][columns]);
		}
		printf("\n");
	}	

	//for (int rs = 0; rs < 8; rs++)
	//{
		for (int cs = 0; cs < 64; cs++)
		{
			printf("%d\t",output[cs]);
		}
		//printf("\n");
	//}	
}