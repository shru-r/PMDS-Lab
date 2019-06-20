/* Experiment 4: Structures
Name : Shruti Rampure
Class : FE Comps
Batch : D3
Roll no : 48
prob 4 - An airline reservation system maintains records for possible flights consisting of
STARTING POINT 3 character code
DESTINATION 3 character code
STARTING TIME integer on scale 0001 – 2400
ARRIVAL TIME integer on scale 0001 – 2400
SEATS positive integer in suitable range.
Your program is to read 20 such records followed by queries of the form STARTINGPOINT – DESTINATION, one to a line. For each query find whether there is a possible flight with a seat available; if so reduce the number of eats by one and print out the flight details (or an apology).
*/

#include <stdio.h>
#include <string.h>
struct f /* creating a struct f datatype for the database of flights*/
{
	char start[4]; /* this string stores the starting place of the flight */
	char destn[4]; /* this string stores the destination of the flight */
	int stime; /* this int variable stores the starting time of the flight */
	int atime; /* this int variable stores the arrival time of the flight */
	int seats; /* this int variable stores the number of seats availabe in the flight */
};
void query(int a, struct f fl[]); //function definition
void display(int b, struct f dis[]); //function definition
void main()
{
	
	int n; /* variable to store the number of flights the user wants to store in the database */
	printf("enter number of flight which you want to store in database\n");
	scanf("%d",&n); /* takes input for n*/
	struct f flight[n]; /* creates a structure to store the database of the flights */
	for(int i=0;i<n;i++) /* loop to enter the data of the flights */
	{
		printf("enter starting point\n");
		scanf("%s",flight[i].start); /* inputs the starting place of the flight */
		printf("enter destination\n"); 
		scanf("%s",flight[i].destn); /* inputs the destination of the flight */
		printf("enter starting time\n");
		scanf("%d",&flight[i].stime); /* inputs the start time of the flight */
		printf("enter arrival time\n"); 
		scanf("%d",&flight[i].atime); /* inputs the arrival time of the flight */
		printf("enter number of seats available\n");
		scanf("%d",&flight[i].seats); /* inputs the number of seats available in the flight */
	}
	
	display(n,flight); /* calling function display and passing int n and struct f flight as parameters */
	query(n,flight); /* calling function query and passing int n and struct f flight as parameters */
} //main ends here

void display(int b, struct f dis[])
{	/* this function prints the database of flights */
	printf("the database is\n");
	printf("STARTPOINT DESTINATION STARTTIME ARRIVALTIME SEATS\n");
	for(int k=0; k<b; k++) // loop for printing the data
	{
		printf("%8s",dis[k].start);
		printf("%10s",dis[k].destn);
		printf("%12d",dis[k].stime);
		printf("%11d",dis[k].atime);
		printf("%8d",dis[k].seats);
		printf("\n");
	}
}
void query(int a, struct f q[])
{	/* this function takes queries and for each query finds whether there is a possible flight with a seat available */
	int match[a]; // array declaration
	int k, b, choice; // integer declaration 
	k = 0;
	char s[4]; /* string to store the starting point of the query */
	char d[4]; /* string to store the destination of the query */
	printf("enter the starting point of your flight\n");
	scanf("%s",s); /* inputs the query */
	printf("enter the ending point of your flight\n");
	scanf("%s",d);
	for (int j=0; j<a; j++) /* loop to check through the database */
	{
		if(strcmp(q[j].start,s)==0 && strcmp(q[j].destn,d)==0) 
		{
			/* checks if any of the flights matches the query */
			match[k]=j; /* this array stores the index numbers in the struct of the flights that match with the query */
			++k; /* keeps count of how many flights match the query */
		}
		
	}88	
	if(k!=0) /* if there are flights available */
	{
		printf("FLIGHT-NO STARTPOINT DESTINATION STARTTIME ARRIVALTIME SEATS\n");
		for (int i=0; i<k; i++)
		{
			b = match[i]; /* index number of the matching flight */
			/* prints details of the flights */
			
			printf("%5d",i+1);
			printf("%10s",q[b].start);
			printf("%12s",q[b].destn);
			printf("%12d",q[b].stime);
			printf("%11d",q[b].atime);
			printf("%9d",q[b].seats);
			printf("\n");
		}
		printf("Enter 1 to book a ticket with this flight 1, 2 to book a ticket with flight 2 and so on. Click 0 for no booking. \n");
		scanf("%d",&choice); /* stores the choice of the user if he wants to book a flight 1 or 2 or no flight */
		if(choice!=0)
		{
			b = match[choice-1]; 
			printf("You have booked a flight from %s to %s that starts at %d hours and arrives at %d hours.\n",s,d,q[b].stime,q[b].atime); // prints the flight selected
			--q[b].seats; /* reduces the number of seats on that plane if user books that flight */
		}
		
	}
	else /* if no flight is available */
	{
		printf("sorry no flights available\n");
	}
}
/* OUTPUT
student@CC-Lab-007-U01:~$ cd Desktop
student@CC-Lab-007-U01:~/Desktop$ gcc flights.c
student@CC-Lab-007-U01:~/Desktop$ ./a.out
enter number of flight which you want to store in database
5
enter starting point
mum
enter destination
goa
enter starting time
1100
enter arrival time
1600
enter number of seats available
150
enter starting point
mum
enter destination
goa
enter starting time
1300
enter arrival time
1700
enter number of seats available
110
enter starting point
mum
enter destination
del
enter starting time
1700
enter arrival time
2400
enter number of seats available
90
enter starting point
mum
enter destination
hyd
enter starting time
1200
enter arrival time
1500
enter number of seats available
180
enter starting point
mum
enter destination
goa
enter starting time
1500
enter arrival time
1900
enter number of seats available
70
the database is
STARTPOINT DESTINATION STARTTIME ARRIVALTIME SEATS
     mum       goa        1100       1600     150
     mum       goa        1300       1700     110
     mum       del        1700       2400      90
     mum       hyd        1200       1500     180
     mum       goa        1500       1900      70
enter the starting point of your flight
mum
enter the ending point of your flight
goa
FLIGHT-NO STARTPOINT DESTINATION STARTTIME ARRIVALTIME SEATS
    1       mum         goa        1100       1600      150
    2       mum         goa        1300       1700      110
    3       mum         goa        1500       1900       70
Enter 1 to book a ticket with this flight 1, 2 to book a ticket with flight 2 and so on. Click 0 for no booking.
2
You have booked a flight from mum to goa that starts at 1300 hours and arrives at 1700 hours.
*/
