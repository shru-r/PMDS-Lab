/* PMDS Experiment 2
Name: Shruti Rampure
Roll no: 48
Class: FE Comps
Batch: D3
problem statement : Write a function which takes as parameters two positive integers and returns TRUE if the numbers are amicable and FALSE otherwise. A pair of numbers is said to be amicable if the sum of the divisors of each of the numbers (excluding the no. itself) is equal to the other number. Ex. 1184 and 1210 are amicable.
*/
#include <stdio.h>
int factors(int); /* declaring the function to calculate sum of factors */
void main() //start of main function
{
	int a, b;
	printf("enter the 2 numbers\n");
	scanf("%d",&a); // inputing the 2 numbers
	scanf("%d",&b);
	int sum1=factors(a); /* calling function factors and passing parameter as a */
	int sum2=factors(b);
	if (sum1==b && sum2==a) //condition of amicable numbers
	{
		printf("%d and %d are amicable numbers\n",a,b);
	}
	else
	{
		printf("%d and %d are not amicable numbers",a,b);	
	}
}
int factors(int n)
{
	int sum=0; //to store the sum of factors
	for(int i=1; i<n; i++) //for loop to check for factors
	{
		if ((n%i)==0) //checks whether i is a factor of n
		{
			sum=sum+i; // adds i to the sum
		}
	}
	return(sum); // returns the sum of factors
}
/*OUTPUT
student@CC-Lab-007-U07:~$ cd Desktop
student@CC-Lab-007-U07:~/Desktop$ gcc amicable.c
student@CC-Lab-007-U07:~/Desktop$ ./a.out
enter the 2 numbers
220
284
220 and 284 are amicable numbers
*/
