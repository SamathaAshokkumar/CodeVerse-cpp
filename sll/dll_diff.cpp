#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *prev;
    struct node * succ;
}*head=NULL, *rear=NULL;

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
                 
             while(prev->succ!=NULL && prev->prev->data!=prevalue)
             {
               
                prev=prev->succ;
             }
             prev=prev->prev;

    if(prev->succ->data==prevalue)
   {
     temp->prev=prev->succ;
     prev->succ->succ=temp;
     temp->succ=NULL;
     rear=temp;
     cout<<"element inserted after predecessor!!"<<endl;
   }
    else if(prev->data==prevalue )
    {
        cout<<"..."<<endl;
        temp->prev=prev;
        temp->succ=prev->succ;
        prev->succ=temp;
        temp->succ->prev=temp;
        cout<<"element inserted after predecessor!!"<<endl;
    }
    else{
        cout<<"element not found"<<endl;
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
                
             while(prev->succ!=NULL && prev->data<=value)
             {

                  prev=prev->succ;
             }

             //cout<<prev->data<<endl;
             prev=prev->prev;
             //cout<<prev->data<<endl;
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

void deletion()
{

      if(head==rear)
    {
        cout<<"the list is empty"<<endl;
        head=rear=NULL;
    }
   else{
 struct node *temp=(struct node*)malloc(sizeof(struct node));
struct node *prev=(struct node*)malloc(sizeof(struct node));
              temp=head;
              //cout<<tem<<endl;
            prev=temp->succ;
            //cout<<prev->pid<<endl;
            prev->prev=NULL;
              
              free(temp);
              head=prev;

   cout<<"deleted"<<endl;
    } 
    /*if(head==NULL)
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
              rear=prev;

    }*/
    cout<<"element deleted"<<endl;
    }


void displayh_r()
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
            
   temp=head;
    if(head==NULL)
    {
        cout<<"the list is empty!!"<<endl;
    }
    else
    {
   while(temp!=NULL)
   {
    cout<<temp->data<<endl;
    temp=temp->succ;
   }
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

void search(int target)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
        int count =0;
        temp=head;
    
        
        while(temp->succ!=NULL && temp->data!=target)
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
void searchr_h(int target)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
         struct node *prev=(struct node*)malloc(sizeof(struct node));
        int count =0;
        temp=rear;
    
        
        while(temp->prev!=NULL && temp->data!=target)
        {
            temp=temp->prev;
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

void count()
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
        // struct node *prev=(struct node*)malloc(sizeof(struct node));
        int count =0;
        temp=head;
        while(temp->succ!=NULL)
        {
            temp=temp->succ;
            count++;
        }
        cout<<"the count is : "<<count+1<<endl;
}

void empty_dll()
{
   
    struct node *temp=(struct node*)malloc(sizeof(struct node));
        // struct node *prev=(struct node*)malloc(sizeof(struct node));
        int count =0;
        temp=head;
        while(temp!=NULL)
        {
            temp=temp->succ;
            count++;
        }
      if(count==0)
      {
        cout<<"the list is empty!!"<<endl;
      }
      else
      {
        cout<<"the list is not empty"<<endl;
      }
}

void destroy()
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
             struct node *prev=(struct node *)malloc(sizeof(struct node));
  prev=head;
  while(prev!=NULL)
  {
    temp=prev->succ;
    free(prev);
    prev=temp;
  }
  head=NULL;
  rear=NULL;
  cout<<"double linked list destroyed!!"<<endl;
}



   int main()
{
    /*int j;
    int choice;
    cout<<"how many times do you  wanna perform operations:"<<endl;
    cin>>j;

    for(int i=0;i<=j;i++)
{
    cout<<"enter 1,2,3,4,5,6,7,8,9,10,11 for insert,insert_pre,order_insert,deletion,counting value,display_head_to _rear,display_rear_to_head,search,search_from_rear_to_head,empty_dll,destroy" <<endl;
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
   int invalue,prevalue;
   cout<<"enter the value to be inserted:"<<endl;
   cin>>invalue;
   cout<<"enter the predecessor value:"<<endl;
   cin>>prevalue;
   insert_pre(invalue,prevalue);
   break;

   case 3:
   int ordvalue;
   cout<<"enter the value to be inserted : "<<endl;
   cin>>ordvalue;
   order_insert(ordvalue);
   break;

   case 4:
   int delvalue;
   cout<<"enter the value to be deleted:"<<endl;
   cin>>value;
   deletion();
   break;

   case 5:
   count();
    break;

    case 6:
    displayh_r();
    break;
    
    case 7:
    displayr_h();
    break;

    case 8:
     cout<<"enter the value to be searched:"<<endl;
   cin>>value;
    search(value);
    break;

    case 9:
    cout<<"enter the value to be inserted:"<<endl;
    cin>>value;
    searchr_h(value);
    break;

    case 10:
    empty_dll();
    break;

    case 11:
    destroy();
    break;




   }
}*/

order_insert(1);
order_insert(5);
order_insert(2);
order_insert(1);
order_insert(4);

deletion();
deletion();
deletion();

order_insert(5);
displayh_r();


return 0;
}

