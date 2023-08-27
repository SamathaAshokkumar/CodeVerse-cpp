#include<iostream>
using namespace std;

struct node
{
    struct node *prev;
    int data;
    struct node *succ;
}*head=NULL;

void insert_beg(int data)
{
       struct node *temp=(struct node*)malloc(sizeof(struct node));
              struct node *prev=(struct node*)malloc(sizeof(struct node));

       temp->data=data;
     if(head==NULL)
     {
         head=temp;
         temp->prev=NULL;
         temp->succ=NULL;
     }
     else
     {
        prev=head;
        temp->prev=NULL;
        temp->succ=prev;
        prev->prev=temp;
        head=temp;
     }

     cout<<"element inserted at the beginning !! "<<endl;
}


void insert_end(int data)
{
     struct node *temp=(struct node*)malloc(sizeof(struct node));
              struct node *prev=(struct node*)malloc(sizeof(struct node));
              temp->data=data;
   if(head==NULL)
   {
     head=temp;
         temp->prev=NULL;
         temp->succ=NULL;
   }

   else
   {
    prev=head;
    while(prev->succ!=NULL)
    {
        prev=prev->succ;
    }
     prev->succ=temp;
     temp->prev=prev;
     temp->succ=NULL;
   }
   cout<<"element inserted at the end"<<endl;
}

void insert(int data)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
              struct node *prev=(struct node*)malloc(sizeof(struct node));
              temp->data=data;
   if(head==NULL)
   {
     head=temp;
         temp->prev=NULL;
         temp->succ=NULL;
   }
   else
   {
    prev=head;
    while(prev->succ!=NULL)
    {
        prev=prev->succ;
    }
     prev->succ=temp;
     temp->prev=prev;
     temp->succ=NULL;
   }
   
    cout<<"element inserted !!"<<endl;
}
void display()
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
              struct node *prev=(struct node*)malloc(sizeof(struct node));
              temp=head;
              while(temp!=NULL)
              {
                cout<<temp->data<<endl;
                temp=temp->succ;
              }
}




int main()
{
 insert_beg(1);
  insert_beg(2);

 insert_beg(3);

 insert_beg(4);
insert_end(5);
insert_end(6);
insert_end(7);
insert(8);
insert(9);
insert(10);
display();

return 0;
}