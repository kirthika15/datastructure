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
//remove duplication
int duplicate(struct Node *p)
{
    struct Node *q=p->next;
    //p=first;
   // q=first->next;
    while(q!=NULL)
  {
        
    if(p->data!=q->data)
    {
        p=q;
        q=q->next;
    }
    else
    {
        p->next=q->next;
        free(q);
        q=p->next;
    }
  }
}
int main()
{
    int a[]={5,5,3,3,1,1,9};
    create(a,7);
    display(first);
    duplicate(first);
    printf("\n\n");
    display(first);
    return 0;
}












