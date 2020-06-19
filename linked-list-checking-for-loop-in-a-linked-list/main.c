#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node *next;
}*first=NULL;
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
int display(struct Node *p)
{
    if(p!=NULL)
    {
        printf("%d",p->data);
        display(p->next);
    }
}
int isLoop(struct Node *f)
{
    struct Node *p,*q;
    p=q=f;
    do
    {
        p=p->next;
        q=q->next;
        q=q?q->next:q;
    }while(p && q && p!=q);
    
    if(p==q)
        return 1;
    else
        return 0;
}

int main()
{
    struct Node *t1,*t2;
    int a[]={4,5,6,7,8};
    create1(a,5);
    display(first);
    t1=first->next->next;
    t2=first->next->next->next->next;
    t2->next=t1;
    printf("\n%d",isLoop(first));
    return 0;
}