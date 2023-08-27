#include<stdio.h>
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

struct sjf
{
int pid;
int at;
int bt;
struct sjf *link;
}*front=NULL,*rear=NULL;





void inqueue(int id,int arr_time,int burst_time)
{
struct sjf *temp=(struct sjf*)malloc(sizeof(struct sjf));
temp->pid=id;
temp->at=arr_time;
temp->bt=burst_time;
temp->link=NULL;
if(front==NULL)
{
front=temp;
rear=temp;
}
else
{
struct sjf *pre=(struct sjf*)malloc(sizeof(struct sjf));
pre=front;
if(rear->at<=temp->at )
{
rear->link=temp;
rear=temp;
}
else if(front->at>temp->at)
{

front=temp;
front->link=pre;
}
else
{
while(pre->link->link!=NULL)
{
if(pre->at<temp->at )
{
pre=pre->link;
}
else
{
    break;
}

}
struct sjf *p=(struct sjf*)malloc(sizeof(struct sjf));
p=pre->link;
pre->link=temp;
temp->link=p;

}
}
}


void dequeue()
{
struct sjf *pre=(struct sjf*)malloc(sizeof(struct sjf));
if(front==NULL)
{
cout<<"the queue is empty"<<endl;
}
else
{
pre=front->link;
front=pre;
}
}



void display()
{
struct sjf *temp=(struct sjf*)malloc(sizeof(struct sjf));
temp=front;
while(temp!=NULL)
{
cout<<temp->pid<<endl;
temp=temp->link;
}
}


void sjf_check()
{
struct sjf *pre=(struct sjf*)malloc(sizeof(struct sjf));
struct sjf *p=(struct sjf*)malloc(sizeof(struct sjf));
struct sjf *pr=(struct sjf*)malloc(sizeof(struct sjf));
struct sjf *t=(struct sjf*)malloc(sizeof(struct sjf));
int count=0;

pre=front->link;
while(pre->link!=NULL)
{
//cout<<",,"<<pre->bt<<endl;
p=pre->link;
  t=p->link;
  //cout<<"..."<<p->bt<<endl;
  //cout<<endl;
  if(count==0)
  {
  if(p->bt<pre->bt)
  {
    pr=pre;
    pre=p;
    pre->link=pr;
    pr->link=t;
    front->link=pre;
    pre=pre->link;
    display();
    cout<<",,,"<<endl;
    //cout<<pre->bt<<endl;
  }
  else
  {
    pre=pre->link;
  }
  }
else
{
    //pre=front->link;

  p=pre->link;
  t=p->link;
  //cout<<"..."<<p->bt<<endl;
  //cout<<endl;
  if(p->bt<pre->bt)
  {
    pr=pre;
    pre=p;
    pre->link=pr;
    pr->link=t;
    pre=pre->link;
    cout<<",,,"<<endl;
    display();
        cout<<",,,"<<endl;

    //cout<<pre->bt<<endl;
  }
  else{
  pre=pre->link;
  }
}
count++;
  }
}


int main()
{
//cout<<".."<<endl;
inqueue(1,0,3);
inqueue(2,1,2);
inqueue(3,2,1);
inqueue(4,4,1);
inqueue(5,5,2);
sjf_check();
//inqueue(5,0,2);
//dequeue();
//dequeue();
//dequeue();
//dequeue();
//display();
return 0;
}

