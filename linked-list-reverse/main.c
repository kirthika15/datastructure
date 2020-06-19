#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node *next;
}*first=NULL;
//create
void create(int a[],int n)
{
    int i;
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
   // printf("the elements are:");
    if(p!=NULL)
    {
     printf("%d",p->data);
    display(p->next);
    //p=p->next;
    }
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
//reversing with arrays
int reverse1(struct Node *p)
{
    int *A,i=0;
    struct Node *q=p;
    //we dont know the size of an array so we use malloc dynamic memory allocation
    A=(int *)malloc(sizeof(int) * count(p));
    
    while(q!=NULL)
    {
        A[i]=q->data;
        q=q->next;
        i++;
    }
    q=p;
    i--;
    while(q!=NULL)
    {
        q->data=A[i];
        q=q->next;
        i--;
    }   
}

//reversing with sliding pointers
int reverse2(struct Node *p)
{
    struct Node *q=NULL,*r=NULL;
    while(p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
}
//reversing using recursion
void reverse3(struct Node *q,struct Node *p)
{
    if(p)
    {
        reverse3(p,p->next);
        p->next=q;
    }
    else
     first=q;
}
int main()
{
    int a[]={10,20,30,40,50};
    create(a,5);
    reverse3(NULL,first);
    display(first);
}