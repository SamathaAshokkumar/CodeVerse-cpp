#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *prev;
    struct node *succ;
}*head=NULL,*rear=NULL;

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
        rear->succ=head;
    }
    else{
        prev=head;
        while(prev!=rear)
        {
            prev=prev->succ;
        }
        temp->prev=prev;
        temp->succ=NULL;
        prev->succ=temp;
        rear=temp;
        //head->prev=rear;
        rear->succ=head;
    }
    //cout<<rear->data<<endl;
    cout<<"element has inserted!!"<<endl;
}
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
void deletion(int delvalue)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
              struct node *prev=(struct node*)malloc(sizeof(struct node));
                            struct node *p=(struct node*)malloc(sizeof(struct node));


              temp=head;
        
              if(temp->data==delvalue)
              {
                prev=temp->succ;
                prev->prev=temp->prev;
                head=prev;
                free(temp);
              }
        
            
               else if(rear->data==delvalue)
              {
                
                p=rear->prev;
                p->succ=NULL;
                free(rear);
                rear=p;
              }
              else
              {
              while(temp!=rear && temp->data!=delvalue)
              {
                temp=temp->succ;
              }
            

              if(temp->data==delvalue)
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
        else if(prev->succ->data>value)
        {
             temp->prev=prev;
             temp->succ=prev->succ;
               prev->succ->prev=temp;
             prev->succ=temp;
        }
        else{
            cout<<"elment already present"<<endl;
        }
             }
    }
             cout<<"element inserted in ordered search list!!"<<endl;
             //cout<<head->data<<endl;
}


void count()
{
     struct node *temp=(struct node *)malloc(sizeof(struct node));
             
    int count=0;
    temp=head;
    while(temp!=rear)
    {
        count++;
        temp=temp->succ;
    }
    if(count+1==0)
    {
        cout<<"the list is empty!!"<<endl;
    }
    else{
        cout<<"the count of the list is : "<<count+1<<endl;
    }
}

void empty_cdll()
{
    if(head==NULL)
    {
        cout<<"the list is empty"<<endl;
    }
    else
    {
        cout<<"the list is not empty"<<endl;
    }
}

void searchh_r(int target)
{
    
     struct node *temp=(struct node *)malloc(sizeof(struct node));
            
             int count=0;
    if(head==NULL)
    {
        cout<<"the list is empty!!"<<endl;
    }
    else
    {
        temp=head;
        while(temp!=rear && temp->data!=target)
        {
            count++;
            temp=temp->succ;
            
        }
        if(temp->data==target)
        {
            cout<<"the target element is present at the location:"<<count+1<<endl;
        }
        else if(rear->data==target)
        {
            cout<<"the target element is located at the location:"<<count+2<<endl;
        }
    
    else
    {
        cout<<"the target element is not present"<<endl;
    }
    }
}

void searchr_h(int target)
{
    
     struct node *temp=(struct node *)malloc(sizeof(struct node));
             int count=0;
    if(head==NULL)
    {
        cout<<"the list is empty!!"<<endl;
    }
    else
    {
        temp=rear;
        while(temp!=head && temp->data!=target)
        {
            count++;
            temp=temp->prev;
            
        }
        if(temp->data==target)
        {
            cout<<"the target element is present at the location:"<<count+1<<endl;
        }
        else if(head->data==target)
        {
            cout<<"the target element is located at the location:"<<count+2<<endl;
        }
    
    else
    {
        cout<<"the target element is not present"<<endl;
    }
    }
}

void destroy()
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
             struct node *prev=(struct node *)malloc(sizeof(struct node));
  prev=head;
  while(prev!=rear)
  {
    temp=prev->succ;
    free(prev);
    prev=temp;
  }
  free(rear);
  head=NULL;
  rear=NULL;
  cout<<"double linked list destroyed!!"<<endl;
}

int main()
{
    int j;
    int choice;
    cout<<"how many times do you  wanna perform operations:"<<endl;
    cin>>j;

    for(int i=0;i<=j;i++)
{
    cout<<"enter 1,2,3,4,5,6,7,8,9,10,11 for insert,order_insert,deletion,counting value,display_head_to _rear,display_rear_to_head,search,search_from_rear_to_head,empty_cdll,destroy" <<endl;
    cin>>choice;
   switch(choice)
   {
    
    case 1:
    int value;
    cout<<"element to be inserted!!"<<endl;
    cin>>value;
   insert(value);
   break;

   case 2:
   int ordvalue;
   cout<<"enter the value to be inserted : "<<endl;
   cin>>ordvalue;
   order_insert(ordvalue);
   break;

   case 3:
   int delvalue;
   cout<<"enter the value to be deleted:"<<endl;
   cin>>delvalue;
   deletion(delvalue);
   break;

   case 4:
   count();
    break;

    case 5:
    displayh_r();
    break;
    
    case 6:
    displayr_h();
    break;

    case 7:
     cout<<"enter the value to be searched:"<<endl;
   cin>>value;
    searchh_r(value);
    break;

    case 8:
    cout<<"enter the value to be inserted:"<<endl;
    cin>>value;
    searchr_h(value);
    break;

    case 9:
    empty_cdll();
    break;

    case 10:
    destroy();
    break;

   }
}

return 0;
}

