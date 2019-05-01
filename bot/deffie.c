#include<stdio.h>
#include<math.h>
void main()
{
    int p, g;           //P should be prime number and G should be primitive root of p like 23,5
    int aliceprivate, bobprivate, alicepublic, bobpublic, sharedkeyalice, sharedkeybob;
    
    printf("Enter the P and G value: ");
    scanf("%d %d", &p, &g);
    
    printf("\nEnter the private key Alice: ");
    scanf("%d", &aliceprivate);
    printf("\nEnter the private key Bob: ");
    scanf("%d", &bobprivate);
    
    alicepublic = (((long long int)pow(g, aliceprivate))%p);         //g^privatekey mod p
    printf("\npublic key of Alice is: %d\t", alicepublic);
    
    bobpublic = (((long long int)pow(g, bobprivate))%p);            //g^privatekey mod p
    printf("public key of Bob is: %d\n", bobpublic);
    
    sharedkeyalice = (((long long int)pow(bobpublic, aliceprivate))%p);         //PublicOfBob ^ PrivateOfAlice mod p
    sharedkeybob = (((long long int)pow(alicepublic, bobprivate))%p);           //PublicOfAlice ^ PrivateOfBob mod p
    
    if(sharedkeybob == sharedkeyalice)
        printf("%d is shared key between Alice and Bob",sharedkeyalice);
    else
        printf("Its is not a shared key");
}