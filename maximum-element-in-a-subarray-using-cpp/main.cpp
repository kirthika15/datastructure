//https://www.geeksforgeeks.org/sliding-window-maximum-set-2/?ref=leftbar-rightbar

#include <iostream>
using namespace std;
 class maximum
 {
public:
    void pmax(int a[],int n,int k)
    {
        if(k==1)
        {
            for(int i=0;i<n;i++)
            cout<< a[i]<<" ";
            return;
        }
        //p is a variable ptr to sub arrays
        //q is a variable ptr to the array which changes its position through the array
        //t is a temp variable to hold the value of p
        int p,q,t,max;
        p=0;
        q=k-1;
        t=p;
        max=a[k-1];
        
        while(q<=n-1)
        {
            if(a[p]>max)
            max=a[p];
        
        p+=1;
        
        if(q==p & p!=n)
        {
            cout<<" max "<<max<<" q "<<q<<"\n";
            q++;
            p=++t;
            
            if(q<n)
            max=a[q];
        }
        }
    }
    
 };
 
int main()
{
    maximum m;
    int n,k;
    cin>>n;
    cin>>k;
    int a[n];
    //int n=sizeof(a)/sizeof(a[0]);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    /*for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }*/
    m.pmax(a,n,k);
    return 0;
}
/*

https://www.geeksforgeeks.org/sliding-window-maximum-set-2/?ref=leftbar-rightbar
*/