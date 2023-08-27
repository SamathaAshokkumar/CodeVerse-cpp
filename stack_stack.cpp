#include<iostream>
#include<string.h>
#include<cstring>
using namespace std;

struct node
{
    int data;
    struct node *link;
}*top1,*top2=NULL;

void insert1(int value)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
        struct node *prev=(struct node*)malloc(sizeof(struct node));
  temp->data=value; 
  if(top1==NULL)
{
top1=temp;
top1->link=NULL;
}
else
{
    prev=top1;
    top1=temp;
   temp->link=prev;
}
    cout<<"element inserted"<<endl;
}

void display1()
{
   struct node *temp=(struct node*)malloc(sizeof(struct node));

temp=top1;
while(temp!=NULL)
{
cout<<temp->data<<endl;
temp=temp->link;
}
}

void insert2()
{
    struct node *temp1=(struct node*)malloc(sizeof(struct node));
        struct node *prev1=(struct node*)malloc(sizeof(struct node));
                struct node *prev2=(struct node*)malloc(sizeof(struct node));
 prev1=top1;
  while(prev1!=NULL)
  {
    temp1->data=prev1->data;
  if(top2==NULL)
{
temp1->link=NULL;
top2=temp1;
cout<<top2->data<<endl;
}
else{
    prev2=top2;
   temp1->link=prev2;
     top2=temp1;
     cout<<top2->data<<endl;
}
    prev1=prev1->link;
}
cout<<"element inserted"<<endl;
}

void display2()
{
    cout<<"the element is displayed : "<<endl;
   struct node *temp1=(struct node*)malloc(sizeof(struct node));
temp1=top2;
cout<<temp1->data<<endl;
while(temp1->link!=NULL)
{
cout<<temp1->data<<endl;
temp1=temp1->link;
}
}

int main()
{
    insert1(6);
    insert1(2);
    insert1(3);
    insert1(4);
    insert1(5);
    display1();   
    insert2();
    cout<<top2->data<<endl;
       struct node *temp=(struct node*)malloc(sizeof(struct node));
              struct node *prev=(struct node*)malloc(sizeof(struct node));
  temp=top2->link;
  cout<<temp->data<<endl;
  prev=temp->link;
  cout<<prev->data<<endl;
    display2();
    return 0;
}