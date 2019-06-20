#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct node
{
char data;
struct node* next;
}node;
node* top=NULL;
node* push(char a,node* top);
node* pop(node* top);
node* display(node* top);
void main()
{
int i;
char s[50];
char a;
clrscr();
printf("Enter the string");
scanf("%s",s);
//n=strlen(s);
for(i=0;i<s[i]!='\0';i++)
{
if(s[i]=='(')
{
a=s[i];
top=push(a,top);
printf("\n");
top=display(top);
printf("\n");
}
else if(s[i]==')')
{
top=pop(top);
}
}
if(top==NULL)
{
printf("Right");
}
else
{
printf("IMPROPER");
}
getch();
}
node* push(char a,node* head)
{
node* p=NULL;
node* q=NULL;
p=(node*)malloc(sizeof(node));
p->data=a;
p->next=NULL;
if(top==NULL)
{
top=p;
}
else
{
p->next=top;
top=p;
}
return top;
}
node* pop(node* top)
{
node* q=NULL;
node* p=NULL;
if(top==NULL)
{
printf("wrong");
}
else
{
p=top;
top=top->next;
free(p);
}
return top;
}
node* display(node* top)
{
node* p=NULL;
p=top;
while(p!=NULL)
{
printf("%c",p->data);
p=p->next;
}
return top;
}


