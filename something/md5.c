#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void binary(char * s, int len){
    long unsigned int i;
    // long int len = strlen(s);
    char c;
    for(i = 0; i < len; i++){
        c = *(s+i);
        for (int j = 7; j >= 0 ; j--){
            printf("%d", (c >> j)  & 1);
        }
        printf(" ");
    }
    // printf("\n");
}

int bits_to_add(int size_msg){
    if(size_msg % 512 == 448) return size_msg + 512;
    if (size_msg < 448) return 448 - size_msg;
    int more_bits = 512 - ((size_msg % 512) - 448);
    return more_bits;
}


void main(){
    char *msg = (char*)malloc(sizeof(char)*1024);
    msg = "aditya";

    int size_msg = strlen(msg)*8;

    char * output = (char *)malloc((size_msg + (bits_to_add(size_msg)) / 8) + 8); // since malloc takes bytes as input

    int character, position;
    char op_char;
    char msg_char;

    /*copy msg*/
    for(int i = size_msg - 1 ; i >= 0 ; i--){
        character = i / 8;
        position = i % 8;

        msg_char = *(msg + character);
        op_char = *(output + character);

        *(output + character) = op_char | (msg_char & (1 << position))    ;
    }
    /*add 1000_0000 */
    int extra_byte = strlen(msg);
    *(output + extra_byte) = (1 << 7);

    // add zeros
    for (int i = 0; i < (bits_to_add(size_msg)/8 - 1); i++){

        *(output + ++extra_byte) = '\0';
    }

    binary(output,(size_msg + bits_to_add(size_msg))/8);


    // add msg length 64 bits
    long long int a = size_msg;
    for(int i = 63; i >= 0; --i){
        printf("%lld", (a >> i) & 1 );
        if ( i % 8 == 0) printf(" ");
    }
    printf("\n");

}
