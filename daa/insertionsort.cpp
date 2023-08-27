#include<iostream>
#include<cstdlib>
#include<fstream>
#include<stdlib.h>
#include<time.h>
using namespace std;

void InsertionSort(int a[],int n)
{
int i,j,key;
for(j=1;j<=n-1;j++)
{
key=a[j];
        i=j-1;
        while(i>=0 && a[i]>=key)
        {
        a[i+1]=a[i];
        i--;
       
}
a[i+1]=key;
}
}
int main()
{
int n,a[n];
cin>>n;
//cout<<"enter the elements :"<<endl;
cout<<"the elements are :"<<endl;
for(int i=0;i<n;i++)
{
cin>>a[i];
}
for(int i=0;i<n;i++)
{
cout<<a[i]<<endl;
}
InsertionSort(a,n);

cout<<"the sorted array is :"<<endl;
for(int i=0;i<n;i++)
{
cout<<a[i]<<endl;
}
ofstream fout;
fout.open("output.txt");
for(int m=0;m<n;m++)
{
fout<<a[m]<<"  ";
}
cout<<"list is copied to file"<<endl;
fout.close();

return 0;
}