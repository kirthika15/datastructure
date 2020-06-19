/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node *next;
    
}*first=NULL;

void create(int a[],int n)
{
    struct Node *t,*last;
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=a[0];
    first->next=NULL;
    last=first;
    
    for(int i=1;i<n;i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=a[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
int display(struct Node *p)
{
    if(p!=NULL){
      printf("%d \t",p->data);
       display(p->next);
        
    }
}
//count of the linked 
int count(struct Node *p)
{
     if(p!=NULL)
     {
         return count(p->next)+1;
     }
     else 
        return 0;
}

//deleting a node in given position
int delete(struct Node *p,int pos)
{
    struct Node *q=NULL;
    int x=-1;
    //to delete a node at the begining(head)
    if(pos<1||pos>count(p))
      return 0;
      
    //first node
    if(pos==1)
    {
        q=first;
        x=first->data;
        first=first->next;
        free(q);
        return x;
    }
    //for nodes from second position to last
   else if(pos>1)
    {
        for(int i=0;i<pos-1;i++)
        {
            q=p;
            p=p->next;
        }
            x=p->data;
            q->next=p->next;
            free(p);
            return x;
        
    }
    
    
}
//to check if the list is sorted or not
int isSorted(struct Node *p)
{
    int x=-32768;
    while(p!=NULL)
    {
        if(p->data<x)
         return 0;
        else
         x=p->data;
         p=p->next;
    }
    return 1;
}
int main()
{
    int pos;
    int a[]={1,2,3,5,4};
    //printf("enter a pos of node to be deleted");
    //scanf("%d",&pos);
    create(a,5);
    //display(first);
    //printf("\n%d deleted\n",delete(first,pos));
    display(first);
    if(isSorted(first))
    {
        printf("\n sorted");
        }
        else
        {
        printf("\n not sorted");
    }
    return 0;
}


