#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

struct srt
{
    int pid,at,bt;
    struct srt *prev,*succ;
}*front=NULL,*rear=NULL;

struct st
{
    int pid,bt;
    struct st *p;

}*f=NULL;


void enqueue(int pid,int bt)
{
    struct st *temp=(struct st*)malloc(sizeof(struct st));
    temp->pid=pid;
    temp->bt=bt;
    temp->p=NULL;
    if(f==NULL)
    {
        f=temp;

    }
    else
    {
            struct st *pre=(struct st*)malloc(sizeof(struct st));
  pre=f;
  while(pre->p!=NULL)
  {
     pre=pre->p;
  }
  pre->p=temp;
    }
   // cout<<"element inserted in enqueue"<<endl;

}

void inqueue(int id,int arr_time,int burst_time)
{
struct srt *temp=(struct srt*)malloc(sizeof(struct srt));
struct srt *prev=(struct srt*)malloc(sizeof(struct srt));

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
                //cout<<front->pid<<endl;
                //cout<<front->succ->pid<<endl;
                //cout<<front->succ->succ->pid<<endl;
             }
             
             /*if(prev->at==arr_time)
             {
                if(prev->bt>temp->bt)
                {
                    temp->prev=prev->prev;
                temp->succ=prev;
                prev->prev=temp;
                front=temp;
                }
                else
                {
                    temp->succ=prev->succ;
                    temp->prev=prev;
                    prev->succ=temp;
                    front=prev;
                }
             }*/
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
             //cout<<"element inserted in ordered search list!!"<<endl;
}



void deletion()
{
       
    if(front==rear)
    {
        //cout<<"the list is empty"<<endl;
        front=rear=NULL;
    }
   else{
 struct srt *temp=(struct srt*)malloc(sizeof(struct srt));
struct srt *prev=(struct srt*)malloc(sizeof(struct srt));
              temp=front;
              //cout<<temp->pid<<endl;
            prev=temp->succ;
            //cout<<prev->pid<<endl;
            prev->prev=NULL;
              
              //free(temp);
              front=prev;

   //cout<<"deleted"<<endl;
    }

   
   /* else
    {
        struct srt *temp=(struct srt*)malloc(sizeof(struct srt));
struct srt *prev=(struct srt*)malloc(sizeof(struct srt));

temp=front->succ;
temp->prev=NULL;
front=temp;


    }*/
   // cout<<"element deleted"<<endl;
    }

