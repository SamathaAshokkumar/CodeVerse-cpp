#include<iostream>
#include<fstream>
#include<stdlib.h>

using namespace std;
int count=0;

int partition(int a[],int s,int e)
{
int key=a[e];
int i=s-1;
for(int j=s;j<=e;j++)
{
count++;
if(a[j]<=key)
{
i=i+1;
swap(a[i],a[j]);
}
}
return i;
}

int QS(int a[],int s,int e)
{
if(s>=e)
{
return 0;
}

   int m=partition(a,s,e);
   //cout<<m<<endl;
   count++;
   QS(a,s,m-1);
   count++;
   QS(a,m+1,e);
   //cout<<".."<<endl;
   return count;
}


void reverse_insertion(int arr[],int n)
{
     int i,j,key;
    
           
for(j=1;j<n;j++)
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

int main()
{
ofstream fout;
ifstream fin;
int n;
cout<<"enter n:"<<endl;
cin>>n;
int *a;
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
QS(a,0,(n-1));
fout.open("quicksort_output.txt");
for(int i=0;i<n;i++)
{
fout<<a[i]<<"\t";
}
fout.close();
cout<<"the time complexity of quick sort for random ordered elements is:"<<count<<endl;
count=0;
fin.open("quicksort_output.txt");
for(int i=0;i<n;i++)
{
fin>>a[i];
}
fin.close();
QS(a,0,(n-1));
fout.open("quicksort_output.txt");
for(int i=0;i<n;i++)
{
fout<<a[i]<<"\t";
}
fout.close();
cout<<"the time complexity of quick sort for ordered elements is:"<<count<<endl;
count=0;
fin.open("in.txt");
for(int i=0;i<n;i++)
{
fin>>a[i];
}
fin.close();
reverse_insertion(a,n);
fout.open("reverse.txt");
for(int i=0;i<n;i++)
{
fout<<a[i]<<"\t";
}
fout.close();
fin.open("reverse.txt");
for(int i=0;i<n;i++)
{
fin>>a[i];
}
fin.close();
QS(a,0,(n-1));
fout.open("quicksort_output.txt");
for(int i=0;i<n;i++)
{
fout<<a[i]<<"\t";
}
fout.close();
cout<<"the time complexity of quick sort for reverse ordered elements is:"<<count<<endl;
count=0;
return 0;
}