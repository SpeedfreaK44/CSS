#include <stdio.h>
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
int power(int base,int exponent)
{
	long long result=1;
	while(exponent!=0)
	{
		result*=base;
		exponent--;
	}
	return (result);
}

void main()
{
	int p,q,phi,n;
	int e,d;
	int plaintext;
	int P,D;

	printf("Enter two prime nos:\n");
	scanf("%d %d",&p,&q);

	printf("Enter a number to be encrypted and decrypted:\n");
	scanf("%d",&plaintext);
	n=p*q;
	phi=(p-1)*(q-1); //Phi Of n
	printf("Phi of n:%d\n",phi);

	// Calculating the public key such that its gcd with phi is 1
	for (int i = 2; i < phi; i++)
	{
		if(phi%i!=0)
		{
			printf("Public Key:%d\n",i);
			e=i;
			break;
		}
	}

	d=modInverse(e,phi); //Calculating private key 
	printf("Private Key:%d",d);
	//Encrypting the plaintext
	P=power(plaintext,e);
	P=P%n;
	printf("Encrypted value:%d\n",P);

	//Decrypting the plaintext
	D=power(P,d);
	D=D%n;
	printf("Decrypted value:%d\n",D);
}