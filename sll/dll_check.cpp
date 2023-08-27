#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *prev;
    struct node * succ;
}*head, *rear;

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
        rear=temp;
    }
    else{
        prev=head;
        while(prev->succ!=NULL)
        {
            prev=prev->succ;
        }
        temp->prev=prev;
        temp->succ=prev->succ;
        prev->succ=temp;
        rear=temp;
    }
    //cout<<rear->data<<endl;
    cout<<"element has inserted!!"<<endl;
}

void displayh_r()
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
    temp=rear;
    if(head==NULL)
    {
        cout<<"the list is empty!!"<<endl;
    }
    else
    {
    while(temp!=NULL)
    {
        cout<<temp->data<<endl;
        temp=temp->prev;
    }
    }
}

void insert_pre(int invalue,int prevalue)
{

    if(head==NULL)
    {
        cout<<"list is empty , element not inserted!!"<<endl;
    }
    else
    {
        struct node *temp=(struct node *)malloc(sizeof(struct node));
             struct node *prev=(struct node *)malloc(sizeof(struct node));
             temp->data=invalue;
             
                 prev=head->succ;
                 
             while(prev!=NULL && prev->prev->data!=prevalue)
             {
               
                prev=prev->succ;
             }
             prev=prev->prev;


            /* if(prev==rear)
         {    
        temp->prev=prev;
        temp->succ=prev->succ; 
        prev->succ=temp; 
        rear=temp;
    }   */
    
    if(prev->succ->data==prevalue)
   {
     temp->prev=prev->succ;
     prev->succ->succ=temp;
     temp->succ=NULL;
     rear=temp;
   }
    else
    {
        cout<<".."<<endl;
        temp->prev=prev;
        temp->succ=prev->succ;
        prev->succ=temp;
        temp->succ->prev=temp;
    }
    }
    cout<<"element inserted after predecessor!!"<<endl;
}
void order_insert(int value)
{
     struct node *temp=(struct node *)malloc(sizeof(struct node));
             struct node *prev=(struct node *)malloc(sizeof(struct node));
                          
             temp->data=value;
             if(head==NULL)
    {
        temp->prev=NULL;
        temp->succ=NULL;
        head=temp;
        rear=temp;
    }
    else
    {
             prev=head;
             if(prev->data>value)
             {
                temp->prev=prev->prev;
                temp->succ=prev;
                prev->prev=temp;
                head=temp;
             }
            else if(head==rear)
            {
                if(head->data<value)
                {
                    temp->prev=prev;
                    temp->succ=prev->succ;
                    prev->succ=temp;
                    rear=temp;
                }
            }
             else
             {
                
             while(prev->succ!=NULL && prev->data<value)
             {

                  prev=prev->succ;
                  
             }

             //cout<<prev->data<<endl;
             prev=prev->prev;
             cout<<prev->data<<endl;
        if(prev->succ->data<value)
        {
             temp->prev=prev->succ;
     prev->succ->succ=temp;
     temp->succ=NULL;
     rear=temp;
        }
        else
        {
             temp->prev=prev;
             temp->succ=prev->succ;
               prev->succ->prev=temp;
             prev->succ=temp;
        }
             }
    }
             cout<<"element inserted in ordered search list!!"<<endl;
}


int main()
{
    insert(1);
    insert(2);
    insert(3);
    //insert(4);
    insert(5);
    //cout<<"display from head to rear : "<<endl;
   //displayh_r();
    
  order_insert(4);
    order_insert(8);

    order_insert(6);
    order_insert(10);
    order_insert(0);
        order_insert(-1);
    order_insert(-2);


cout<<"displaying"<<endl;
displayh_r();
    return 0;
}