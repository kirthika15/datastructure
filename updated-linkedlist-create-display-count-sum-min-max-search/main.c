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
//sum
int sum(struct Node *p)
{
    if(p!=NULL)
    {
        return sum(p->next)+p->data;
    }
    else
        return 0;
}
//max
int max(struct Node *p)
{
    int max=-32767;
    while(p)
    {
        if(p->data>max)
            max=p->data;
    p=p->next;
        
    }
    return max;
}
//min
int min(struct Node *p)
{
    int min=32767;
    while(p)
    {
        if(p->data<min)
            min=p->data;
    p=p->next;
        
    }
    return min;
}
/*there are two methods for search operation
1.transposition- changing the position of data that is not possible in linked list..so option 2
2.move to head- moving the node(data+pointer) to the head that is *first
we use second method ,move to head in linked list 
*/
//move to head linear search
int linearsearch(struct Node *p,int key)
{
    struct Node*q=NULL;
    while(p!=NULL)
    {
       
        if(key==p->data)
         {
            q->next=p->next;
            p->next=first;
            first=p;
            return p;
         }
         q=p;
         p=p->next;
    }
    return NULL;
}
//recursive linear search
int search(struct Node *p,int key)
{
    struct Node *q;
    if (p==NULL)
        return NULL;
    if(key==p->data)
        return p;
    return search(p->next,key);
    
}
//main
int main()
{
    struct Node *temp;
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    create(a,n);
   // display(first);
   /* printf("\ncount is:%d",count(first));
     printf("\nsum is:%d",sum(first));
     printf("\nmax is:%d",max(first));
      printf("\nmin is:%d",min(first));
      temp=linearsearch(first,5);
      if(temp!=NULL)
        printf("\nthe key %d is found",temp->data);
    else
        printf("\nkey not found");*/
     temp=search(first,5);
    if(temp!=NULL)
        printf("\nthe key %d is found",temp->data);
    else
        printf("\nkey not found");
   
    display(first);
     return 0;
}

