#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;
int count=0;
struct Node
{
float data;
Node *link;
};
struct HeadNode
{
int count;
Node *head;
};
class bucket
{
private :
HeadNode *list;
public :
   void arrayOfHeadNodes(int n)
{
     list=new HeadNode[n];
 for(int i=0;i<n;i++)
 {
  count++;
  list[i].count=0;
  list[i].head=NULL;
 }
}
void insertFront(float key,int n)
{
int index=key*10;
Node *newnode=new Node;
newnode->data=key;
if(list[index].head==NULL)
{
list[index].head=newnode;
newnode->link=NULL;
list[index].count++;
}
else
{
newnode->link=list[index].head;
list[index].head=newnode;
list[index].count++;
}
}
void display(int n)
{
for(int i=0;i<n;i++)
{
Node *temp=list[i].head;
while(temp!=NULL)
{
cout<<temp->data<<"\t";
temp=temp->link;
}
}
}
void retrive(float *a,int n,float *outarr)
{
int val=0;
for(int i=0;i<n;i++)
{
 
 Node *temp=list[i].head;
     while(temp!=NULL)
   {
    count++;
    outarr[val++]=temp->data;
   temp=temp->link;
     }
}
int tempn=val;
for(int i=0;i<tempn;i++)
{
    count++;
a[i]=outarr[i];
}
}
void insertionSort(int n)
{
for(int i=0;i<n;i++)
{

Node *temp=list[i].head;
if(temp!=NULL)
{
 Node *j=temp->link;
 while(j!=NULL&&j->link!=NULL)
 {
float key=j->data;
Node *i1=temp;
while(i1->link!=NULL&&i1->data>=key)
{
    count++;
swap(i1->link->data,i1->data);
i1=i1->link;
}
j=j->link;
 }
   }
}
}
};
void bucketSort(float *a,int n)
{
bucket b;
b.arrayOfHeadNodes(n);
cout<<"Array of list created\n";
for(int i=0;i<n;i++)
{
    count++;
b.insertFront(a[i],n);
}
cout<<"Values are Inserted Successfully\n";
//cout<<"Array list elements before sorting :";
//b.display(n);
cout<<endl;
b.insertionSort(n);
float *outarr=new float[n];
b.retrive(a,n,outarr);
/*cout<<"Retrieved after sorting elements in array list :";
for(int i=0;i<n;i++)
{
cout<<outarr[i]<<"\t";
}
cout<<endl;*/
}
int main()
{
ifstream in;
ofstream out;
int n;
cout<<"Enter no.of list :";
cin>>n;
float *a=new float[n];
out.open("i.txt");
for(int i=0;i<n;i++)
{
float temp=rand()%n;
temp=temp/10;
out<<temp<<"\t";
}
out.close();
in.open("i.txt");
for(int i=0;i<n;i++)
{
in>>a[i];
}
in.close();
count=0;
bucketSort(a,n);
out.open("others_output.txt");
for(int i=0;i<n;i++)
    {
    out<<a[i]<<"\t";
}
out.close();
cout<<"\nBucket Sort iterated for "<<count<<" times"<<endl;
}