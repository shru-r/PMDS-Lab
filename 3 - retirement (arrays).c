/* PMDS Experiment 3
Name: Shruti Rampure
Class: Fe comps
Batch: D3
Roll no: 48

problem: Write a program which reads the current year followed by N followed by a list of N employee numbers and their current ages. Produce a list showing the years in which the employees retire (become 65 years old). If more than one employee retires in given year then include them all under the same heading, for example
Year Number
1986 896743
1988 674501
     450926
If you have character arrays available then use employee names rather than number. 
*/

#include <stdio.h>
void main()
{
        int n,y;
        printf("enter the current year\n"); //inputs current year
        scanf("%d",&y);
        printf("Enter the number of employees\n"); //inputs number of employees
        scanf("%d",&n);
        int id[n]; // array for storing ids of the n employees
        int age[n]; // array for storing current ages of the employees
        int retyear[n]; // array for storing their retirement ages
        for(int i=0;i<n;i++) //to input the 2 arrays
        {
                printf("enter the employee id\n");
                scanf("%d",&id[i]); //input id number
                printf("enter the employee age\n");
                scanf("%d",&age[i]); //input age of employee
        }
        for(int i=0;i<n;i++)
        {
                retyear[i]=y+65-age[i]; //calculates the retirement years of each employee
        }
        for(int i=0;i<n-1;i++) //outer loop to perform bubble sort
        {
                for(int j=0;j<n-i-1;j++) // inner loop
                {
                        if(retyear[j]>retyear[j+1]) //sorts the retyear array in ascending order
                        {
                                int temp1=retyear[j]; // for swapping
                                retyear[j]=retyear[j+1];
                                retyear[j+1]=temp1;
                                int temp2=id[j]; // for swapping
                                id[j]=id[j+1];
                                id[j+1]=temp2;
                         }
                  }
         }
        printf("year     employee\n");
        for(int i=0;i<n;i++)
         {
            printf("%d",retyear[i]); //prints the retirement year
            printf("%9d\n",id[i]); // prints corresponding employee id
            while(retyear[i+1]==retyear[i])
            {
                printf("\t%5d\n",id[++i]); //prints id of other employees with the same retirement year
            }
               
         }
}

/*
OUTPUT:-
student@CC-Lab-007-U06:~$ cd Desktop
student@CC-Lab-007-U06:~/Desktop$ gcc retirement.c
student@CC-Lab-007-U06:~/Desktop$ ./a.out
enter the current year
2018
Enter the number of employees
4
enter the employee id
20
enter the employee age
60
enter the employee id
14
enter the employee age
45
enter the employee id
12
enter the employee age
25
enter the employee id
17
enter the employee age
60
year     employee
2023		20
		17
2038       14
2058       12

*/
