#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *link;
}*head=NULL;

struct stack
{
    int data_s;
    struct stack *link_s;
}*h=NULL;

void insert(int value)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
       

    if(head==NULL)
    {
        temp->data=value;
        head=temp;
        head->link=NULL;
    }
    else
    {
         struct node *prev=(struct node *)malloc(sizeof(struct node));
      prev=head;
      head =temp;
      temp->data=value;
      temp->link=prev;

    }

}
int deletion(int &q)
{
   if(head==NULL)
  {
    cout<<"stack is empty"<<endl;
  }
  else{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
             struct node *prev=(struct node *)malloc(sizeof(struct node));

      prev=head;
      q=prev->data;
      temp=prev->link;
      head=temp;
      free(prev);
  }
  return q;
}

void display()
{
    if(head==NULL)
    {
        cout<<"stack is empty"<<endl;
    }
    else
    {
         struct node *temp=(struct node *)malloc(sizeof(struct node));
   temp=head;
   while(temp!=NULL)
   {
    cout<<temp->data<<endl;
temp=temp->link;
   }
    }
}

void inserts()
{
    int value;
    struct stack *temp=(struct stack*)malloc(sizeof(struct stack));
    struct stack *prev=(struct stack*)malloc(sizeof(struct stack));
    int q=deletion(value);
     temp->data_s=q;
     if(h==NULL)
    {
        temp->data_s=value;
        h=temp;
        h->link_s=NULL;
    }
    else
    {
         //struct node *prev=(struct node *)malloc(sizeof(struct node));
      prev=h;
      h =temp;
      temp->data_s=value;
      temp->link_s=prev;

    }

}

void displays()
{
    if(h==NULL)
    {
        cout<<"stack is empty"<<endl;
    }
    else
    {
         struct stack *temp=(struct stack *)malloc(sizeof(struct stack));
   temp=h;
   while(temp!=NULL)
   {
    cout<<temp->data_s<<endl;
temp=temp->link_s;
   }
    }
}

int main()
{
    int q;
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    display();
    inserts();
    inserts();
    inserts();
    inserts();
    inserts();
    displays();
    return 0;
}
