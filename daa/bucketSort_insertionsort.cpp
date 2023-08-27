#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
int count;
struct node
{
    float data;
    struct node *link;
    struct node *l;
}*head[50];

void create_head()
{
     //struct node *temp=(struct node*)malloc(sizeof(struct node));
        struct node *prev=(struct node*)malloc(sizeof(struct node));
                struct node *h=(struct node*)malloc(sizeof(struct node));
                 int i=0;
    //int rem=num%5;
     /*temp->data=num;
    temp->link=NULL;
    
   head[num]=temp;


return head[num];*/
/*for(i;i<=10;i++)
{
     head[i]->data=i;
    head[i]->link=NULL;
     head[i]->data=i;
    head[i]->link=NULL;
}*/
while(i<=10)
{
    count++;
    struct node *temp=(struct node*)malloc(sizeof(struct node));
   temp->data=i;
   //cout<<temp->data<<endl;
   temp->link=NULL;
   temp->l=NULL;
   //prev=temp;
   head[i]=temp;
   
    i++;
}
/*while(head[i]!=NULL)
{
  cout<<head[i]->data<<endl;
  i++;
}*/
}

void insert(float n)
{
     struct node *temp=(struct node*)malloc(sizeof(struct node));
        struct node *prev=(struct node*)malloc(sizeof(struct node));
                struct node *pre=(struct node*)malloc(sizeof(struct node));
                                struct node *p=(struct node*)malloc(sizeof(struct node));
        int num;
               num=n;
                prev=head[num];
                temp->data=n;

               pre=prev->link;
               prev->link=temp;
               temp->link=pre;
               temp->l=prev;


}

void display()
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
        struct node *prev=(struct node*)malloc(sizeof(struct node));
        int i=0;
        //prev=head[i];
          
        while(head[i]!=NULL)
        {
        prev=head[i];
//cout<<"the number for "<<i<<" are follows : "<<endl;
if(prev->link==NULL)
{
   // cout<<"the list is empty!!"<<endl;
}
        else if(prev->data==i)
        {
            prev=prev->link;
            while(prev!=NULL)
            {
                //cout<<",,"<<endl;
                // cout<<"the numbers and divisors for a remainder "<<r<<" are follows : "<<endl;
                 cout<<prev->data<<endl;
                 //cout<<"the divider is : "<<prev->div<<endl;
                 prev=prev->link;
            }
        }
          i++;
        }
    
}

void insertion_sort()
{
   struct node *temp=(struct node*)malloc(sizeof(struct node));
        struct node *prev=(struct node*)malloc(sizeof(struct node));

    //temp=head[0];
    for(int i=0;i<=10;i++)
    {
        
        temp=head[i];
        for(temp;temp!=NULL;temp=temp->link)
        {
            
        for(prev=temp->link;prev!=NULL;prev=prev->link)
        {
            count++;
            if(prev->data<temp->data)
            {
                swap(prev->data,temp->data);
            }
        }
        }
    }     
}

int main()
{
  float num;
 int j;
 int choice;
 create_head();
int n;
cout<<"enter the number of elements:"<<endl;
cin>>n;
cout<<"enter the numbers:"<<endl;
 for(int i=0;i<n;i++)
 {
    cin>>num;
    insert(num);
   
 }
 cout<<endl;
 insertion_sort();
 display();
 cout<<count<<endl;
 count=0;
    return 0;
}