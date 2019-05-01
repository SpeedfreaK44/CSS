#include<stdio.h>
void main()
{
    char msg[5];
    printf("enter the character: ");
    gets(msg);
    printf("message is = %s",msg);
}


/*
output1: enter the character: viraj
		   message is = viraj


output2:  enter the character: virajdoshi
		  *** stack smashing detected ***: /home/a.out terminated
		  message is = virajdoshiAborted
*/