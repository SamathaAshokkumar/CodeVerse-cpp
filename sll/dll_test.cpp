#include <iostream>
#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node * front;
    struct node * back;
};
struct headnode
{
    int count;
    struct node * head;
    struct node * rear;
};
void create(struct headnode**hnode)
{
   *hnode=(struct headnode *)malloc(sizeof(struct headnode));
   (*hnode)->head=NULL;
   (*hnode)->rear=NULL;
   (*hnode)->count=0;
}
int search(struct headnode * hnode , int target, struct node* pre,struct node* suc)
{
    int found=0;
    (pre)=NULL;
    (suc)=hnode->head;
   
      if(suc==NULL)
      {
        found =0;
      }
      else
      {
    while(suc->data!=target && suc->front!=NULL)
    {
     pre=suc;
     suc=suc->front;
    }
    

    if(suc->data==target )
    {
      cout<<"data found";
      found=1;
    }
    
    else
    {
        cout<<"no data found"<<endl;
        found=0;
        
    }
}
    return found ;
}

void insert(struct headnode * hnode,int value)
{
struct node *nnode;
nnode=(struct node*)malloc(sizeof(struct node));
nnode->front=NULL;
nnode->back=NULL;
nnode->data=value;
 
int flag;
  struct node *pre=NULL;
  struct node *suc=NULL;
  int target=value;


 
flag=search(hnode,target,pre,suc);
 
if(  flag==0)
{
    if(pre==NULL)
    {   nnode->back=NULL;
        nnode->front=hnode->head;
        hnode->head=nnode;
       
    }
      else
      {
          nnode->front=suc;
          nnode->back=pre;
          pre->front=nnode;
      }
      if(suc==NULL)
      {
          hnode->rear=nnode;
         
      }
        else
        {
            suc->back=nnode;
        }  
}

 }


int main()
{
    struct headnode *hnode;
    struct node *pre,*suc;
   create(&hnode);
   int data;
   //cout<<"enter data"<<endl;
   //cin>>data;
   insert(hnode,8);
   insert(hnode,9);
   insert(hnode,8);
   insert(hnode,9);
 
   int target;
   cin>>target;
   search(hnode,target,pre,suc);

    return 0;
}

