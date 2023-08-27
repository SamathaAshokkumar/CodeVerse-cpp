#include<iostream>
#include<stdlib.h>
#include<cstdlib>
#include<bits/stdc++.h>
#include<cstring>
#include<string.h>
using namespace std;

int i=0;
struct dfs_list
{
char data;
int weight;
struct dfs_list *link;
};

struct dfs_para
{
char value;
char pi;
int cost;
struct dfs_list *l;
}*h[10];

void insert_vertex(char val)
{
//struct dfs_list *temp=(struct dfs_list*)malloc(sizeof(struct dfs_list));
struct dfs_para *temp=(struct dfs_para*)malloc(sizeof(struct dfs_para));

temp->value=val;
temp->pi='N';
//temp->color='W';
//temp->s=0;
//temp->f=0;
temp->cost=999;
temp->l=NULL;

h[i]=temp;
i++;

//cout<<"vertex inserted!"<<endl;
}
void display()
{
//struct dfs_para *temp=(struct dfs_para*)malloc(sizeof(struct dfs_para));
struct dfs_list *pre=(struct dfs_list*)malloc(sizeof(struct dfs_list));
int j=0;
while(h[j]!=NULL)
{
  cout<<h[j]->value<<endl;
  pre=h[j]->l;
 
  while(pre!=NULL)
{
//cout<<"...."<<endl;
cout<<pre->data<<endl;
cout<<pre->weight<<endl;
pre=pre->link;
}
  j++;
}

//cout<<"..."<<endl;
}


struct dfs_para *check_source(char s)
{
int j=0;
while(h[j]!=NULL && h[j]->value!=s)
{
j++;
}
return h[j];
}

void insert_char(char s,char c,int wei)
{
struct dfs_list *pre=(struct dfs_list*)malloc(sizeof(struct dfs_list));
struct dfs_list *p=(struct dfs_list*)malloc(sizeof(struct dfs_list));
struct dfs_para *temp=(struct dfs_para*)malloc(sizeof(struct dfs_para));
pre->data=c;
pre->weight=wei;
pre->link=NULL;
temp=check_source(s);
//cout<<"the source is:"<<temp->value<<endl;
p=temp->l;
if(p==NULL)
{
temp->l=pre;
//cout<<p->data<<endl;

}
else
{
while(p->link!=NULL)
{
p=p->link;
}
p->link=pre;
}
}

struct dfs_para *get_source(struct dfs_list *g)
{
int k=0;
while(h[k]!=NULL && h[k]->value!=g->data)
{
k++;
}
return h[k];
}

void relax(struct dfs_para *temp,struct dfs_list *pre)
{
  struct dfs_para *t=(struct dfs_para*)malloc(sizeof(struct dfs_para));
  t=get_source(pre);
  if((temp->cost+pre->weight)<t->cost)
  {
    t->cost=temp->cost+pre->weight;
    t->pi=temp->value;
  }

}
bool rel(struct dfs_para *temp,struct dfs_list *pre)
{
  struct dfs_para *t=(struct dfs_para*)malloc(sizeof(struct dfs_para));
  t=get_source(pre);
  if((temp->cost+pre->weight)<t->cost)
  {
    return false;
  }
  else
  {
    return true;
  }

}

int check_weight(struct dfs_para *tm,struct dfs_para *te)
{
     struct dfs_list *pre=(struct dfs_list*)malloc(sizeof(struct dfs_list));
     pre=tm->l;
     while(pre!=NULL && pre->data!=te->value)
     {
      pre=pre->link;
     }
     return pre->weight;
}

void bellman_ford(int n)
{
  struct dfs_list *pre=(struct dfs_list*)malloc(sizeof(struct dfs_list));
    struct dfs_para *t=(struct dfs_para*)malloc(sizeof(struct dfs_para));

    int i=0,j=0,k=0;
    h[i]->cost=0;
 
     for(k=1;k<n;k++)
     {
      while(h[i]!=NULL)
      {
        pre=h[i]->l;
        while(pre!=NULL)
        {
        relax(h[i],pre);
        pre=pre->link;
        }
        i++;
      }
      i=0;
      }

        
    
    j=0;
    while(h[j]!=NULL)
    {
      pre=h[j]->l;
      while(pre!=NULL)
      {
       if(rel(h[j],pre))
       {
        pre=pre->link;
       }
       
       else
       {
        break;
        
       }
       
      }
      if(pre==NULL)
      {
        j++;
      }
      else
      {
        cout<<"there is no tree for this"<<endl;
        cout<<"THE NEGATIVE EDGED CYCLE IS :"<<endl;
        break;
        

      }
       
    }
   i=1;
   int weight=0;
   char d;
    while(h[i]!=NULL)
    {
      d=h[i]->pi;
      t=check_source(d);
      //cout<<t->value<<endl;
      weight=check_weight(t,h[i]);
      cout<<t->value<<"------>"<<h[i]->value<<"\t"<<weight<<endl;
      i++;
    }
   
}

int main()
{
  int n,e,wei;
  char val,v1,v2;
  cout<<"enter number of vertices :"<<endl;
  cin>>n;
  cout<<"enter the number of edges :"<<endl;
  cin>>e;
  for(int i=1;i<=n;i++)
  {
    cout<<"\nenter the vertice "<<i<<": ";
    cin>>val;
    insert_vertex(val);
  }
  for(int i=1;i<=e;i++)
  {
    cout<<"\nv1 :";
    cin>>v1;
    cout<<"\nv2 :";
    cin>>v2;
    cout<<"\nenter weight :";
    cin>>wei;
    insert_char(v1,v2,wei);
  }

  //display();
  /*insert_vertex('s');
  insert_vertex('t');
  insert_vertex('y');
  insert_vertex('x');
  insert_vertex('z');

  insert_char('s','t',6);
  insert_char('s','y',7);
  insert_char('t','y',8);
  insert_char('t','z',-4);
  insert_char('t','x',5);
  insert_char('y','z',9);
  insert_char('y','x',-3);
  insert_char('x','t',-2);
  insert_char('z','s',2);
  insert_char('z','x',7);*/
  bellman_ford(n);
  return 0;
}
