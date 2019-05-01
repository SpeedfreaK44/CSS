#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
// include if using Euler's theorem
// #include <math.h>

int gcd(int a, int m){
	int temp;
	while(a != 0)
	{
		if(a == 1)
		{
			return 1;
		}
		temp = a;
		a = m % a; 
		m = temp;
	}

	return 0;
}

int additiveInv(int k)
{
	if(k < 26)
	{
		return abs(k-26);
	}
	return abs(k%26 - 26);
}

//extended Euclidean theorem
int mulInv(int k)
{
	int t = 0;
	int newt = 1;
	int r = 26;
	int newr = k;
	int temp1,temp2,q;

	while(newr != 0)
	{
		q = r/newr;
		temp1 = newt;
		temp2 = t - q*newt;
		t = temp1;
		newt = temp2;
		temp1 = newr;
		temp2 = r - q*newr;
		r = temp1;
		newr = temp2;
	}

	if(t < 0)
	{
		t = t+26;
	}

	return t;
}

//using Euler's theorem
// int mulInv(int k){
// 	// totient(26) = 12
// 	int phi = 12;
// 	k = (int)pow(k,phi-1) % 26;
// 	return k;
// }

void decrypt(char *str, int k1, int k2)
{
	int i;
	char ch;
	k2 = additiveInv(k2);
	k1 = mulInv(k1);

	printf("\nDecrypted string: ");

	for(i=0;i<strlen(str);i++)
	{
		ch = str[i];
		ch = ch - 'a';
		// printf("\n%d\n",ch);
		ch = ((ch + k2) * k1) % 26 + 'a';
		printf("%c",ch);
	}
	printf("\n");
}

void encrypt(char *str, int k1, int k2)
{
	int i;
	char ch;
	char encrypted_string[strlen(str)];
	printf("\nEncrypted string:");

	for(i=0;i<strlen(str);i++)
	{
		ch = tolower(str[i]) - 'a';	
		// printf("%d\n",ch);
		ch = (ch * k1 + k2) % 26 + 'a';
		printf("%c",ch);
		encrypted_string[i] = ch;
	}

	decrypt(encrypted_string,k1,k2);
}

void main()
{
	int k1,k2;
	char *input;
	int val = 0;

	printf("Enter string to be encrypted: ");
	scanf("%s",input);

	while(!val)
	{
		printf("\nEnter key 1: ");
		scanf("%d",&k1);	
		if(k1 > 26)
		{
			val = gcd(26,k1);	
		}
		else
		{
			val = gcd(k1,26);
		}

		if(val != 1)
		{
			printf("\nInverse does not exist. Enter another key.");
		}
	}
	
	printf("\nEnter key 2: ");
	scanf("%d",&k2);

	encrypt(input,k1,k2);
}