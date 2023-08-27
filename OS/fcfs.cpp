#include<stdio.h>
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

struct fcfs
{
int pid;
int at;
int bt;
struct fcfs *prev,*succ;

}*front=NULL,*rear=NULL;

/*void inqueue(int id,int arr_time,int burst_time)
{
struct fcfs *temp=(struct fcfs*)malloc(sizeof(struct fcfs));
temp->pid=id;
temp->at=arr_time;
temp->bt=burst_time;
temp->link=NULL;
if(front==NULL)
{
front=temp;
rear=temp;
}

else
{
struct fcfs *pre=(struct fcfs*)malloc(sizeof(struct fcfs));
pre=front;
if(rear->at<=temp->at)
{
    rear->link=temp;
    rear=temp;
}
else if(front->at>temp->at)
{
    front=temp;
    front->link=pre;
    
}
else
{
while(pre->link!=NULL && pre->at<temp->at)
{
   // if(pre->at<temp->at)
    //{
pre=pre->link;
    //}
    //else{
      //  break;
    //}
}
cout<<pre->at<<endl;
 if(pre->link==NULL)
{
pre->link=temp;
rear=temp;
}

else
{
   struct fcfs *p=(struct fcfs*)malloc(sizeof(struct fcfs)); 
   p=pre->link;
   pre->link=temp;
   temp->link=p;
}

}
}
cout<<"element inserted in queue"<<endl;
}*/

void inqueue(int id,int arr_time,int burst_time)
{
struct fcfs *temp=(struct fcfs*)malloc(sizeof(struct fcfs));
struct fcfs *prev=(struct fcfs*)malloc(sizeof(struct fcfs));

temp->pid=id;
temp->at=arr_time;
temp->bt=burst_time;
             if(front==NULL)
    {
        temp->prev=NULL;
        temp->succ=NULL;
        front=temp;
        rear=temp;
    }
    else
    {
             prev=front;
             if(prev->at>arr_time)
             {
                temp->prev=prev->prev;
                temp->succ=prev;
                prev->prev=temp;
                front=temp;
             }
            
            else if(front==rear)
            {
                if(front->at<arr_time)
                {
                    temp->prev=prev;
                    temp->succ=prev->succ;
                    prev->succ=temp;
                    rear=temp;
                }
            }
             else
             {
                
             while(prev->succ!=NULL && prev->at<=arr_time)
             {
                
                  prev=prev->succ;
               
             }

             //cout<<prev->data<<endl;
             prev=prev->prev;
             //cout<<prev->data<<endl;
        if(prev->succ->at<arr_time)
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



void dequeue()
{
    struct fcfs *pre=(struct fcfs*)malloc(sizeof(struct fcfs));
    if(front==NULL)
    {
        cout<<"the queue is empty"<<endl;
    }
    else
    {
        pre=front->succ;
        front=pre;

    }
}

void display()
{
    struct fcfs *temp=(struct fcfs*)malloc(sizeof(struct fcfs));
    temp=front;
   // int count=0;
   /*while(temp!=NULL)
    {
        cout<<temp->pid<<endl;
        temp=temp->link;
        count++;

    }
    cout<<count<<endl;*/
cout<<"id"<<"         "<<"at"<<"           "<<"bt"<<"             "<<"rt"<<"            "<<"tat"<<"           "<<"wt"<<endl;   
cout<<endl;
    int execution_time=0,idle_time=0,count=0;
    int tat=0,wt=0;
    float idle=0,exec_end=0;
   float avg_tat=0.0,avg_wt=0.0;
    while(temp!=NULL)
    {
        
        if(idle_time<temp->at)
        {
            //cout<<"the cpu is idle for :"<<temp->at-idle_time<<endl;
            idle=idle+(temp->at-idle_time);
            idle_time=temp->at-idle_time;
        }
        //idle_time=temp->at-idle_time;
        //idle_time=temp->at-idle_time;
        if(idle_time!=execution_time)
        {
           execution_time=execution_time+temp->bt+idle_time;
        }
        else
        {
             execution_time=temp->bt+idle_time;
        }
           tat=execution_time-temp->at;
           avg_tat=avg_tat+tat;
           wt=tat-temp->bt;
           avg_wt=avg_wt+wt;
              //cout<<"the process "<<temp->pid<<" starts executing : "<<execution_time-temp->bt<<endl;
              //cout<<"the process execution time :"<<execution_time<<endl;
            cout<<temp->pid<<"           "<<temp->at<<"           "<<temp->bt<<"             "<<execution_time-temp->bt<<"                "<<tat<<"           "<<wt<<endl;
            idle_time=execution_time;
          cout<<endl;
          exec_end=tat;
        temp=temp->succ;
        count++;
    }
    //cout<<count<<endl;
    cout<<"the execute time is :"<<exec_end-idle<<endl;
    cout<<"the exit time is :"<<exec_end<<endl;
    cout<<"the avg tat : "<<avg_tat/count<<endl;
    cout<<"the avg waiting time : "<<avg_wt/count<<endl;
    cout<<"the cpu utilization is : "<<((exec_end-idle)/exec_end)*100<<endl;
    cout<<"the idle time of cpu : "<<(idle/exec_end)*100<<endl;
}

void display_h()
{
   struct fcfs *temp=(struct fcfs*)malloc(sizeof(struct fcfs));
   temp=front;
   while(temp!=NULL)
   {
    cout<<temp->pid<<endl;
    temp=temp->succ;
   }
}

int main()
{
//cout<<".."<<endl;
inqueue(1,3,4);
inqueue(2,5,3);
inqueue(3,0,2);
inqueue(4,5,1);
inqueue(5,4,3);
//inqueue(5,0,2);
//dequeue();
//dequeue();
//dequeue();
//dequeue();
//display();
display_h();
return 0;
}

