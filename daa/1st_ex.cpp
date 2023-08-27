#include<iostream>
#include<cstdlib>
#include<fstream>
#include<stdlib.h>
int cf;
int count;
using namespace std;
int InsertionSort(int a[],int n)
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
        count++;    
}
a[i+1]=key;
count++;
}
return count;
}

void reverse_insertion(int arr[],int n)
{
     int i,j,key;          
for(j=1;j<=n-1;j++)
{
key=arr[j];
        i=j-1;
        while(i>=0 && arr[i]<key)
        {
        arr[i+1]=arr[i];
        i--;      
}
arr[i+1]=key;
}
    //return count;
}

int merge(int a[],int p,int q,int r)
{
int i,j,k,n1,n2;
n1=q-p+1;
n2=r-q;
int n=r+1;
//int l[9999],v[9999];
int *l,*v;
l=new int[n];
v=new int[n];
//int l[10000],v[10000];
j=k=0;
for(i=p;i<=r;i++)
{
count++;
if(i<=q)
{
l[j]=a[i];
j++;
//cout<<l[j]<<endl;
}
else
{
v[k]=a[i];
k++;
//cout<<v[k]<<endl;
}
}
l[j]=9999999;
v[k]=9999999;
j=k=0;
for(i=p;i<=r;i++)
{
count++;
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
return count;
}

int MergeSort(int a[],int p,int r)
{
int q;

if(p>=r)
{
return p;
}
 cf++;
q=(p+r)/2;
//cout<<q<<endl;
MergeSort(a,p,q);
MergeSort(a,(q+1),r);
count=merge(a,p,q,r);
//cout<<cf<<endl;

return count+cf;
}

int main()
{
ofstream fout;
ifstream fin;
int n,c;
int *a;
cin>>n;
a=new int[n];
fout.open("in.txt");
for(int i=0;i<n;i++)
{
fout<<(rand()%n)<<"\t";
}
fout.close();
fin.open("in.txt");
for(int i=0;i<n;i++)
{
fin>>a[i];
}
fin.close();
c=InsertionSort(a,n);
c=InsertionSort(a,n);
fout.open("insertionout.txt");
for(int i=0;i<n;i++)
{
fout<<a[i]<<"\t";

}
fout.close();
cout<<"the time for insertion sort is :"<<c<<endl;
count=0;
fin.open("in.txt");
for(int i=0;i<n;i++)
{
fin>>a[i];
}
fin.close();
c=MergeSort(a,0,n-1);
fout.open("mergesortout.txt");
for(int i=0;i<n;i++)
{
fout<<a[i]<<"\t";
}
fout.close();
cout<<"the time for merge sort is :"<<c<<endl;
cout<<".."<<endl;
count=0;
fin.open("insertionout.txt");
for(int i=0;i<n;i++)
{
fin>>a[i];
}
fin.close();
c=InsertionSort(a,n);
fout.open("insertionout.txt");
for(int i=0;i<n;i++)
{
fout<<a[i]<<"\t";
}
fout.close();
cout<<"the time for insertion sort for ordered list is :"<<c<<endl;
count=0;
fin.open("mergesortout.txt");
for(int i=0;i<n;i++)
{
fin>>a[i];
}
fin.close();
//c=0;
cf=0;
c=MergeSort(a,0,n-1);
fout.open("mergesortout.txt");
for(int i=0;i<n;i++)
{
fout<<a[i]<<"\t";
}
fout.close();
cout<<"the time for ordered list merge sort is :"<<c<<endl;
cout<<".."<<endl;
count=0;
fin.open("insertionout.txt");
for(int i=0;i<n;i++)
{
fin>>a[i];
}
fin.close();
reverse_insertion(a,n);
fout.open("reverse_desc.txt");
for(int i=0;i<n;i++)
{
fout<<a[i]<<"\t";
}
fout.close();

fin.open("reverse_desc.txt");
for(int i=0;i<n;i++)
{
fin>>a[i];
}
fin.close();
c=InsertionSort(a,n);
fout.open("insertionout.txt");
for(int i=0;i<n;i++)
{
fout<<a[i]<<"\t";
}
fout.close();
cout<<"the time for insertion sort for reverse list is :"<<c<<endl;
count=0;
fin.open("reverse_desc.txt");
for(int i=0;i<n;i++)
{
fin>>a[i];
}
fin.close();
//c=0;
cf=0;
c=MergeSort(a,0,n-1);
fout.open("mergesortout.txt");
for(int i=0;i<n;i++)
{
fout<<a[i]<<"\t";
}
fout.close();
cout<<"the time for merge sort reverse list is :"<<c<<endl;
cout<<".."<<endl;
count=0;
return 0;
}
//082830091044