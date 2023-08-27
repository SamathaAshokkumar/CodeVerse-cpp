#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct arc;
struct vertex
{
char v;
struct vertex *v_link;
struct arc *arc_link;
bool visited;
bool processed;
}*head=NULL;

struct arc
{
struct vertex *v_add;
struct arc *link;
//bool visited;
};

void insert_vertex(char val)
{
struct vertex *temp=(struct vertex*)malloc(sizeof(struct vertex));
temp->v=val;
temp->arc_link=NULL;
temp->v_link=NULL;
if(head==NULL)
{
head=temp;
temp->v_link=NULL;
}

else
{
struct vertex *prev=(struct vertex*)malloc(sizeof(struct vertex));
prev=head;
while(prev->v_link!=NULL)
{
prev=prev->v_link;
}
prev->v_link=temp;
}
cout<<"vertex inserted!"<<endl;
}

struct vertex *check_source(char s)
{
struct vertex *prev=(struct vertex*)malloc(sizeof(struct vertex));
prev=head;
while(prev!=NULL && prev->v!=s)
{
prev=prev->v_link;
}
return prev;
}

struct vertex *check_dest(char d)
{
struct vertex *prev=(struct vertex*)malloc(sizeof(struct vertex));
prev=head;
while(prev!=NULL && prev->v!=d)
{
prev=prev->v_link;
}
if(prev->v==d)
{
return prev;
}
else
{
return NULL;
}
return prev;
}


void insert_char(char source,char dest)
{
struct vertex *sour=(struct vertex*)malloc(sizeof(struct vertex));
struct vertex *desti=(struct vertex*)malloc(sizeof(struct vertex));
struct arc *p=(struct arc*)malloc(sizeof(struct arc));
struct arc *temp=(struct arc*)malloc(sizeof(struct arc));
sour=check_source(source);
//cout<<sour->v<<endl;
desti=check_dest(dest);
//cout<<desti->v<<endl;
p->v_add=desti;
p->link=NULL;
if(sour->arc_link==NULL)
{
sour->arc_link=p;
//cout<<"arc inserted"<<endl;
}
else
{
temp=sour->arc_link;

while(temp->link!=NULL)
{
temp=temp->link;
}
temp->link=p;
//cout<<"arc inserted"<<endl;
}
}

int push(char p[],int n,char q,int &k)
{
if(k==n-1)
{
cout<<"stack is full!"<<endl;
//return k;
}
else
{
k++;
p[k]=q;

}
return k;
}

int pop(char p[],int &k,char &q)
{
if(k==-1)
{
cout<<"stack is empty"<<endl;
//return k;
}
else
{
  q=p[k];
k--;
//cout<<q<<endl;

}
return k;
//cout<<q<<endl;
}

char stacktop(char p[],int &k,char &q)
{
if(k==-1)
{
//cout<<"stack is empty"<<endl;
return k;
}
else
{

q=p[k];
return k;
}
//}
return k,q;
}
void dft()
{
  cout<<"the depth first traversal order of the adjacency list is : "<<endl;
    int n=50;
    int k=-1;
    char p[n];
    char q;
    struct vertex *prev=(struct vertex*)malloc(sizeof(struct vertex));
    struct vertex *vertex=(struct vertex*)malloc(sizeof(struct vertex));
    struct arc *temp=(struct arc*)malloc(sizeof(struct arc));
    prev=head;
    while(prev!=NULL && prev->processed!=true)
    {
      //cout<<".."<<endl;
      push(p,n,prev->v,k);
      prev->visited=true;
       pop(p,k,q);
      cout<<"the vertex is : "<<q<<endl;
      prev->processed=true;
      temp=prev->arc_link;
    while(temp!=NULL && temp->v_add->visited!=true && temp->v_add->processed!=true)
    {
      push(p,n,temp->v_add->v,k);
      temp->v_add->visited=true;
      temp=temp->link;
    }
    if(k!=-1)
    {
      //cout<<".."<<endl;
    stacktop(p,k,q);
    //cout<<q<<endl;
    pop(p,k,q);
    vertex=head;
    while(vertex!=NULL && vertex->v!=q)
    {
      vertex=vertex->v_link;
    }
  prev=vertex;
    }
    else{
      //cout<<"..."<<endl;
      vertex=head;
      while(vertex!=NULL && vertex->visited==true)
      {
        vertex=vertex->v_link;

    }
    prev=vertex;
    //cout<<prev->v<<endl;
   //pop(p,k,q);
    }
}
}
void display()
{
struct vertex *list=(struct vertex*)malloc(sizeof(struct vertex));
struct arc *adj=(struct arc*)malloc(sizeof(struct arc));
list=head;
while(list!=NULL)
{
if(list->arc_link!=NULL)
{
cout<<"the adjacent list for the vertex "<<list->v<<" are : "<<endl;
cout<<list->v<<endl;
}
else
{
cout<<"the adjacent list for the vertex "<<list->v<<" are : "<<endl;
cout<<list->v<<endl;
}
adj=list->arc_link;
while(adj!=NULL)
{
//cout<<"..."<<endl;
cout<<adj->v_add->v<<endl;
adj=adj->link;
}
list=list->v_link;
}
}


