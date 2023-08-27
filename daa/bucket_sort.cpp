#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

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
    struct node *temp=(struct node*)malloc(sizeof(struct node));
   temp->data=i;
   //cout<<temp->data<<endl;
   temp->link=NULL;
   temp->l=NULL;
   //prev=temp;
   head[i]=temp;
   
    i++;
}
i=0;
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
                //cout<<prev->data<<endl;
                temp->data=n;
               //cout<<prev->data<<endl;
               if(prev->link==NULL)
               {
                //cout<<"0000"<<endl;
                temp->link=NULL;
                temp->l=prev;
                prev->link=temp;
                
               }
               else if(prev->link->data>n)
               {
                //cout<<"///"<<endl;
                  p=prev->link;
                  prev->link=temp;
                  temp->l=prev;
                  temp->link=p;
                  p->l=temp;

               }
           else if(prev->link->link==NULL)
               {
 
            //cout<<".."<<endl;
                if(prev->link->data<n)
               {
                 p=prev->link;
                         p->link=temp;
                    temp->link=NULL;
                    temp->l=p;
                   
  }
               }
               else
               {
           
                p=prev->link;
                /*if(p->data>n)
                {
                    prev->link=temp;
                    p->l=temp;
                    temp->l=prev;
                    temp->link=p;
                }*/
                
                
                while(p->link!=NULL && p->data<n)
                {
                    p=p->link;
                }
                //cout<<p->data<<endl;
                if(p->link==NULL)
                {
                  //pre=prev->link;
                  if(p->data<n)
                  {
                   // cout<<",,"<<endl;
                    p->link=temp;
                    temp->link=NULL;
                    temp->l=p;
                  }
                  else
                {
                   // cout<<",.,.,.,."<<endl;
                    p=p->l;
                   pre=p->link;
                   p->link=temp;
                   temp->l=p;
                   temp->link=pre;
                   pre->l=temp;
                }
                }
                /*else if(p->link==NULL)
                {
                    if(p->data<n)
                    {
                         p->link=temp;
                    temp->link=NULL;
                    temp->l=p;
                    }
                }*/
                else
                {
                    //cout<<",.,.,.,."<<endl;
                    p=p->l;
                   pre=p->link;
                   p->link=temp;
                   temp->l=p;
                   temp->link=pre;
                   pre->l=temp;
                }
                
               }
                
    cout<<"inserted!!"<<endl;
}

void insertionsort()
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
        struct node *prev=(struct node*)malloc(sizeof(struct node));
        int j,i,key;
        for(j=1;j<=10;j++)
        {
            i=j-1;
        }
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
 display();
    return 0;
}
