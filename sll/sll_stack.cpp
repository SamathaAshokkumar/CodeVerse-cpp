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

void deletion()
{
  if(head==NULL)
  {
    cout<<"stack is empty"<<endl;
  }
  else{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
             struct node *prev=(struct node *)malloc(sizeof(struct node));

      prev=head;
      temp=prev->link;
      head=temp;
      free(prev);
  }
}

void stacktop()
{
        struct node *temp=(struct node *)malloc(sizeof(struct node));
   //temp=head;
    cout<<"the stacktop value is:"<<endl;
    cout<<head->data<<endl;
}

void emptystack()
{
  if(head==NULL)
  {
    cout<<"stack is empty"<<endl;

  }
  else{
    cout<<"stack is not empty"<<endl;
  }
}

void destroy()
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
             struct node *prev=(struct node *)malloc(sizeof(struct node));
  prev=head;
  while(prev!=NULL)
  {
    temp=prev->link;
    free(prev);
    prev=temp;
  }
  head=NULL;
  cout<<"stack linked list destroyed!!"<<endl;
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

int main()
{

      int choice,j,value;
    cout<<"how many times do you  wanna perform operations:"<<endl;
    cin>>j;
   

for(int i=0;i<=j;i++)
{
     cout<<"enter 1,2,3,4,5, for insert,deletion,stack_empty,stacktop,display,display" <<endl;
    cin>>choice;
    switch(choice)
    {
        case 1:
        cout<<"enetr the value to be inserted:"<<endl;
        cin>>value;
        insert(value);
        break;

        case 2:
        deletion();
        break;

        case 3:
        emptystack();
        break;

        case 4:
        stacktop();
        break;

        case 5:
        display();
        break;

        case 6:
        destroy();
        break;

        default:
        cout<<"invalid choice!!"<<endl;

    }
}
    
    return 0;
}