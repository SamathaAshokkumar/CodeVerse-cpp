#include<iostream>
#include<cstdlib>
#include<fstream>
#include<stdlib.h>
using namespace std;

int count;

void MaxHeapify(int a[],int n,int i)
{
int l=(2*i)+1;
int r=(2*i)+2;
int m=i;
if(l<=n-1 && a[l]<a[m])
{
m=l;

}
if(r<=n-1 && a[r]<a[m])
{
m=r;
}
if(m!=i)
{
count++;
swap(a[i],a[m]);
MaxHeapify(a,n,m);
}
}

void reverse_insertion(int arr[],int n)
{
     int i,j,key;
    
           
for(j=1;j<n;j++)
{
key=arr[j];
        i=j-1;
        while(i>=0 && arr[i]<=key)
        {
        arr[i+1]=arr[i];
        i--;
       
       
}
arr[i+1]=key;

}
    //return count;
}


void BuildMaxHeap(int a[],int n)
{
for(int i=(n-2)/2;i>=0;i--)
{
count++;
MaxHeapify(a,n,i);
}
}

void HeapSort(int a[],int n)
{
BuildMaxHeap(a,n);
while(n>1)
{
count++;
swap(a[0],a[n-1]);
n=n-1;
MaxHeapify(a,n,0);
}
}

/*int main()
{
int *a;
int n;
cout<<"enter n:"<<endl;
cin>>n;
a= new int[n];

for(int j=0;j<n;j++)
{
cin>>a[j];
}
//HeapSort(a,n);
//cout<<"the total operations for heap sort is :"<<count;
HeapSort(a,n);
cout<<"....."<<endl;
for(int j=0;j<n;j++)
{
cout<<a[j]<<endl;
}
count=0;
return 0;
}*/
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
HeapSort(a,n);
fout.open("minheapsort_output.txt");
for(int i=0;i<n;i++)
{
fout<<a[i]<<"\t";
}
fout.close();
cout<<"the time complexity of quick sort for random ordered elements is:"<<count<<endl;
count=0;
fin.open("minheapsort_output.txt");
for(int i=0;i<n;i++)
{
fin>>a[i];
}
fin.close();
HeapSort(a,n);
fout.open("minheapsort_output.txt");
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
HeapSort(a,n);
fout.open("minheapsort_output.txt");
for(int i=0;i<n;i++)
{
fout<<a[i]<<"\t";
}
fout.close();
cout<<"the time complexity of quick sort for reverse ordered elements is:"<<count<<endl;
count=0;
return 0;
}