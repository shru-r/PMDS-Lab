/* Name: Shruti Rampure
   Roll no: 48
   Class: FE Comps
   Batch: D3
*/
/* Problem Statement (experiment 1, problem 8):  Twin primes are consecutive odd numbers both of which are prime numbers. Write a program which inputs two positive integers A and B and outputs all the twin primes in the range A to B.*/
#include <stdio.h>
void main()
{
	int a, b, num1, num2, i, j, k;
	printf("Enter the starting value of range\n");
	scanf("%d",&a); //to input the starting value of range
	printf("Enter the ending value of range\n");
	scanf("%d",&b); //to input ending value of range

	if (a%2==0)
	{
		num1=a+1;
	}
	else
	{
		num1=a;
	}
	//this is to change the staring value of range to odd number
	
	if (b%2==0)
	{
		num2=b-1;
	}
	else
	{
		num2=b;
	}
	//this is to change the ending value of range to odd number
	
	
	i=num1; //this is to start the iterations from the starting odd number in the range

	while (i<=(num2-2)) //while loop to check all odd numbers in the range
	{
		int count1=0; // factors of the 'i'th number
		int count2=0; // factors of the 'i+2'th number
		j=2;	
		k=2;
		while (j<i) //to check if 'i'th number is prime
		{
			if(i%j==0) //to check if j is a factor of 'i'th number
			{
				count1++; //number of factors of 'i'th number increases by 1
			}
			j++;
		}
		
		while (k<i+2) //to check if 'i+2'th number is prime
		{
			if((i+2)%k==0)//to check if k is a factor of 'i+2'th number
			{
				count2++;//number of factors of 'i+2'th number increases by 1
			}
			k++;
		}
		
		if (count1==0 && count2==0) 
		//if number of factors of both 'i'th and 'i+2'th number are 0 then they are twin-prime nos
		{
			printf("%d and %d are twin prime numbers\n",i,i+2);
		}
		
		i=i+2; //to check the next odd number
	}
}
			
/*Output:
student@CC-Lab-007-U03:~/Desktop$ gcc twin-prime.c
student@CC-Lab-007-U03:~/Desktop$ ./a.out
Enter the starting value of range
3
Enter the ending value of range
40
3 and 5 are twin prime numbers
5 and 7 are twin prime numbers
11 and 13 are twin prime numbers
17 and 19 are twin prime numbers
29 and 31 are twin prime numbers
 */
