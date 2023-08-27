#include<iostream>
using namespace std;

struct node 
{
    int data;
    struct node *link;
};

struct node *front=NULL,*rear=NULL;
void enqueue(int value)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    
    if(rear==NULL)
    {
        temp->data=value;
    temp->link=NULL;
        front=rear=temp;
    }
    else
    {
        temp->data=value;
    temp->link=NULL;
        rear->link=temp;
        rear=temp;
    }
    cout<<"element inserted"<<endl;
}

void dequeue()
{
    if(rear==NULL)
    {
        cout<<"queue is empty"<<endl;
    }
    else{
       struct node *prev=(struct node *)malloc(sizeof(struct node));
              struct node *temp=(struct node *)malloc(sizeof(struct node));

       prev=front;
       temp=prev->link;
       front=temp;
       free(prev);

    }
    cout<<"element deleted!!"<<endl;
}

void queuefront()
{
    if(front==NULL)
    {
        cout<<"queue is empty"<<endl;
    }
    else
    {
        cout<<"queue front is:"<<front->data<<endl;
    }
}

void queuerear()
{
    if(rear==NULL)
    {
        cout<<"queue is empty"<<endl;
    }
    else
    {
        cout<<"queue rear value is:"<<rear->data<<endl;
        
    }
}

void emptyqueue()
{
    if(rear==NULL)
    {
        cout<<"queue is empty"<<endl;
    }
    else{
        cout<<"queue is not empty!!"<<endl;
    }
    
}
void queuecount()
{
    int count=0;
              struct node *temp=(struct node *)malloc(sizeof(struct node));
              temp=front;
              while(temp->link!=NULL)
              {
                temp=temp->link;
                count++;
              }
    cout<<"queue count is:"<<count+1<<endl;
    cout<<endl;
}

void destroy()
{
    struct node *prev=(struct node *)malloc(sizeof(struct node));
              struct node *temp=(struct node *)malloc(sizeof(struct node));
              prev=front;
              while(prev->link!=NULL)
              {
                temp=prev->link;
                free(prev);
                prev=temp;
              }
              front=NULL;
              rear=NULL;
              cout<<"linked list is deleted!!"<<endl;
             
              
}
 
void display()
{
       struct node *temp=(struct node *)malloc(sizeof(struct node));
      
       if(front==NULL)
       {
        cout<<"queue is empty"<<endl;
       }
        
       else{
        cout<<"the elements are:"<<endl;
temp=front;
while(temp->link!=NULL)
{
    cout<<temp->data<<endl;
    temp=temp->link;
  
}
cout<<temp->data<<endl;
cout<<endl;
       }

}


int main()
{
    
      int choice,j,value;
    cout<<"how many times do you  wanna perform operations:"<<endl;
    cin>>j;
   

for(int i=0;i<=j;i++)
{
    int value;
     cout<<"enter 1,2,3,4,5,6,7,8 for enqueue,dequeue,queuefront,queuerear,emptyqueue,queuecount,display,destroy" <<endl;
    cin>>choice;
    switch(choice)
    {
      case 1:
      cout<<"enter data:"<<endl;
    cin>>value;
    enqueue(value);
     break;

     case 2:
     dequeue();
     break;

     case 3:
     queuefront();
     break;

     case 4:
     queuerear();
     break;
     
     case 5:
     emptyqueue();
     break;


     case 6:
     queuecount();
     break;

     case 7:
     display();
     break;

     case 8:
     destroy();

    }
}
    return 0;
}