void displayh_r()
{
   
struct srt *temp=(struct srt*)malloc(sizeof(struct srt));
//struct sjf *prev=(struct sjf*)malloc(sizeof(struct sjf));            
   temp=front;
    //cout<<temp->pid<<endl;
    if(front==NULL)
    {
        cout<<"display-the list is empty!!"<<endl;
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


int bt(int pid)
{
    int t;
    struct st *tem=(struct st*)malloc(sizeof(struct st));
    tem=f;
    if(f==NULL)
    {
        cout<<"bt_function-the list is empty"<<endl;
    }
    while(tem->p!=NULL && tem->pid!=pid)
    {
        tem=tem->p;
    }
  t=tem->bt;
  //cout<<t<<endl;
  return t;

}

void check_swap(int count)
{
        struct srt *temp=(struct srt*)malloc(sizeof(struct srt));
struct srt *prev=(struct srt*)malloc(sizeof(struct srt));
    struct srt *pre=(struct srt*)malloc(sizeof(struct srt));
struct srt *p=(struct srt*)malloc(sizeof(struct srt));
temp=front;
int c=0;

while(temp->succ!=NULL && c<count)
{
    prev=temp->succ;
  if(c==0)
  {
    if(temp->bt>prev->bt)
    {
       swap(temp->pid,prev->pid);
       swap(temp->at,prev->at);
       swap(temp->bt,prev->bt);
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
    if(temp->bt>prev->bt)
    {
       swap(temp->pid,prev->pid);
       swap(temp->at,prev->at);
       swap(temp->bt,prev->bt);
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



/*void check_srt(int pid,int execution,int at,int bt)
{
     int execution_time=execution,idle_time=0,count=0;
    int tat=0,wt=0;
    float idle=0,exec_end=0;
   float avg_tat=0.0,avg_wt=0.0;
   int btime;

tat=execution_time-at;
           avg_tat=avg_tat+tat;
           wt=tat-bt;
           avg_wt=avg_wt+wt;
              //cout<<"the process "<<temp->pid<<" starts executing : "<<execution_time-temp->bt<<endl;
              //cout<<"the process execution time :"<<execution_time<<endl;
            cout<<pid<<"           "<<at<<"           "<<bt<<"             "<<execution_time-bt<<"                "<<tat<<"           "<<wt<<endl;
            idle_time=execution_time;
          cout<<endl;
          exec_end=tat;
}

void display(int n)
{
    int counter=0;
    int check_bt=0;
            struct srt *temp=(struct srt*)malloc(sizeof(struct srt));
            struct srt *pre=(struct srt*)malloc(sizeof(struct srt));
    temp=front;
    cout<<"id"<<"         "<<"at"<<"           "<<"bt"<<"             "<<"rt"<<"            "<<"tat"<<"           "<<"wt"<<endl;   
cout<<endl;
    int execution_time=0,idle_time=0,count=0;
    int tat=0,wt=0,time=0;
    float idle=0,exec_end=0;
   float avg_tat=0.0,avg_wt=0.0;
   int btime;
    while(temp!=NULL )
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
           execution_time=execution_time+1+idle_time;
        }
        else
        {
             execution_time=1+idle_time;
        }
           //tat=execution_time-temp->at;
           //avg_tat=avg_tat+tat;
           //wt=tat-temp->bt;
           //avg_wt=avg_wt+wt;
          //check_bt=check_bt+1;
          btime=temp->bt-1;
           //idle_time=execution_time;
          //exec_end=tat;
          if(btime==0)
          {
           check_srt(temp->pid,execution_time,temp->at,temp->bt);
           avg_tat=avg_tat+tat;
           wt=tat-temp->bt;
           avg_wt=avg_wt+wt;
           deletion();
          }
          else
          {
            deletion();
            inqueue(temp->pid,temp->at,btime);
          }

          if(btime==0)
          {

          }
        temp=front;
        count++;
        //counter++;
    }
    else
    {
        counter=0;
        //cout<<check_bt<<endl;
        //cout<<endl;
        while(temp!=NULL && temp->at<=check_bt)
        {
            temp=temp->succ;
            counter++;

        }
        if(temp==NULL)
        {
            counter++;
        }
        //cout<<counter<<endl;
        //cout<<endl;
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
           execution_time=execution_time+1+idle_time;
        }
        else
        {
             execution_time=1+idle_time;
        }
        tat=execution_time-temp->at;
           //avg_tat=avg_tat+tat;
           //wt=tat-temp->bt;
           //avg_wt=avg_wt+wt;
          check_bt=check_bt+1;
          btime=temp->bt-1;
           idle_time=execution_time;
          exec_end=tat;
           
          check_bt=check_bt+1;
          btime=temp->bt-1;
          inqueue(temp->pid,temp->at,btime);
          if(temp->bt==0)
          {
           check_srt(temp->pid,execution_time,temp->at,temp->bt);
           avg_tat=avg_tat+tat;
           wt=tat-temp->bt;
           avg_wt=avg_wt+wt;
           deletion();
          }
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
}*/


void display_f()
{
    struct st *tem=(struct st*)malloc(sizeof(struct st));
    tem=f;
    while(tem!=NULL)
    {
        cout<<tem->pid<<endl;
        tem=tem->p;
    }
}

void display(int n)
{//burst,btime,check_bt
    int counter=0;
    int check_bt=0,c=0;
    int burst;
     struct srt *temp=(struct srt*)malloc(sizeof(struct srt));
struct srt *prev=(struct srt*)malloc(sizeof(struct srt));
    temp=front;
    int execution_time=0,idle_time=0,count=0;
    int tat=0,wt=0,time=0;
    float idle=0,exec_end=0;
   float avg_tat=0.0,avg_wt=0.0;
    cout<<"id"<<"         "<<"at"<<"           "<<"bt"<<"             "<<"rt"<<"            "<<"tat"<<"           "<<"wt"<<endl;   
cout<<endl;
int btime=0;
  while(temp!=NULL )
  {
    if(count==0)
    {
        if(idle_time<temp->at)
        {
            idle=idle+(temp->at-idle_time);
            idle_time=temp->at-idle_time;
        }

        if(idle_time!=execution_time)
        {
            execution_time=execution_time+1+idle_time;
        }
        else
        {
            execution_time=1+idle_time;
        }

          btime=temp->bt-1;
          burst=bt(temp->pid);
          
          if(btime==0)
          {
            tat=execution_time-temp->at;
            avg_tat=avg_tat+tat;
            wt=tat-burst;
            avg_wt=avg_wt+wt;
            check_bt=check_bt+1;
            idle_time=execution_time;
            exec_end=exec_end+tat;
                        cout<<temp->pid<<"           "<<temp->at<<"           "<<burst<<"             "<<execution_time-temp->bt<<"                "<<tat<<"           "<<wt<<endl;

            deletion();
          }
          else
          {
            //tat++;
            //avg_tat++;
            //exec_end=exec_end+1;
            idle_time=idle_time+1;
            check_bt=check_bt+1;
            //c=bt;
            deletion();
            inqueue(temp->pid,temp->at,btime);
            //displayh_r();
            
          }
         temp=front;
         count++;
    }
    else
    {
        //cout<<count<<endl;
        counter=0;
        while(temp!=NULL && temp->at<=check_bt)
        {
           temp=temp->succ;
           counter++;
           //cout<<counter<<endl;
        }
        if(temp==NULL)
        {
            counter++;
        }
        for(int i=0;i<counter;i++)
        {
            check_swap(counter-1);
        }
        temp=front;
        prev=temp;
    if(idle_time<temp->at)
        {
            idle=idle+(temp->at-idle_time);
            idle_time=temp->at-idle_time;
        }
        
        if(idle_time!=execution_time)
        {
            execution_time=execution_time+1+idle_time;
        }
        else
        {
            execution_time=1+idle_time;
        }
         btime=temp->bt-1;
         //cout<<temp->pid<<endl;
          //c++;
          if(btime==0)
          {
            tat=execution_time-temp->at;
            avg_tat=avg_tat+tat;
            wt=tat-bt(temp->pid);
            avg_wt=avg_wt+wt;
            check_bt=check_bt+1;
            idle_time=execution_time;
            exec_end=exec_end+tat;
                        cout<<temp->pid<<"           "<<temp->at<<"           "<<bt(temp->pid)<<"             "<<execution_time-temp->bt<<"                "<<tat<<"           "<<wt<<endl;

            deletion();
            
          }
          else
          {
            //tat++;
            //avg_tat++;
            //exec_end=exec_end+1;
            idle_time=idle_time+1;
            check_bt=check_bt+1;
            deletion();
            //cout<<prev->pid<<endl;
            inqueue(temp->pid,temp->at,btime);
            //cout<<"displayh"<<endl;
            //displayh_r();
          }
         temp=front;
         count++;
    }
  }
   cout<<"the execute time is :"<<execution_time-idle<<endl;
    cout<<"the exit time is :"<<execution_time<<endl;
    cout<<"the avg tat : "<<avg_tat/n<<endl;
    cout<<"the avg waiting time : "<<avg_wt/n<<endl;
    cout<<"the cpu utilization is : "<<((execution_time-idle)/execution_time)*100<<endl;
    cout<<"the idle time of cpu : "<<(idle/execution_time)*100<<endl;
}


int main()
{
inqueue(1,0,5);
inqueue(2,6,1);
inqueue(3,7,2);
inqueue(4,7,1);
inqueue(5,8,3);
enqueue(1,5);
enqueue(2,1);
enqueue(3,2);
enqueue(4,1);
enqueue(5,3);
int n=5;
/*int pid,at,bt;
cout<<"enter number of processes:"<<endl;
cin>>n;
for(int i=0;i<n;i++)
{
    cout<<"enter the process id :"<<endl;
    cin>>pid;
    cout<<"enter the process arrival time :"<<endl;
    cin>>at;
    cout<<"enter the process burst time :"<<endl;
    cin>>bt;
    inqueue(pid,at,bt);
    enqueue(pid,bt);
}*/

//int n=3;
/*inqueue(1,0,8);
inqueue(2,1,4);
inqueue(3,2,9);
inqueue(4,3,5);
enqueue(1,8);
enqueue(2,4);
enqueue(3,9);
enqueue(4,5);*/

//displayh_r();

/*deletion();
deletion();
deletion();
displayh_r();

inqueue(5,1,2);
displayh_r();*/
//display_f();
display(n);

return 0;
}