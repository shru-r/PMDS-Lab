/*
Experiment 7 on Linked List implementation of Stack (postfix expression evaluation
Name: Shruti Rampure
Roll no: 48
batch : D3
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct postfix /* structure to store the numbers in a stack */
{
    int n;
    struct postfix* next; /* self referencing structure */
};
struct postfix* top; /* points to the top of the stack */

int count =0;
void push(int number); /* function to push an element in the stack on top*/
int pop(); /* function to remove an element from the top of a stack*/

int main()
{
    top=NULL;
    char pf[100]; /*to  store the postfix string input by user*/
    int a;
    int op1; /* operand 1 */
    int op2; /* operand 2 */
    int val=0;
    printf("enter the postfix string\n");
    scanf("%s",pf); /* taking input from user */
    int len=strlen(pf);
    for(int i=0; i<len; i++)
    {
        if(pf[i]>='0' && pf[i]<='9') /*checks whether character is a number*/
        {
            a=(int)(pf[i])-48; /* if number found, push it onto the stack*/
            push(a);
        }
        else
        {
            switch(pf[i]) /* checking for operators*/
            {
                case '/': /*division*/
                        op2=pop(); /* removing the top 2 elements from the stack*/
                        op1=pop();
                        val=op1/op2; /* performing the operation on them*/
                        push(val);
                        break;
                case '*': /*multiplication*/
                        op2=pop();
                        op1=pop();
                        val=op1*op2;
                        push(val);
                        break;
                case '+': /*addition*/
                        op2=pop();
                        op1=pop();
                        val=op1+op2;
                        push(val);
                        break;
                case '-': /*subtraction*/
                        op2=pop();
                        op1=pop();
                        val=op1-op2;
                        push(val);
                        break;
            }
        }
    }
    if(top!=NULL) /* to display the final value of the evaluation*/
    {
        printf("\nThe above postfix string evaluates to: \n");
        printf("%d\n",top->n);
    }
    return 0;
}

void push(int number)
{
    struct postfix* temp; /*temporary pointer to go through the whole stack*/
    if (top == NULL) /* if stack is empty */
    {
        top =(struct postfix*)(malloc(1*sizeof(struct postfix))); /* assigning memory */
        top->n=number;
        top->next=NULL;
    }
    else /* if there are already elements in the stack*/
    {
        temp =(struct postfix*)malloc(1*sizeof(struct postfix)); /* assigning memory */
        temp->n=number;
        temp->next=top;
        top = temp; /*adds the element on top of the stack */
    }
    count++;
}

int pop()
{
    struct postfix* top1; /* to temporarily store the top element of the stack */
    top1=top;
    int num=top->n;
    top=top1->next;
    free(top1); /* removes the topmost element from the stack*/
    count--;
    return(num); /*returns the value of the topmost element*/
}

/*OUTPUT:-

enter the postfix string
543+*7/9-

The above postfix string evaluates to:
-4
*/
