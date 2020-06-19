#include <stdio.h>
#include <stdlib.h>
struct Node
{
 int data;
 struct Node *next;
}*first=NULL;
void create(int A[],int n)
{
 int i;
 struct Node *t,*last;
 first=(struct Node *)malloc(sizeof(struct Node));
 first->data=A[0];
 first->next=NULL;
 last=first;

 for(i=1;i<n;i++)
 {
 t=(struct Node*)malloc(sizeof(struct Node));
 t->data=A[i];
 t->next=NULL;
 last->next=t;
 last=t;
 }
}
void Display(struct Node *p)
{
 while(p!=NULL)
 {
 printf("%d ",p->data);
 p=p->next;
 }
}
void RDisplay(struct Node *p)
{
 if(p!=NULL)
 {
 RDisplay(p->next);
 printf("%d ",p->data);

 }
}
//count
int count(struct Node *p)
{
    int c=0;
    while(p)
    {
    c=c+1;
    p=p->next;
    }
    printf("\n %d",c);
}
//recursion in count
int Rcount(struct Node *p)
{
    if(p!=NULL)
        return Rcount(p->next)+1;
     else
        return 0;
    }
//add
int add(struct Node *p)
{
    if(p==0)
        return 0;
    else
        return add(p->next)+p->data;
     
}
int main()
{
 struct Node *temp;
 //int A[]={3,5,7,10,25,8,32,2};
 int n;
 scanf("%d",&n);
 int A[n];
 for(int i=0;i<n;i++)
 {
      scanf("%d",&A[i]);

 }
 create(A,n);

 //Display(first);
 
 count(first);
// printf("\n Rcount: \t %d",Rcount(first));
 // printf("\n Sum: \t %d",add(first));

 return 0;
}
