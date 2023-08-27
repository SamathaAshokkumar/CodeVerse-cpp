#include<iostream>
#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;

struct sjf
{
    int pid,at,bt;
    int priority;
    struct sjf *prev,*succ;
}*front=NULL,*rear=NULL;

void inqueue(int id,int arr_time,int burst_time,int p)
{
struct sjf *temp=(struct sjf*)malloc(sizeof(struct sjf));
struct sjf *prev=(struct sjf*)malloc(sizeof(struct sjf));

temp->pid=id;
temp->at=arr_time;
temp->bt=burst_time;
temp->priority=p;
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
             if(prev->at==arr_time && prev->priority>temp->priority)
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

/*void swapping(int count)
{
    struct sjf *temp=(struct sjf*)malloc(sizeof(struct sjf));
struct sjf *prev=(struct sjf*)malloc(sizeof(struct sjf));
struct sjf *pre=(struct sjf*)malloc(sizeof(struct sjf));
struct sjf *p=(struct sjf*)malloc(sizeof(struct sjf));



int c=0;
temp=front;
while(temp->succ!=rear && c<count )
{
   prev=temp->succ;
   if(c==0)
   {
   if(temp->bt<pre->bt)
   {
    p=temp;
    temp=prev;
    p->succ=temp->succ;
    temp->succ=p;
    temp->prev=p->prev;
    p->prev=temp;
    p->succ->prev=p;
    front=temp;
    temp=temp->succ;
    cout<<"..."<<endl;
   
    c++;
   }
   else
   {
    temp=temp->succ;
     

    c++;
   }
   }
   else
   {
    if(temp->bt<pre->bt)
    {
         p=temp;
    temp=prev;
    p->succ=temp->succ;
    temp->succ=p;
    temp->prev=p->prev;
    p->prev=temp;
    if(temp->succ->succ!=NULL)
    {
    p->succ->prev=p;
    temp=temp->succ;
        cout<<",,,"<<endl;

    c++;
   }
    else
   {
       // rear=temp;
        temp=temp->succ;
        c++;
    }
    }
    
    


   }
}

if(front->bt>rear->bt)
{
    swap(front->at,rear->at);
    swap(front->bt,rear->bt);
    swap(front->pid,rear->pid);
    cout<<front->pid<<endl;
}

}*/


void deletion()
{
       
    if(front==NULL)
    {
        cout<<"the list is empty"<<endl;
    }
   /* else{
 struct sjf *temp=(struct sjf*)malloc(sizeof(struct sjf));
struct sjf *prev=(struct sjf*)malloc(sizeof(struct sjf));
              temp=front;
              while(temp->succ!=NULL)
              {
                temp=temp->succ;
              }
              
              prev=temp->prev;
              prev->succ=NULL;
              free(temp);
              rear=prev;


    }*/

    if(front==rear)
    {
        front=NULL;
        rear=NULL;
    }
    else
    {
        struct sjf *temp=(struct sjf*)malloc(sizeof(struct sjf));
struct sjf *prev=(struct sjf*)malloc(sizeof(struct sjf));

temp=front->succ;
temp->prev=NULL;
front=temp;


    }
   // cout<<"element deleted"<<endl;
    }

void displayh_r()
{
   
struct sjf *temp=(struct sjf*)malloc(sizeof(struct sjf));
//struct sjf *prev=(struct sjf*)malloc(sizeof(struct sjf));            
   temp=front;
    //cout<<temp->pid<<endl;
    if(front==NULL)
    {
        cout<<"the list is empty!!"<<endl;
    }
    else
    {
   while(temp!=NULL)
   {
    cout<<temp->pid<<endl;
    temp=temp->succ;
   }
}
}

void check_swap(int count)
{
        struct sjf *temp=(struct sjf*)malloc(sizeof(struct sjf));
struct sjf *prev=(struct sjf*)malloc(sizeof(struct sjf));
    struct sjf *pre=(struct sjf*)malloc(sizeof(struct sjf));
struct sjf *p=(struct sjf*)malloc(sizeof(struct sjf));
temp=front;
int c=0;

while(temp->succ!=NULL && c<count)
{
    prev=temp->succ;
  if(c==0)
  {
    if(temp->priority>prev->priority)
    {
       swap(temp->pid,prev->pid);
       swap(temp->at,prev->at);
       swap(temp->bt,prev->bt);
       swap(temp->priority,prev->priority);
      front=temp;
      temp=temp->succ;
      c++;
    }
    else
    {
        temp=temp->succ;
        c++;
    }
  }
  else
  {
    if(temp->priority>prev->priority)
    {
       swap(temp->pid,prev->pid);
       swap(temp->at,prev->at);
       swap(temp->bt,prev->bt);
              swap(temp->priority,prev->priority);

       temp=temp->succ;
       c++;
  }
  else
  {
    temp=temp->succ;
    c++;

  }
}
}

/*if(front->bt>rear->bt)
{
    swap(front->at,rear->at);
    swap(front->bt,rear->bt);
    swap(front->pid,rear->pid);
    //cout<<front->pid<<endl;
}*/

}
void display(int n)
{
    int counter=0;
    int check_bt=0;
            struct sjf *temp=(struct sjf*)malloc(sizeof(struct sjf));
            struct sjf *pre=(struct sjf*)malloc(sizeof(struct sjf));
    temp=front;
    cout<<"id"<<"         "<<"at"<<"           "<<"bt"<<"             "<<"rt"<<"            "<<"tat"<<"           "<<"wt"<<endl;   
cout<<endl;
    int execution_time=0,idle_time=0,count=0;
    int tat=0,wt=0;
    float idle=0,exec_end=0;
   float avg_tat=0.0,avg_wt=0.0;
    while(temp!=NULL && count<=n)
    {
        if(count==0)
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
          check_bt=check_bt+temp->bt;
           deletion();
        temp=front;
        count++;
        //cout<<check_bt<<endl;
        //counter++;
    }
    else
    {
        counter=0;
        while(temp!=NULL && temp->at<=check_bt)
        {
           temp=temp->succ;
           counter++;
        }
        if(temp==NULL)
        {
            counter++;
        }
        for(int i=0;i<counter;i++)
        {
       check_swap(counter-1);
        }
       //displayh_r();
       temp=front;
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
          check_bt=check_bt+temp->bt;
           deletion();
        temp=front;
        count++;
        //counter++;

    }
    }
    //cout<<count<<endl;
    cout<<"the execute time is :"<<exec_end-idle<<endl;
    cout<<"the exit time is :"<<exec_end<<endl;
    cout<<"the avg tat : "<<avg_tat/count<<endl;
    cout<<"the avg waiting time : "<<avg_wt/count<<endl;
    cout<<"the cpu utilization is : "<<((exec_end-idle)/exec_end)*100<<endl;
    cout<<"the idle time of cpu : "<<(idle/exec_end)*100<<endl;
}



int main()
{
inqueue(1,0,6,1);
inqueue(2,1,4,4);
inqueue(3,4,2,2);
inqueue(4,0,1,1);
inqueue(5,1,3,3);
int n=6;
/*int n,pid,at,bt;
cout<<"enter n:"<<endl;
cin>>n;
for(int i=0;i<n;i++)
{
    cout<<"enter process id:"<<endl;
    cin>>pid;
    cout<<"enter process at:"<<endl;
    cin>>at;
    cout<<"enter process bt:"<<endl;
    cin>>bt;
    inqueue(pid,at,bt);
}*/
//deletion();
//swapping(5);
/*for(int i=0;i<=4;i++)
{
check_swap(4);
}*/
//displayh_r();
display(n);

return 0;
}