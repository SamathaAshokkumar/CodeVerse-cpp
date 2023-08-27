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
struct dfs_list *link;
};

struct topo
{
char d;
struct topo *p;
}*head=NULL;

struct dfs_para
{
char value;
char pi;
char color;
int s,f;
struct dfs_list *l;
}*h[10];

void insert_vertex(char val)
{
//struct dfs_list *temp=(struct dfs_list*)malloc(sizeof(struct dfs_list));
struct dfs_para *temp=(struct dfs_para*)malloc(sizeof(struct dfs_para));

temp->value=val;
temp->pi='N';
temp->color='W';
temp->s=0;
temp->f=0;
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

void insert_char(char s,char c)
{
struct dfs_list *pre=(struct dfs_list*)malloc(sizeof(struct dfs_list));
struct dfs_list *p=(struct dfs_list*)malloc(sizeof(struct dfs_list));
struct dfs_para *temp=(struct dfs_para*)malloc(sizeof(struct dfs_para));
pre->data=c;
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

void dfs_visit(struct dfs_para *temp,struct dfs_list *pre,int time)
{
struct dfs_para *tem=(struct dfs_para*)malloc(sizeof(struct dfs_para));
//struct dfs_list *t=(struct dfs_list*)malloc(sizeof(struct dfs_list));
//cout<<temp->value<<endl;

int j=0;
temp->color='G';
time=time+1;
temp->s=time;

//pre=temp->l;

while(pre!=NULL)
{
//cout<<"pre value"<<pre->data<<endl;
tem=get_source(pre);
if(tem->color=='W')
{
tem->pi=temp->value;
dfs_visit(tem,tem->l,time);
}
pre=pre->link;
}

  temp->color='B';
  time=time+1;
  temp->f=time;
  struct topo *t=(struct topo*)malloc(sizeof(struct topo));
    struct topo *to=(struct topo*)malloc(sizeof(struct topo));

    t->d=temp->value;
    t->p=NULL;
    if(head==NULL)
    {
    head=t;  
}
else
{
to=head;
head=t;
head->p=to;
//to=head;

}
 

}

void dfs(int n)
{
int time=0;
int j=0;
while(j<n)
{
  //cout<<h[j]->color<<endl;
if(h[j]->color=='W')
{
//cout<<".."<<endl;
dfs_visit(h[j],h[j]->l,time);
}
j++;
}
}
void topological_sort(int n)
{
dfs(n);
  struct topo *temp=(struct topo*)malloc(sizeof(struct topo));
          temp=head;
          while(temp!=NULL)
          {
          cout<<temp->d<<endl;
          temp=temp->p;
          }
 
}

int main()
{
  /*int n,e;
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
    insert_char(v1,v2);
  }*/

insert_vertex('a');
insert_vertex('b');
insert_vertex('c');
insert_vertex('d');
insert_vertex('e');
insert_vertex('f');
insert_vertex('g');
insert_vertex('h');
insert_vertex('i');
//insert_vertex('D');

//display();
insert_char('a','b');
insert_char('a','d');
insert_char('a','f');
insert_char('b','c');
     insert_char('c','h');
     insert_char('d','e');
     insert_char('e','f');
     insert_char('e','g');
     insert_char('f','i');
     insert_char('f','g');
     insert_char('f','h');
     insert_char('g','i');
     insert_char('h','i');
     //insert_char('D','A');
//display();

topological_sort(9);

//cout<<time<<endl;
return 0;
}

