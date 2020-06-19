#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node *next;
}*first=NULL,*second=NULL,*third=NULL;
//create
void create1(int a[],int n)
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
void create2(int a[],int n)
{
    int i;
    struct Node *t,*last;
    second=(struct Node *)malloc(sizeof(struct Node));
    second->data=a[0];
    second->next=NULL;
    last=second;
    
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
//concatinate
int concatinate(struct Node *p,struct Node *q)
{
     third=p;
     while(p->next!=NULL)
     {
        p=p->next;
     }
     p->next=q;
}
//merging
void merge(struct Node *p,struct Node *q)
{
    struct Node *last;
    if(p->data < q->data)
    {
        third=last=p;
        p=p->next;
        third->next=NULL;
    }
    else
    {
        third=last=q;
        q=q->next;
        third->next=NULL; 
    }
    while(p && q)
    {
        if(p->data < q->data)
        {
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;
        }
        else
         {
            last->next=q;
            last=q;
            q=q->next;
            last->next=NULL;
        }
    }
    if(p)last->next=p;
    if(q)last->next=q;
}
int main()
{
    int a[]={10,20,30,60,80};
    int b[]={15,25,35,45,55};
    create1(a,5);
    create2(b,5);
    display(first);
    printf("\ts:\t");
    display(second);
    merge(first,second);    
    printf("\nmerged linked list:\n");
    display(third);
   /* concatinate(first,second);
    printf("\nthird");
    display(third);*/
    
    
    }