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

void check()
{
         struct node *prev=(struct node *)malloc(sizeof(struct node));
                  struct node *temp=(struct node *)malloc(sizeof(struct node));

         prev=head;
while(prev->link!=NULL)
{
prev=prev->link;
}
//cout<<prev->data<<endl;
temp=head;
cout<<temp->data<<endl;
head=temp->link;
cout<<head->data<<endl;
prev->link=temp;
//head=head->link;
//cout<<prev->link->data<<endl;
        
}

int main()
{
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    display();
    check();
   //display();
    return 0;
}
