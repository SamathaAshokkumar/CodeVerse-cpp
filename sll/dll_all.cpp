#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node *prev;
    struct node * succ;
}*head=NULL;

void insert(int value)
{
     struct node *temp=(struct node*)malloc(sizeof(struct node));
              struct node *prev=(struct node*)malloc(sizeof(struct node));
    temp->data=value;
    if(head==NULL)
    {
        temp->prev=NULL;
        temp->succ=NULL;
        head=temp;

    }

    else
    {
        prev=head;
        while(prev->succ!=NULL)
        {
            prev=prev->succ;
        }
        temp->prev=prev;
        temp->succ=prev->succ;
        prev->succ=temp;
    }
    cout<<"element inserted"<<endl;
}

void deletion()
{
    if(head==NULL)
    {
        cout<<"the list is empty"<<endl;
    }
    else{
         struct node *temp=(struct node*)malloc(sizeof(struct node));
              struct node *prev=(struct node*)malloc(sizeof(struct node));
              temp=head;
              while(temp->succ!=NULL)
              {
                temp=temp->succ;
              }
              
              prev=temp->prev;
              prev->succ=NULL;
              free(temp);

    }
    cout<<"element deleted"<<endl;
}

void search(int target)
{
             struct node *temp=(struct node*)malloc(sizeof(struct node));
         struct node *prev=(struct node*)malloc(sizeof(struct node));
        int count =0;
        temp=head;
        while(temp!=NULL && temp->data!=target)
        {
            temp=temp->succ;
            count++;
        }

        if(temp->data==target)
        {
            cout<<"the element found at the location:"<<count+1<<endl;
        }
        else
        {
            cout<<"element not found"<<endl;
        }
}

void display()
{
         struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<endl;
        temp=temp->succ;
    }
}

void displayr_h()
{
             struct node *temp=(struct node*)malloc(sizeof(struct node));
         struct node *prev=(struct node*)malloc(sizeof(struct node));
            //struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp=head;
    while(temp!=NULL)
    {
        //cout<<temp->data<<endl;
        temp=temp->succ;
    }
    prev=temp;
   while(prev!=NULL)
   {
    cout<<prev->data<<endl;
    prev=prev->prev;
   }
}




int main()
{
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    //display();
    displayr_h();
    deletion();
    deletion();
    display();
    search(3);
    
    
}