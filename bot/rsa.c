#include<stdio.h>
#include<stdlib.h>
void main()
{
	int p=61,q=53;					//Select 2 prime numbers 
	int n=p*q;						
	int phi=(p-1)*(q-1);       
	printf("The value of phi = %d\n", phi);
	
	int e;
	for(int i = 2; i<phi; i++)
	{
	    if(phi % i != 0)
	    {
	        e=i;
	        break;
	    }
	}
	printf("The Value of E is %d\n",e);
	
	int k = rand()%e;                        //for some integers calculation k < e
	int d = (1 + (k*phi))/e;
	printf("The Value of D is %d\n",d);
		
	int input=89;					
	printf("The Input Text is %d\n",input);
	
	int c = (input^d)%n;
	printf("ENcrypted text is %d\n",c);		
	
	int plain = (c^d)%n;
	printf("Decryption is %d\n",plain);	
}
