#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *prev;
    struct node *succ;
}*head=NULL,*rear=NULL;

void displayh_r()
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
            
            if(head==NULL)
            {
                cout<<"the list is empty!!"<<endl;
            }
            else
            {
   temp=head;
   while(temp!=rear)
   {
    cout<<temp->data<<endl;
    temp=temp->succ;
   }
   cout<<rear->data<<endl;
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
    while(temp!=head)
    {
        cout<<temp->data<<endl;
        temp=temp->prev;
    }
    cout<<head->data<<endl;
    }
}

/*void order_insert(int value)
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
        //rear->succ=head;
    }
    else
    {
             prev=head;
             
             if(head==rear)
            {
                if(head->data<value)
                {
                    temp->prev=prev;
                    temp->succ=prev->succ;
                    prev->succ=temp;
                    rear=temp;
                    rear->succ=prev;
                }
                if(head->data>value)
                {
                    temp->prev=prev->prev;
                temp->succ=prev;
                prev->prev=temp;
                head=temp;
                rear=prev;
                rear->succ=head;
                }
            }
            else if(prev->data>value)
             {
                temp->prev=prev->prev;
                temp->succ=prev;
                prev->prev=temp;
                head=temp;
                //rear=prev;
                rear->succ=head;
             }
             else
             {
                
             while(prev!=rear && prev->data<value)
             {

                  prev=prev->succ;
             }
             prev=prev->prev;
            
        if(prev->succ->data<value)
        {
             temp->prev=prev->succ;
     prev->succ->succ=temp;
     temp->succ=NULL;
     rear=temp;
     rear->succ=head;
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
             //cout<<head->data<<endl;
}*/

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
        rear->succ=head;
        head->prev=rear;
    }
    else
    {
             prev=head;
             
             if(head==rear)
            {
                if(head->data<value)
                {
                    temp->prev=prev;
                    temp->succ=prev->succ;
                    prev->succ=temp;
                    rear=temp;
                    rear->succ=prev;
                    head->prev=rear;
                }
                if(head->data>value)
                {
                    temp->prev=prev->prev;
                temp->succ=prev;
                prev->prev=temp;
                head=temp;
                //rear=prev;
                rear->succ=head;
                head->prev=rear;
                }
                else{
                    cout<<"element already present"<<endl;
                }
            }
            else if(prev->data>value)
             {
                temp->prev=prev->prev;
                temp->succ=prev;
                prev->prev=temp;
                head=temp;
                //rear=prev;
                rear->succ=head;
                head->prev=rear;
             }
             else
             {
                
             while(prev!=rear && prev->data<value)
             {

                  prev=prev->succ;
             }
             prev=prev->prev;
            
        if(prev->succ->data<value)
        {
             temp->prev=prev->succ;
     prev->succ->succ=temp;
     temp->succ=NULL;
     rear=temp;
     rear->succ=head;
     head->prev=rear;
        }
        else if(prev->succ->data>value)
        {
             temp->prev=prev;
             temp->succ=prev->succ;
               prev->succ->prev=temp;
             prev->succ=temp;
        }
        else{
            cout<<"element already present"<<endl;
        }
             }
    }
             cout<<"element inserted in ordered search list!!"<<endl;
             //cout<<head->data<<endl;
}

/*void order_insert(int value)
{
struct node *temp=(struct node*)malloc(sizeof(struct node));
struct node *prev=(struct node*)malloc(sizeof(struct node));
prev=head;
temp->data=value;
if(head==NULL)
{
    cout<<"1"<<endl;
temp->prev=NULL;
temp->succ=NULL;
head=temp;
rear=temp;
}
if(head->data>value)
{
    cout<<",2"<<endl;
temp->succ=head;
head->prev=temp;
temp->prev=head->prev;
head=temp;
rear->succ=head;
}
/*else if(head=rear)
{
temp->prev=head;
temp->succ=head->succ;
rear=temp;
head->prev=rear;
}
else if(rear->data<value)
{
    cout<<",last"<<endl;
temp->prev=rear;
temp->succ=rear->succ;
rear=temp;
head->prev=rear;
}

else
{
    cout<<".."<<endl;
prev=head;
while(prev->succ!=rear && prev->data<value)
{
prev=prev->succ;
}
prev=prev->prev;
if(prev->data<value)
{
    cout<<"mid"<<endl;
temp->prev=prev;
temp->succ=prev->succ;
prev->succ=temp;
}
}
cout<<"inserted"<<endl;

}*/

void deletion(int delvalue)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
              struct node *prev=(struct node*)malloc(sizeof(struct node));
                            struct node *p=(struct node*)malloc(sizeof(struct node));

              temp=head;
              
              while(temp!=rear && temp->data!=delvalue)
              {
                temp=temp->succ;
              }
              
              if(temp==head)
              {
                prev=temp->succ;
                prev->prev=temp->prev;
                head=prev;
                free(temp);
              }
              else
              {

              
              
               if(rear->data==delvalue)
              {
                
                p=rear->prev;
                p->succ=NULL;
                free(rear);
                rear=p;
              }
            

              else if(temp->data==delvalue)
              {
                
                    prev=temp->prev;
                prev->succ=temp->succ;
                temp->succ->prev=prev;
                free(temp);
                
              }
              
              else
              {
               cout<<"element not found!!"<<endl;
              }

}
}

int main()
{
    order_insert(1);
    order_insert(10);
    order_insert(0);
    order_insert(-9);
    order_insert(-2);
    order_insert(8);
    order_insert(9);
        order_insert(3);

    order_insert(4);

    order_insert(6);

        //order_insert(10);
    order_insert(6);

    displayh_r();
    //deletion(0);
        //deletion(8);
    //deletion(0);

    cout<<"..."<<endl;
    //displayr_h();
    displayr_h();

}