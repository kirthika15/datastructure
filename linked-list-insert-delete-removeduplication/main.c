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
       display(p->next);}
}
//count
int count(struct Node *p)
{
     if(p!=NULL)
     {
         return count(p->next)+1;
     }
     else 
        return 0;
}
//insertion
int insert(struct Node *p,int pos,int x)
{
        if(pos<0||pos>count(p))
            return 0;
   struct Node *t;
   t=(struct Node *)malloc(sizeof(struct Node));
   t->data=x;
   
    if(pos==0)
    {
       
        t->next=first;
        first=t;
    }
    
    else if(pos>0)
    {
        p=first;
        for(int i=0;i<pos-1;i++)
        p=p->next;
        t->next=p->next;
        p->next=t;
        
    }
}
//inserting at the end always
int insertlast(struct Node*t,int x)
{
    struct Node *last;
     last=(struct Node *)malloc(sizeof(struct Node));

    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;
    t->next=NULL;
    if(first==NULL)
        {
            first=t;
            last=t;
        }
    else
    {
        last->next=t;
        last=t;
    }
    
}
int main()
{
    int n,pos,x;
   /* scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    create(a,n);
    display(first);
   /* printf("enter the position after which the node has to be inserted:");
    scanf("%d",&pos);*/
    printf("enter the element that has to be inserted: ");
    scanf("%d",&x);
   // insert(first,pos,x);
   insertlast(first,x);
    display(first);
   // printf("\n%d",count(first));
    

    return 0;
}





