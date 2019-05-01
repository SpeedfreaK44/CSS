#include<stdio.h>
#include<stdint.h>
int power(int base, int exponent)
{
	int result=1;
	while(exponent!=0)
	{
		result*=base;
		exponent--;
	}
	return (result);
}
void main()
{
	int q; //prime number is must
	int alpha;
	int Xa=8,Xb=4; //Xa is the private key of A & Xb is the private key of B.
	int Ya,Yb; //Ya and Yb is the public key of A & B respectively.
	int Ka,Kb; //Ka and Kb are used for the key generation of A & B.
	int ya,yb,ka,kb;
	int x,y=1;
	int i,j,k; 
	uint8_t table[q];

	printf("Enter a prime number:");
	scanf("%d",&q);

	//finding alpha, such that its should be a primitive root of 'q'.
	for (i = 2; i < q; i++)
	{
		x=1;
		for(k=0;k<q;k++)
		{
			table[k]=0;
		}
		for(j=2;j<q;j++)
		{
			x=(y*i)%q;
			if (table[x]==1)
			{
				goto a;
			}
			else
			{
				table[x]=1;
				y=x;
			}
		}
		
		if(j==q)
		{
			alpha = i;
			break;
		}
		a:continue;
	}
	printf("Alpha:%d\n",alpha);
	
	//Calculating the public key of A & B
	ya=power(alpha,Xa);
	Ya=ya%q;

	yb=power(alpha,Xb);
	Yb=yb%q;
	
	printf("Private Key of A:%d\nPrivate Key of B:%d\n",Xa,Xb);
	printf("Public Key of A:%d\nPublic Key of B:%d\n",Ya,Yb);

	//Key Generation
	ka=power(Yb,Xa);
	Ka=ka%q;

	kb=power(Ya,Xb);
	Kb=kb%q;

	printf("Key of A:%d\nKey of B:%d",Ka,Kb);
}