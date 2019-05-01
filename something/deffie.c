#include <stdio.h>
#include <stdlib.h>


unsigned long int power(unsigned long int a,unsigned  long int b , unsigned long int n);

unsigned long int power(unsigned long int a, unsigned long int b, unsigned long int n) {
    unsigned long int number = 1;
    while (b > 0){
        number *= a;
        number %= n;
        b -- ;
    }
    return number;

}

int Repeating(int arr[], int size)
{
    int i, j;
    for(i = 0; i < size; i++)
        for(j = i+1; j < size; j++)
            if(arr[i] == arr[j])
                return 0;
    return 1;
}

int Primitive_root(int n){

    // r in [1,n-1]
    // x in [0,n-2]
    // find "r" such that all values of (r ^ x ) mod n must be different

    for(int r = 1; r < n-1 ; r++){
        int a [100];
        for(int x = 0; x < n-2; x++){
            a[x] = power(r,x,n);
        }
        if (Repeating(a,n-2) == 1){
            return r;
        }
    }
}





void main(){



    /*
        primitve root - https://en.wikipedia.org/wiki/Primitive_root_modulo_n
        primitive root - https://www.geeksforgeeks.org/primitive-root-of-a-prime-number-n-modulo-n/
    */
    /*
        let,
            A - sender
            B - reciever
            both A and B have agreed
                p is public modulus
                g is primitive root of p

            A chooses a secret integer a
                A sends B => A_msg = (g ^ a) mod p
            B chooses a secret integer b
                B sends A => B_msg = (g ^ b) mod p

            A comutes s = (B_msg ^ a) mod p
            B comutes s = (A_msg ^ b) mod p

    */

    // base modulus
    int p = 23;

    // primitive root
    int g = Primitive_root(23);

    // A chooses a secret number
    srand(p) ;
    int a = rand() % 50;

    // A's msg
    int A_msg = power(g,a,p);

    // B chooses a secret number
    srand(p*g);
    int b = rand() % 80;

    // B's msg
    int B_msg = power(g,b,p);

    // A calculates secret_key
    int secret_key_a = power(B_msg, a, p);

    // B calculates secret_key
    int secret_key_b = power(A_msg, b, p);



    printf("secret_key_a %d\n",secret_key_a );
    printf("secret_key_b %d\n",secret_key_b );


}