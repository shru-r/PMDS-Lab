/* Exp 8: Queue
name : Shruti Rampure
batch : D3
roll no : 48
Consider a single queueing system for a food joint. There is a single queue of customers. The customers however, are served by three different counters. The moment a counter is free, the first customer in the queue is serviced at the counter. It is possible that at a particular time instant only 2 counters are free to serve customers, so at that point the first 2 customers are removed from the queue for servicing. Simulate this system’s behavior. Your program must:
i. Create a queue for n customers
ii. At every instant of time ask for how many counters are free(k) and then remove k customers from the queue accordingly. (Do this till all n customers are serviced. Assume: There are no new customers adding to the queue.)
iii. Display the queue contents at each instant after removing customer
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct queue /* struct to create a queue*/
{
    char cname[100]; /* stores the name of the customer */
    struct queue* next; /* self referencing structure */
};
struct queue* front; /* pointer to the front of the queue */
struct queue* rear; /* pointer to the back of the queue */

void enqueue(char name[]); /* to add at the back of the queue */
void display(struct queue* temp); /* to display the queue */
void dequeue(); /* to delete from the front of the queue */

int main()
{
    int n;
    front=NULL; /* initialising front and rear to NULL to create an empty queue */
    rear=NULL;
    printf("enter the number of customers: ");
    scanf("%d",&n); /* input the number of customers */
    char name[100];
    for(int i=0; i<n; ++i)
    {
        printf("enter customer name : ");
        scanf("%s",name); /* input name of each customer */
        enqueue(name); /* passing name to enqueue function, to add at back of the queue */
    }
    int choice=0;
    int c=0;
    printf("enter 1 to free counters: ");
    scanf("%d",&choice); /* input whether user wants to free counters */
    printf("\n");
    int counter=0; /* to store how many counters are free*/
    if (choice == 1)
    {
        do
        {
            printf("enter how many counters out of 3 are free: ");
            scanf("%d",&counter); /* input number of free counters */
            printf("\n");
            for(int j=1; j<=counter; ++j)
            {
                printf("\n%s was served at %d counter\n",(front->cname),j); /* customer at the front is served */
                dequeue(); /* removes the first customer from the queue */
            }
            n=n-counter; /* number of customers in the queue now */
            if(n!=0) /* queue is not empty */
            {
                printf("\n%d customers are left in the queue:-\n",n);
                if(front!=NULL)
                {
                    display(front); /* displays the names of the customers waiting in the queue in order */
                }
            }
            else /* queue is empty */
            {
                printf("\nAll customers have been served. \nQueue is empty now\n");
                break;
            }
            printf("\nenter 1 to free more counters or 0 to exit: ");
            scanf("%d",&c); /* inputs whether user wants to free any more counters or exit */
        }while(c==1); /* if customer wants to free more counters, repeat */
    }
    return 1;
}

void enqueue(char name[])
{
    struct queue* temp=(struct queue*)malloc(1*sizeof(struct queue)); /* allocating memory to create a node */
    if(rear==NULL && front==NULL) /* empty list */
    {
        strcpy(temp->cname,name); /* storing the customer's name in the node */
        rear=temp; /* when there is only 1 node, both front and rear are the same */
        front=rear;
    }
    else /* list is not empty */
    {
        strcpy(temp->cname,name);
        rear->next=temp; /*adds a node at the rear of the queue */
        rear=temp; /* rear is shifted to the last node */
    }
}

void dequeue()
{
    struct queue* t=(struct queue*)malloc(1*sizeof(struct queue)); /* allocating memory */
    if(front!=NULL && rear!=NULL)
    {
        if(front==rear) /* only one element in the list */
        {
            free(rear); /* delete the only element from the queue */
            free(front);
        }
        else
        {
            t=front->next;
            free(front); /* delete the first node */
            front=t; /* shift front to the next node */
        }
    }
}

void display(struct queue* temp)
{
    while(temp!=NULL) /* to traverse the whole queue */
    {
        printf("%s\n",temp->cname); /* displaying the customer name */
        temp=temp->next;
    }
}

/* OUTPUT
enter the number of customers: 8
enter customer name : Shruti
enter customer name : Anjali
enter customer name : Tanvi
enter customer name : Nehal
enter customer name : Tania
enter customer name : Deepika
enter customer name : Shreya
enter customer name : Sakshi
enter 1 to free counters: 1

enter how many counters out of 3 are free: 2


Shruti was served at 1 counter

Anjali was served at 2 counter

6 customers are left in the queue:-
Tanvi
Nehal
Tania
Deepika
Shreya
Sakshi

enter 1 to free more counters or 0 to exit: 1
enter how many counters out of 3 are free: 3


Tanvi was served at 1 counter

Nehal was served at 2 counter

Tania was served at 3 counter

3 customers are left in the queue:-
Deepika
Shreya
Sakshi

enter 1 to free more counters or 0 to exit: 1
enter how many counters out of 3 are free: 3


Deepika was served at 1 counter

Shreya was served at 2 counter

Sakshi was served at 3 counter

All customers have been served.
Queue is empty now.
*/
