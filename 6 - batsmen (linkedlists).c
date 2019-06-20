/* name: Shruti Rampure     class: FE Comps
   roll no:48    batch:D3
problem statement: Imagine an IPL coach is maintaining the records for the all batsman in his team. The data which he needs is players name, country and his score. The coach can have 10 to 15 standby batsman. Out of this standby coach needs to identify candidate batsman which can play in the tournament. The condition for selection is that the batsman has better score than average of all standby batsman. Write a program such that coach should be able to add new batsman, remove a batsman, display all batsman, display average score and display list of batsman who qualify based on condition from list. */

#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

struct batsmen /* structure to store data of batsmen */
{
	char name[30]; /* store name of batsme */
	float runs; /* store runs of batsme */
	struct batsmen* next; /* self-referencing structure */
};

struct batsmen* nalloc(char s[], int r); /* function to allocate memory */
struct batsmen* addend(struct batsmen* head, char s[], int r); /* function to add at end of list */
void sort(struct batsmen* f, float avg); /* to sort the batsmen whose runs are above average */
void delete(struct batsmen* h, float avg); /*to delete from the list */
void display(struct batsmen* dh); /* to display a list */

void main()
{
	struct batsmen* head; /* pointer to first node of list */
	float sum=0;
	int n;
	printf("enter the number of batsmen\n");
	scanf("%d",&n);
	char bn[30]; /* to store batsmen name */
	float r;
	struct batsmen* new; 
	struct batsmen* first;
	for(int i=0; i<n; i++)
	{
		printf("enter name of the batsman : ");
		scanf("%s",bn);
		printf("enter number of runs scored by batsman : ");
		scanf("%f",&r);
		printf("\n");
		if(i==0)
		{
			head=nalloc(bn,r); /* calling function to allocate memory */
		}
		else
		{
			new=addend(head,bn,r); /* calling functions to add node at the back */
		}
		sum=sum+r; /* calculates sum of runs scored by all batsmen */
	}
	float avg=sum/n; /* average of the runs */
	display(head); /* displaying the whole list */
	printf("\n");
	printf("the average is %f\n",avg);	
	sort(head,avg);
	delete(head,avg);
}

struct batsmen* nalloc(char s[], int r)
{
	struct batsmen* p=(struct batsmen*)(malloc(sizeof(struct batsmen))); /* memory allocation */
	if (p!=NULL)
	{
		strcpy(p->name,s);
		p->runs=r;
		p->next=NULL;
	}
	return p; /* returns pointer to the node created */
}

struct batsmen* addend(struct batsmen* head, char s[], int r)
{
	struct batsmen* temp=head;
	struct batsmen* p=nalloc(s,r);
	if(p==NULL)
	{
		return head;
	}
	while(temp->next!=NULL)
	{
		temp=temp->next; /* traversing the list */
	}
	temp->next=p;
	return head; /* returns the nodes added at the back in the list */
}

void sort(struct batsmen* f, float avg)
{
	float r;
	int count=0;
	struct batsmen* new;
	struct batsmen* selected;
	printf("the selected players are\n");
	while(f!=NULL)
	{
		r=f->runs;
		if(r>=avg) /*batsmen is selected if this condition s met */
		{
			if(count==0)
			{
				selected=nalloc(f->name,r); /* to create a new list of the selected bastmen */
			}
			else
			{
				new=addend(selected,f->name,r);
			}
			++count;
		}
		f=f->next; /* traversing through the whole list */
	}
	display(selected); /* displaying the new list */
}

void delete(struct batsmen* h, float avg)
{
	struct batsmen* temp;
	temp=h;
	struct batsmen* prev;
	while(temp!=NULL) /* loop to delete */
	{
		if((temp->runs)>=avg)
		{
			if(temp==h) /* to delete head */
			{
				h=temp->next;
				free(temp);
				temp=h;
			}
			else /* to delete any node other than head */
			{
				prev->next=temp->next;
				free(temp);
				temp=prev->next;
			}
		}
		else
		{
			prev=temp; /* backup of temp node */
			temp=temp->next; /* for traversing through the whole list */
		}
	}
	printf("the new list is now\n");
	display(h); /* displaying new list after deleting all the selected players */
	
}

void display(struct batsmen* dh)
{
	while(dh!=NULL)
	{
			printf("%s\t\t%f",dh->name,dh->runs);
			printf("\n");
			dh=dh->next; /* traversing the whole list */
	}
}

/* OUTPUT:-

enter the number of batsmen
5
enter name of the batsman : yuvraj
enter number of runs scored by batsman : 80

enter name of the batsman : virat
enter number of runs scored by batsman : 120

enter name of the batsman : ab
enter number of runs scored by batsman : 70

enter name of the batsman : shikhar
enter number of runs scored by batsman : 100

enter name of the batsman : sachin
enter number of runs scored by batsman : 200

yuvraj		80.000000
virat			120.000000
ab			70.000000
shikhar		100.000000
sachin		200.000000

the average is 114.000000
the selected players are
virat			120.000000
sachin		200.000000
the new list is now
yuvraj		80.000000
ab			70.000000
shikhar		100.000000

*/
