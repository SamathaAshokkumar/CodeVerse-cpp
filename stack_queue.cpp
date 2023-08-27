#include<iostream>
using namespace std;

int insert(int arr[],int arr1[],int value,int &front,int &rear,int &front1,int &rear1)
{
    if(front1==0)
    {
        front1++;
        rear1++;
       arr1[front1]=arr1[rear1]=value;

    }
    if(front1!=0)
    {
        rear1++;
        arr1[rear1]=value;
    }

   while(front!=0)
   {
    rear1++;
    arr1[rear1]=arr[front];
    front++;
   }
   front=0;
   rear=0;
   arr=0;
    
   
       /* while(front1!=0)
        {
            if(rear1==0)
            {
                front++;
                rear++;
                front=rear=arr[front1];
            }
            else{
                rear++;
                arr[rear]=arr[front1+1];
            }

            front1=0;
            rear1=0;
        }*/
       
       swap(arr1,arr);
return front,rear;
return front1,rear1;
    
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
    int arr[100],arr1[100];
    int front=0;
    int rear=0;
    int front1=0,rear1=0;
    insert(arr,arr1,2,front,rear,front1,rear1);
    insert(arr,arr1,3,front,rear,front1,rear1);
    display(arr,front,rear);
    return 0;
}