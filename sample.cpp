#include<iostream>
#include<stdlib.h>
#include<cstdlib>
#include<fstream>
using namespace std;

void insertionSort(int a[],int n)
{
    int i,j,key;
    for(j=1;j<=n-1;j++)
    {
        key=a[j];
        i=j-1;
        while(i>=0 && a[i]>key)
        {
            a[i+1]=a[i];
            i--;
        }
        a[i+1]=key;
    }

}

void Merge(int a[],int p,int q,int r)
{
    int n1=q-p+1;
    int n2=r-q;
    int *l,*v;
    l=new int[r];
    v=new int[r];
    int j=0,k=0;
    for(int i=p;i<=r;i++)
    {
        if(i<=q)
        {
        l[j]=a[i];
        j++;
        }
        else
        {
            v[k]=a[i];
            k++;
        }
    }
    l[j]=999999;
    v[k]=999999;
    j=k=0;
    for(int i=p;i<=r;i++)
    {
       if(l[j]<=v[k])
       {
          a[i]=l[j];
          j++;
       }
       else
       {
        a[i]=v[k];
        k++;
       }
    }
    
}

void MergeSort(int a[],int p,int r)
{
    int q;
    if(p>=r)
    {
        return;
    }
    else
    {
        q=(p+r)/2;
        MergeSort(a,p,q);
        MergeSort(a,(q+1),r);
        Merge(a,p,q,r);
    }
}

int partition(int a[],int s,int e)
{
    int key=a[e];
    int i=s-1;
    for(int j=s;j<=e;j++)
    {
        if(a[j]<=key)
        {
            i++;
            swap(a[i],a[j]);
        }
        
    }
    return i;
}

void QuickSort(int a[],int s,int e)
{
    int m;
    if(s>=e)
    {
        return ;
    }

    m=partition(a,s,e);
    QuickSort(a,s,(m-1));
    QuickSort(a,(m+1),e);

}

void MCSA(int a[],int p,int m,int r)
{
    int lmax,lsum,sum,i,rmax,rsum;
    lsum=a[m];
    lmax=m;
    sum=a[m];
   for(int i=m-1;i>=p;i--)
    {
        sum=sum+a[i];
        if(sum>lsum)
        {
            lsum=sum;
            lmax=i;
        }
    }
    rsum=a[m+1];
    rmax=m+1;
    sum=a[m+1];
    for(int i=(m+2);i<=r;i++)
    {
        sum=sum+a[i];
        if(sum>rsum)
        {
            rsum=sum;
            rmax=i;
        }
    }
   
}

void MSA(int a[],int p,int r)
{
  int m;
  if(p>=r)
  {
    return;
  }
  else
  {
    m=(p+r)/2;
    //sa1=MSA(a,p,m);
    //sa2=MSA(a,(m+1),r);
    //MCSA(a,p,m,r);
  }
}

/*subarrray bf;
bf.sum=a[1];
bf.s=1;
bf.e=1;
for(int i=1;i<=n;i++)
{
    for(int j=i;j<=n;j++)
    {
        sum=0;
        for(int k=i;k<=j;k++)
        {
            sum=sum+a[k];
        }
        if(sum>bf.sum)
        {
            bf.sum=sum;
            bf.e=j;
            bf.s=i;
        }
    }
}

for(int i=1;i<=n;i++)
{
    sum=0;
    for(int ji;j<=n;j++)
    {
        sum=sum+a[j];
        if(sum>bf.sum)
        {
            bf.sum=sum;
            bf.s=i;
            bf.e=j;
        }
    }
}
*/

/*
int MaxHeapify(int a[],int n,int i)
{
    int l=(2*i)+1;
    int r=2*i+2;
    int m=i;
    if(l<=n-1 && a[l]>a[m])
    {
        m=l;
    }
    if(r<=n-1 && a[r]>a[m]
    {
        m=r;
    })
    if(m!=i)
    {
        swap(a[i],a[m]);
        MaxHeapify(a,n,m);
    }
    return i;
}

void Buildmaxheap(int a[],int n)
{
    for(int i=(n-2)/2;i>=0;i--)
    {
        maxheapify(a,n,i);
    }
}

void Heapsort(int a[],int n)
{
    BuildMaxHeap(a,n);
    while(n>1)
    {
      swap(a[0],a[n-1]);
      MaxHeapify(a,n,0);
    }
}
*/