int main()
{
/*insert_vertex('A');
insert_vertex('B');
insert_vertex('C');
insert_vertex('D');
insert_vertex('E');
insert_vertex('F');
insert_vertex('G');
insert_vertex('H');
insert_vertex('S');
insert_vertex('P');
insert_vertex('V');
//insert_vertex('b');
insert_char('A','B');
insert_char('A','C');
insert_char('A','D');
insert_char('B','H');
insert_char('C','B');
insert_char('C','E');
insert_char('C','F');
insert_char('S','V');
insert_char('P','F');
insert_char('D','F');
insert_char('E','F');
insert_char('G','F');
insert_char('H','F');
insert_char('V','S');
insert_char('F','A');
insert_char('F','C');
insert_char('F','S');
display();
dft();
struct vertex *prev=(struct vertex*)malloc(sizeof(struct vertex));
prev=head;
while(prev!=NULL)
{
  prev->visited=false;
  prev->processed=false;
  prev=prev->v_link;
}
bft();*/
/*int j;
    int choice;
    cout<<"how many times do you  wanna perform operations:"<<endl;
    cin>>j;

    for(int i=0;i<=j;i++)
{
    cout<<"enter 1,2,3,4 for inserting vertex,inserting edges,bst,dft" <<endl;
    cin>>choice;
   switch(choice)
   {
    case 1:
    int num_of_vertices;
    cout<<"enter how many vertices you wanna enter : "<<endl;
    cin>>num_of_vertices;
    for(int j=0;j<=num_of_vertices;j++)
    {
      char a;
      cout<<"enter the vertex: "<<endl;
      cin>>a;
       insert_vertex(a);
    }
    break;

    case 2:
    int num_of_edges;
    cout<<"enter how many eges you wanna add: "<<endl;
    cin>>num_of_edges;
    char source,destination;
    for(int j=0;j<=num_of_edges;j++)
    {
         cout<<"enter the source : "<<endl;
    cin>>source;
    cout<<"enter the desitination : "<<endl;
    cin>>destination;
      insert_char(source,destination);

    }
    break;


 case 3:
    display();
break;

    case 4:
struct vertex *p=(struct vertex*)malloc(sizeof(struct vertex));
p=head;
while(p!=NULL)
{
  p->visited=false;
  p->processed=false;
  p=p->v_link;
}
dft();
break;


   }

}*/
insert_vertex('A');
insert_vertex('B');
insert_vertex('C');
insert_vertex('D');
insert_vertex('E');
insert_vertex('F');
insert_vertex('G');
insert_vertex('H');
insert_vertex('S');

insert_char('A','B');
insert_char('A','S');
insert_char('B','A');
insert_char('C','D');
insert_char('C','E');
insert_char('C','F');
insert_char('C','S');
insert_char('D','C');
insert_char('E','C');
insert_char('E','H');
insert_char('F','C');
insert_char('F','G');
insert_char('G','F');
insert_char('G','H');
insert_char('G','S');
insert_char('H','E');
insert_char('H','G');
insert_char('S','A');
insert_char('S','C');
insert_char('S','G');
display();
dft();
return 0;
}

