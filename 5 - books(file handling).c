/* Experiment 8 based on Files
Name: Shruti Rampure
Roll no: 48
Class: FE Comps
Batch: D3
Problem 2 :  publishing company holds in a file details of all books they publish. However, in future, they wish to maintain two distinct files (i) paperbacks (ii) hardbacks. Write a program which reads a file containing details of both paperback and hardback books and creates two files as specified above. Assume that the first character in each input record indicates if the book is paperback(p) or hardback(h) or both(b).
*/
#include <stdio.h>
#include <string.h>

struct f /* declaring a structure to store the book details */
{
        char book[50]; /* declaring a string to store book's name */
        char author[50]; /* declaring a string to store author's name */
        int price; /* declaring an integer to store price of the book */
};
        
void main() //start
{       
        struct f b[20]; /* creating a structure of struct f type */
        int i=0;
        FILE *fp; /* file pointer to the records file */
        FILE *p; /* file pointer to the paperback file */ 
        FILE *h; /* file pointer to the hardback file */
        fp = fopen("record.txt","r"); /* opens the record file in read mode to read all the records */
        p = fopen("paperback.txt","w"); /* opens the paperback file in write mode to print the records of paperback books */
        h = fopen("hardback.txt","w"); /* opens the hardback file in write mode to print the records of hardback books */

        while(!feof(fp)) /* reads the record file till the end */
        {
                fscanf(fp,"%s%s%d",b[i].book,b[i].author,&b[i].price); /* this reads the bookname, author name and price and stores it in the corresponding elements in the struct b */
                printf("%s\t%s\t%d\n",b[i].book,b[i].author,b[i].price); /* this prints all the elements of the struct */
                ++i;
        }

        int j; // loop variable
        char s[50], t[50]; /* declaring strings */
        int q;
        fprintf(p,"BOOK-NAME\tAUTHORNAME\tPRICE\n"); /* to print the headers of the table */
        fprintf(h,"BOOK-NAME\tAUTHORNAME\tPRICE\n");

        for(int j=0; j<i; j++) /* to access all the elements of the struct */
        {
                strcpy(s,b[j].book); /* string s stores the book name */
                strcpy(t,b[j].author); /* string t stores the author name */
                q = b[j].price; /* q stores the book price */
		     int l = strlen(s); 

                if(s[0]=='p') 
                { /*if first letter is p, book is paperback*/
                      for(int k=0; k<l-1; k++)
				{
					s[k]=s[k+1];
					/* this loop deletes the first letter p from the string of the book name */
				}
				s[l-1]='\0';
				fprintf(p,"%s \t\t %s \t\t %d\n",s,t,b[j].price); /* this prints all the paperback book details in the paperback.txt file */
                }

                else if(s[0]=='h')
                { /*if first letter is h, book is hardback*/
			     for(int k=0; k<l-1; k++)
			     {
					s[k]=s[k+1];
					/* this loop deletes the first letter h from the string of the book name */
			     }
			     s[l-1]='\0';
                     fprintf(h,"%s \t\t %s \t\t %d\n",s,t,b[j].price); /* this prints all the hardback book details in the hardback.txt file */
                }

                else if(s[0]=='b')
			{
				 /*if first letter is b, book is both paperback and hardback*/
			     for(int k=0; k<l-1; k++)
			     {
					s[k]=s[k+1];
					/* this loop deletes the first letter b from the string of the book name */
			     }
			     s[l-1]='\0';
                     fprintf(h,"%s \t\t %s \t\t %d\n",s,t,b[j].price); /* this prints all the book details in the hardback.txt file */
				fprintf(p,"%s \t\t %s \t\t %d\n",s,t,b[j].price); /* this prints all the book details in the paperback.txt file */
			}

        }  //end of outermost for loop
        fclose(fp); /* this closes the record.txt file */
        fclose(p); /* this closes the paperback.txt file */
        fclose(h); /* this closes the hardback.txt file */ 
} // end of main
                
/* record.txt file :-
hOrigin DanBrown 400
pMonsoon RKaplan 200
hNancyDrew CKeene 150
bEmma JAusten 300
bPaperTowns JGreene 250
pFamousFive EBlyton 200
hSapiens YHarari 350
p1984 GOrwell 400
*/

/* Output :-
student@CC-Lab-007-U01:~$ cd Desktop
student@CC-Lab-007-U01:~/Desktop$ gcc file.c
student@CC-Lab-007-U01:~/Desktop$ ./a.out
hOrigin		DanBrown 400
pMonsoon		RKaplan  200
hNancyDrew		CKeene   150
bEmma   		JAusten  300
bPaperTowns	JGreene  250
pFamousFive	EBlyton  200
hSapiens		YHarari  350
p1984			GOrwell  400
*/

/* paperback.txt file :-
BOOK-NAME		AUTHORNAME		PRICE
Monsoon		RKaplan		 200
Emma 		 	JAusten		 300
PaperTowns		JGreene 		 250
FamousFive		EBlyton 		 200
1984 		 	GOrwell 		 400
*/

/* hardback.txt file :-
BOOK-NAME		AUTHORNAME		PRICE
Origin		DanBrown 		 400
NancyDrew		CKeene 		 150
Emma			JAusten 		 300
PaperTowns		JGreene 		 250
Sapiens		YHarari 		 350
*/



