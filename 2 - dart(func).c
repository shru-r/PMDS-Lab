/*
NAME: SHREYA OAK
ROLL NO.39
BRANCH: COMPUTER
EXPERIMENT-2
QUESTION.3

On a conventional dartboard, a single dart may score any integer i in the range 1 to 20 also
2*i, 3*i, 25 or 50.
a. Write a procedure which takes a single parameter N and determines whether or not N can
be scored with 3 or fewer darts.
b. Modify your procedure so that it outputs the minimum no. of darts needed to score N.*/

#include <stdio.h>
int min(int);
void main()
{
     int n,minimum;
     printf("enter no.\n");
     scanf("%d",&n);                       /*input*/
     minimum=min(n);                      /*function call*/
     printf("minimum no. of darts is %d\n",minimum); 
     if(minimum<=3 && minimum>0)                            /* to check whether its less than 3*/
     {
        printf("N can be scored with 3 or fewer darts\n");
     }
     else
        printf("N can be scored with more than 3 darts\n");
         
}

int min(int N)
{
        int i,n;
        int z=N/60;           /*to check the minimum for any number*/
       
        n=N-(z*60);
        if(N==167 || N==161)          /*exceptions*/
        {
                return(3);
        }
        else if(n==0)               /*checking is its a multiple of 60*/
        {
                return(z);     
        
        }
        else if(n==25 || n==50 || n%3==0 || (n>=1 && n<=20) || (n<=40 && n%2==0))  /*q's condition*/
        {
                 return(z+1);
        }   
        else
        {
                return(z+2);
        }
}    


/*
OUTPUT:
shreya@shreya-Inspiron-3537:~$ cd Desktop
shreya@shreya-Inspiron-3537:~/Desktop$ cd C
shreya@shreya-Inspiron-3537:~/Desktop/C$ gcc dart.c
shreya@shreya-Inspiron-3537:~/Desktop/C$ ./a.out
enter no.
104
minimum no. of darts is 3
N can be scored with 3 or fewer darts
shreya@shreya-Inspiron-3537:~/Desktop/C$ ./a.out
enter no.
240
minimum no. of darts is 4
N can be scored with more than 3 darts
shreya@shreya-Inspiron-3537:~/Desktop/C$ ./a.out
enter no.
20
minimum no. of darts is 1
N can be scored with 3 or fewer darts

                 
        
        
        

*/
