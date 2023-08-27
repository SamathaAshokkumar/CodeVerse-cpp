#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *link;
}*head=NULL;



void insert(int value)
{
   struct node *temp=(struct node *)malloc(sizeof(struct node));
      struct node *prev=(struct node *)malloc(sizeof(struct node));

   if(head==NULL)
{
    temp->data=value;
head=temp;
head->link=NULL;
}
else
{
prev=head;
while(prev->link!=NULL)
{
prev=prev->link;
}
temp->data=value;
temp->link=NULL;
prev->link=temp;  

}
 
   cout<<"element inserted!"<<endl;
}

void display()
{
       struct node *temp=(struct node *)malloc(sizeof(struct node));

temp=head;
while(temp!=NULL)
{
    cout<<temp->data<<endl;
    temp=temp->link;

}
}

void nodechange()
{
   struct node *temp=(struct node *)malloc(sizeof(struct node));
      struct node *prev=(struct node *)malloc(sizeof(struct node));
      prev=head;
      while(prev->link!=NULL)
         {
            prev=prev->link;
            
         }  
    swap(prev->data,head->data);
    cout<<"first node and last node changed"<<endl;
}

int main()
{
   insert(1);
   insert(2);
   insert(3);
   insert(4);
   insert(5);
   display();
   nodechange();
   display();
   return 0;

}