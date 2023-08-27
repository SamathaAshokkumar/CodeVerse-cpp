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

struct arc{
    struct vertex *v_add;
    struct arc *link;
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


/*void insert_char(char source,char dest)
{
struct vertex *sour=(struct vertex*)malloc(sizeof(struct vertex));
struct vertex *desti=(struct vertex*)malloc(sizeof(struct vertex));
struct arc *p=(struct arc*)malloc(sizeof(struct arc));
struct arc *temp=(struct arc*)malloc(sizeof(struct arc));
sour=check_source(source);
cout<<sour->v<<endl;
desti=check_dest(dest);
cout<<desti->v<<endl;
p->v_add=desti;
p->link=NULL;
if(sour->arc_link==NULL)
{
sour->arc_link=p;
cout<<"arc inserted"<<endl;
}
else
{
temp=sour->arc_link;

while(temp->link!=NULL)
{
temp=temp->link;
}
temp->link=p;
cout<<"arc inserted"<<endl;
}
}*/
void insert_char(char s,char d)
{
    struct vertex *sour=(struct vertex*)malloc(sizeof(struct vertex));
    struct vertex *desti=(struct vertex*)malloc(sizeof(struct vertex));
    struct arc *p=(struct arc*)malloc(sizeof(struct arc));
    struct arc *source=(struct arc*)malloc(sizeof(struct arc));
     struct arc *temp=(struct arc*)malloc(sizeof(struct arc));
      struct arc *tempd=(struct arc*)malloc(sizeof(struct arc));
    sour=check_source(s);
    desti=check_dest(d);
    p->v_add=desti;
    p->link=NULL;
    source->v_add=sour;
    source->link=NULL;
    if(sour->arc_link==NULL)
    {
        sour->arc_link=p;
    }
    else
    {
       temp=sour->arc_link;
       while(temp->link!=NULL && temp->v_add->v!=d)
       {
         temp=temp->link;
       }
       if(temp->link==NULL && temp->v_add->v!=d)
       {
        temp->link=p;
       }
       else
       {

       }
    }
       if(desti->arc_link==NULL)
    {
        desti->arc_link=source;
    }
    else
    {
         tempd=desti->arc_link;
       while(tempd->link!=NULL && tempd->v_add->v!=s)
       {
         tempd=tempd->link;
       }
       if(tempd->link==NULL && tempd->v_add->v!=s)
       {
        tempd->link=source;
       }
       else
       {
         cout<<"the adjacency node is already present"<<endl;
       }

    }
}

void display()
{
     struct vertex *prev=(struct vertex*)malloc(sizeof(struct vertex));
    struct arc *temp=(struct arc*)malloc(sizeof(struct arc));
    prev=head;

    while(prev!=NULL)
    {
        /*if(prev->arc_link!=NULL)
        {
            cout<<"the adjacent list for the vertex "<<prev->data<<" are : "<<endl;
              // cout<<prev->data<<endl;
        }
        else
        {
            cout<<"the adjacent list for the vertex "<<prev->data<<" are : "<<endl;
             cout<<"there are no adjacent nodes"<<endl;
        }*/
        if(prev->arc_link==NULL)
        {
            cout<<"the adjacent list for the vertex "<<prev->v<<" are : "<<endl;
             cout<<"there are no adjacent nodes"<<endl;
             cout<<endl;
             prev=prev->v_link;
        }
        else
        {
            cout<<"the adjacent list for the vertex "<<prev->v<<" are : "<<endl;
       temp=prev->arc_link;
        while(temp!=NULL)
        {
            cout<<temp->v_add->v<<endl;
            temp=temp->link;
        }
      prev=prev->v_link;
        }
    }
    
   
}

/*void displa()
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
//cout<<list->v<<endl;
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
}*/

int push(char p[],int n,char q,int &k)
{
    if(k==n-1)
    {
        cout<<"stack is full"<<endl;
    }
    else
    {
        k++;
        p[k]=q;
    }
    return k;
}

int pop(char p[],char &q,int &k)
{
    if(k==-1)
    {
        cout<<"satck is empty"<<endl;

    }
    else
    {
        q=p[k];
        k--;

    }
    return k;
    //return q;
}

char stacktop(char p[],int &k,char &q)
{

    if(k==-1)
    {
        cout<<"satck is empty"<<endl;
    }
    else
    {
    q=p[k];
    }
    return k,q;
}

void dft()
{
    cout<<"the dft traversal of the graph is :"<<endl;
    int n=50;
    char p[n];
    char q;
    int k=-1;
   struct vertex *prev=(struct vertex*)malloc(sizeof(struct vertex));
      struct vertex *vertex=(struct vertex*)malloc(sizeof(struct vertex));

   struct arc *temp=(struct arc*)malloc(sizeof(struct arc));

   prev=head;
   while(prev!=NULL && prev->processed!=true)
   {
    push(p,n,prev->v,k);
    prev->visited=true;
    pop(p,q,k);
    prev->processed=true;
    cout<<prev->v<<endl;
   
    temp=prev->arc_link;

    if(temp!=NULL && temp->v_add->visited!=true)
    {
        //cout<<".."<<endl;
        prev=temp->v_add;
    }
    else if(temp!=NULL && temp->v_add->processed==true)
    {
        while(temp!=NULL && temp->v_add->processed==true)
        {
            temp=temp->link;
        }
        if(temp==NULL)
        {
            //cout<<".."<<endl;
             vertex=head;
        while(vertex!=NULL && vertex->processed==true && vertex->visited==true)
        {
            vertex=vertex->v_link;
        }
        prev=vertex;
        }
        else
        {
        prev=temp->v_add;
        }
    }
    /*while(temp!=NULL)
    {
        if(temp->v_add->visited!=true && temp->v_add->processed!=true)
        {
            prev=temp->v_add;
            temp=NULL;
            
        }
        else
        {
            temp=temp->link;
             
        }
    }
    if(temp==NULL)
    {*/
    else
    {
        //cout<<",,"<<endl;
       vertex=head;
        while(vertex!=NULL && vertex->processed==true && vertex->visited==true)
        {
            vertex=vertex->v_link;
        }
        prev=vertex;
    }
   } 
}

int main()
{
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



//display();
dft();
return 0;
}
