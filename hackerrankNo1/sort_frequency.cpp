#include<stdio.h>
#include<iostream>
using namespace std;

void sort_freq(int arr[],int n,int g)
{
    int b[g],l=0;
    for(int i=1;i<=g;i++)
    {
        b[i]=0;
    }

    for(int i=1;i<=n;i++)
    {
      b[arr[i]]=b[arr[i]]+1;
    }
    for(int i=1;i<=g;i++)
    {
        cout<<"the b array:\t"<<b[i]<<endl;
    }
    for(int i=1;i<=g;i++)
    {
       int max=0,m=0;
        int j=1;
      while(j<=g)
        {
             
         if(max<b[j])
         {
         max=b[j];
         m=j;
         }
         
         j++;
        }
      for(int p=0;p<max;p++)
      {
        cout<<m<<endl;
        arr[l]=m;
        l++;
      }
      b[m]=0;
    }
   
}

int main()
{
    int n,max=0,temp;
    int *a;
    a=new int[n];
    cout<<"enter n:"<<endl;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        temp=a[i];
        if(max<temp)
        {
            max=temp;
        }
    }
    //cout<<"the max is:"<<max;
   sort_freq(a,n,max);
    for(int i=1;i<=n;i++)
    {
        //cout<<a[i]<<endl;
    }
    return 0;
}
