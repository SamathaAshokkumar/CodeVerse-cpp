#include<iostream>
using namespace std;
int insert(int arr[],int n,int value,int &front,int &rear)
{    
    if(rear==n-1)
    {
        cout<<"queue overflow!!"<<endl;
        cout<<endl;

    }
    else{
        if(front ==-1)
        {
            front++;
            arr[front]=value;
        }
        rear++;
        arr[rear]=value;
       cout<<"element inserted!!"<<endl;
        
    }

     return rear;
        return front;
}

int deletion(int arr[],int value,int &front,int &rear)
{
    if(front==-1)
    {
        cout<<"queue is empty"<<endl;
    }
    
    if(front==rear)
        {
            value=arr[front];
            front=-1;
            rear=-1;
            cout<<"element deleted!!"<<endl;
        }
        else
        {
        value=arr[front];
       front++;
       cout<<"element deleted"<<endl;
        }

       
    

    return front;
    return rear;
}

void queue_full(int arr[],int n,int front,int rear)
{
    if(rear==n-1)
    {
        cout<<"queue full"<<endl;
    }
    else{
        cout<<"queue is not full"<<endl;
    }
}

void queue_empty(int arr[],int front,int rear)
{
     if(front==-1)
    {
        cout<<"queue is empty"<<endl;
    }
    else{
        cout<<"queue is not empty"<<endl;
    }
}

void queue_front(int arr[],int front)
{
   if(front==-1)
   {
    cout<<"queue is empty"<<endl;
   }
   else{
    cout<<arr[front]<<endl;
    
   }
}

void queue_rear(int arr[],int front,int rear)
{
   if(front==-1)
   {
    cout<<"queue is empty"<<endl;
   }
   else{
    cout<<arr[rear]<<endl;
   }
}

void queue_count(int arr[],int front,int rear)
{
     if(front==-1)
   {
    cout<<"queue is empty"<<endl;
   }
   else{
    cout<<(rear-front)+1<<endl;
   }
}

void display(int arr[],int front,int rear)
{
    cout<<"the elements are:"<<endl;
    for(int i=front;i<=rear;i++)
    {
        cout<<arr[i]<<endl;
    }
}

int main()
{
    int n=100,arr[n],value;
    int front=-1;
    int rear=-1;
     int choice,j;
    cout<<"how many times do you  wanna perform operations:"<<endl;
    cin>>j;
   

for(int i=0;i<j;i++)
{
     cout<<"enter 1,2,3,4,5,6,7,8 for insert,deletion,queue_empty,queue_full,queu_front,queue_rear,queue_count,display" <<endl;
    cin>>choice;
    switch(choice)
    {
        case 1:
        cout<<"enter data:"<<endl;
        cin>>value;
        insert(arr,n,value,front,rear);
        break;

        case 2:
        cout<<"enter data:"<<endl;
        cin>>value;
        deletion(arr,value,front,rear);
        break;

        case 3:
       queue_empty(arr,front,rear);
       break;

        case 4:
        queue_full(arr,n,front,rear);
        break;
        
        case 5:
        queue_front(arr,front);
        break;

        case 6:
        queue_rear(arr,front,rear);
        break;

        case 7:
        queue_count(arr,front,rear);
        break;

        case 8:
        display(arr,front,rear);
        break;
    }

}
    
    return 0;
}