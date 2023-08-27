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
char color;
int cost;
struct dfs_list *l;
}*h[10];

void insert_vertex(char val)
{
//struct dfs_list *temp=(struct dfs_list*)malloc(sizeof(struct dfs_list));
struct dfs_para *temp=(struct dfs_para*)malloc(sizeof(struct dfs_para));

temp->value=val;
temp->pi='N';
temp->color='W';
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


struct dfs_para *extract_min()
{
int j=0;
int cost=999;
while(h[j]!=NULL)
{
   if(h[j]->color!='B')
   {

if(h[j]->cost<cost)
{
cost=h[j]->cost;
}
}

j++;
}
j=0;
while(h[j]!=NULL && h[j]->cost!=cost && h[j]->color!='W')
{
j++;
}
//cout<<h[i]->value<<endl;
return h[j];
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


void prims()
{
struct dfs_list *temp=(struct dfs_list*)malloc(sizeof(struct dfs_list));
struct dfs_para *p=(struct dfs_para*)malloc(sizeof(struct dfs_para));
struct dfs_para *t=(struct dfs_para*)malloc(sizeof(struct dfs_para));
h[0]->cost=0;
int i=0;

while(i<10)
{
t=extract_min();
//cout<<t->value<<endl;
temp=t->l;
while(temp!=NULL)
{
p=get_source(temp);
if(p->color=='W')
{
     if(temp->weight<p->cost)
     {
      p->cost=temp->weight;
      p->pi=t->value;
 }
}
temp=temp->link;
}
t->color='B';
i++;
}

}

int main()
{
int i=0;
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
cout<<endl;
insert_char('a','b',4);
insert_char('a','h',8);
insert_char('b','a',4);
insert_char('b','c',8);
     insert_char('b','h',11);
     insert_char('c','b',8);
     insert_char('c','d',7);
     insert_char('c','i',2);
     insert_char('c','f',4);
     insert_char('d','c',7);
     insert_char('d','e',9);
     insert_char('d','f',14);
     insert_char('e','d',9);
     insert_char('e','f',10);
     insert_char('f','c',4);
     insert_char('f','d',14);
     insert_char('f','e',10);
     insert_char('f','g',2);
     insert_char('g','h',1);
     insert_char('g','i',6);
     insert_char('g','f',2);
     insert_char('h','a',8);
     insert_char('h','b',11);
     insert_char('h','i',7);
     insert_char('h','g',1);
     insert_char('i','c',2);
     insert_char('i','h',7);
     insert_char('i','g',6);
   
       
     //insert_char('D','A');
//display();
prims();
int total_cost=0;
while(h[i]!=NULL)
{
cout<<h[i]->value<<"----->"<<h[i]->pi<<"  : "<<h[i]->cost<<endl;
total_cost=total_cost+h[i]->cost;
i++;
}

cout<<"the total cost is "<<total_cost<<endl;

return 0;
}


