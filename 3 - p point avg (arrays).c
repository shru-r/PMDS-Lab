/*
NAME: SHREYA OAK
ROLL NO.39
BATCH: D3
BRANCH: COMPUTER
EXPERIMENT 4
QUESTION 5.
 Write a program which reads a pair of positive integers P and N followed by N number X​ 1 ​ ,
X​ 2 ,............,
X​ N . ​ After having read X​ i​ (i >=P) the program should output the average of X​ i-P+1​ ,
............, X​ i , ​ thus producing the P-point moving average of the data items.
*/

#include<stdio.h>
void avg(int array[],  int, int);
void main()
{
	int p,n;				/*declaring it as integer*/
	
	printf("enter p\n");
	scanf("%d",&p);				/*read the value of p*/
	printf("enter n\n");
	scanf("%d",&n);				/*read the value of n*/
	int array[n];
	
	for(int i=0;i<n;i++)			/*for loop to store elements of array*/
	{
		printf("enter element ");
		scanf("%d",&array[i]);
	}

	
	avg(array,p,n);				/*function call*/

}

void avg(int array[],int p, int n)
{	float average=1;				/*assigning variable average as 1*/
	
	for(int i=p-1;i<n;i++)				/*for loop increment i*/
	{       float sum=0;
		for(int j=i-p+1;j<=i;j++)		/*for loop to find the 'p' elements*/
		{
			sum=sum+array[j];	 	/*sum of 'p' elements*/
		}
		float average=sum/p;			/*average of 'p' elements*/
		printf("Average for i=%d is %f",i,average);		/*printing the average of 'p' elements*/
		printf("\n");
	}

}
/*
OUTPUT:
student@CC-Lab-007-U13:~/Desktop/shreya$ gcc avg.c
student@CC-Lab-007-U13:~/Desktop/shreya$ ./a.out
enter p
3
enter n
6
enter element 5
enter element 6
enter element 7
enter element 3
enter element 4
enter element 1
Average for i=2 is 6.000000
Average for i=3 is 5.333333
Average for i=4 is 4.666667
Average for i=5 is 2.666667

student@CC-Lab-007-U13:~/Desktop/shreya$ gcc avg.c
student@CC-Lab-007-U13:~/Desktop/shreya$ ./a.out
enter p
2
enter n
4
enter element 2
enter element 3
enter element 4
enter element 5
Average for i=1 is 2.500000
Average for i=2 is 3.500000
Average for i=3 is 4.500000

*/







