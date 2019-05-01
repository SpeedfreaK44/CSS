#include<stdio.h>
void main()
{
	int p=53,q=59;					//Select 2 prime numbers 
	int n=p*q;						
	float phi=(p-1)*(q-1);       
	printf("The value of phi = %f\n", phi);
	
	int e=3;						
	printf("The Value of E is %d\n",e);
	
	int k = 2;                        //for some integers calculation k < e
	int d = (1 + (k*phi))/e;
	printf("The Value of D is %d\n",d);
		
	int input=89;					
	printf("The Input Text is %d\n",input);
	
	int c = (input^d)%n;
	printf("ENcrypted text is %d\n",c);		
	
	int plain = (c^d)%n;
	printf("Decryption is %d\n",plain);	
}
