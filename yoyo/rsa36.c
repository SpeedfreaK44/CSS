#include<stdio.h>
#include<math.h>
#include<string.h>

//Finding the modular inverse
int modInverse(int a, int m) 
{ 
    a = a%m; 
    for(int x=1; x<m; x++)
    { 
       if((a*x) % m == 1)
       {
       	return x;
       } 
    }
} 

//Power function
int power(int base, int exponent)
{
	long long int result=1;
	while(exponent!=0)
	{
		result*=base;
		exponent--;
	}
	return (result);
}

void main()
{
	//Declaring variables
	int p=3,q=5,plaintext,encryption[8],decryption[8];
	int e,d,n,funcn;
	long long int P,D;
	char ptext[8];
	
	printf("Enter plaintext:\n");
	gets(ptext);
	n=p*q;
	printf("n:%d\n",n);
	funcn=((p-1)*(q-1)); //Phi of n
	printf("Phi of n:%d\n",funcn);

	// Calculating the public key
	for (int i = 2; i < funcn; i++)
	{
		if((int)funcn%i!=0)
		{
			printf("Public Key:%d\n",i);
			e=i;
			break;
		}
	}

	// Calculating Private Key
	d=modInverse(e,funcn);
	printf("Private key:%d\n",d);

	for (int i = 0; i < strlen(ptext); i++)
	{
		plaintext=(int)(ptext[i]);

		//Encryption
		P=power(plaintext,e);
		printf("Power value:%lld\n",P);
		int pe=(int)(P)%n;
		encryption[i]=(int)pe;
		printf("Encrypted value:%d\n",encryption[i]);

		//Decryption
		D=power(encryption[i],d);
		printf("D:%lld\n",D);
		long long int de= D%n;
		decryption[i]=(int)de;
		printf("Decrypted value:%d\n",decryption[i]);
		printf("\n");
	}
}
