#include<iostream>
using namespace std;
struct arc;

struct vertex
{
    char data;
    struct vertex *v_link;
    struct arc *arc_link;
    bool visited=false;
    bool processed=false;
}*head=NULL;

struct arc
{
    struct vertex *v_add;
    struct arc *link;
};

void insert_vertex(char v)
{
    struct vertex *prev=(struct vertex*)malloc(sizeof(struct vertex));
    struct vertex *temp=(struct vertex*)malloc(sizeof(struct vertex));
    temp->data=v;
    temp->arc_link=NULL;
    temp->v_link=NULL;
    if(head==NULL)
    {
        head=temp;

    }
    else
    {
        prev=head;
        while(prev->v_link!=NULL && prev->data!=v)
        {
            prev=prev->v_link;
        }
        if(prev->data!=v)
        {
        prev->v_link=temp;
        }
        else{
            
        }
    }
}

struct vertex *check_source(char source)
{
     struct vertex *prev=(struct vertex*)malloc(sizeof(struct vertex));
     prev=head;
     while(prev->v_link!=NULL && prev->data!=source)
     {
        prev=prev->v_link;
     }
 return prev;
}

struct vertex *check_destination(char destination)
{
     struct vertex *prev=(struct vertex*)malloc(sizeof(struct vertex));
     prev=head;
     while(prev->v_link!=NULL && prev->data!=destination)
     {
        prev=prev->v_link;
     }
     if(prev->data==destination)
     {
 return prev;
     }
     else
     {
        return NULL;
     }
}

void insert_char(char s,char d)
{
    struct vertex *sour=(struct vertex*)malloc(sizeof(struct vertex));
    struct vertex *desti=(struct vertex*)malloc(sizeof(struct vertex));
    struct arc *p=(struct arc*)malloc(sizeof(struct arc));
    struct arc *source=(struct arc*)malloc(sizeof(struct arc));
     struct arc *temp=(struct arc*)malloc(sizeof(struct arc));
      struct arc *tempd=(struct arc*)malloc(sizeof(struct arc));
    sour=check_source(s);
    desti=check_destination(d);
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
       while(temp->link!=NULL && temp->v_add->data!=d)
       {
         temp=temp->link;
       }
       if(temp->link==NULL && temp->v_add->data!=d)
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
       while(tempd->link!=NULL && tempd->v_add->data!=s)
       {
         tempd=tempd->link;
       }
       if(tempd->link==NULL && tempd->v_add->data!=s)
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
            cout<<"the adjacent list for the vertex "<<prev->data<<" are : "<<endl;
             cout<<"there are no adjacent nodes"<<endl;
             cout<<endl;
             prev=prev->v_link;
        }
        else
        {
            cout<<"the adjacent list for the vertex "<<prev->data<<" are : "<<endl;
       temp=prev->arc_link;
        while(temp!=NULL)
        {
            cout<<temp->v_add->data<<endl;
            temp=temp->link;
        }
      prev=prev->v_link;
        }
    }
    
   
}

/*int insert(char p[],int n,char &q,int &front,int &rear)
{    
    if(rear==n-1)
    {
        cout<<"queue overflow!!"<<endl;
        cout<<endl;

    }
    else{
        if(front ==-1)
        {
            front++;
            p[front]=q;
        }
        rear++;
        p[rear]=q;
       //cout<<"element inserted!!"<<endl;
        
    }

     return rear;
        return front;
}

int insert(char p[],int n,char q,int &front,int &rear)
{
    if(front==-1)
    {
        front++;
        rear++;
        p[front]=q;
    }
    else
    {
        rear++;
        p[rear]=q;
    }
return front,rear;
}

char queue_front(char p[],char &q,int &front)
{
    if(front==-1)
    {
        cout<<"the queue is empty"<<endl;
    }
    else
    {
         q=p[front];
    }
    return front;
    return q;
}

int deletion(char p[],char &q,int &front,int &rear)
{
    if(front==-1)
    {
        cout<<"queue is empty"<<endl;
    }
    
    if(front==rear)
        {
            q=p[front];
            front=-1;
            rear=-1;
            //cout<<"element deleted!!"<<endl;
        }
        else
        {
        q=p[front];
       front++;
       //cout<<"element deleted"<<endl;
        }
    return front;
    return rear;
   return q;
}

void bft()
{
   int n=100;
   char p[n];
   char q;
   int front=-1;
   int rear=-1;
    struct vertex *prev=(struct vertex*)malloc(sizeof(struct vertex));
   struct vertex *vert=(struct vertex*)malloc(sizeof(struct vertex));
        struct arc *temp=(struct arc*)malloc(sizeof(struct arc));
    prev=head;
    while(prev!=NULL)
    {
        if(prev->processed!=true && prev->visited!=true)
        {
            insert(p,n,prev->data,front,rear);
            prev->visited=true;
            deletion(p,q,front,rear);
            cout<<"the vertex is : "<<q<<endl;
            prev->processed=true;
        }
        temp=prev->arc_link;

        while(temp!=NULL)
        {
            if(temp->v_add->visited!=true && temp->v_add->processed!=true)
            {
                insert(p,n,temp->v_add->data,front,rear);
                temp->v_add->visited=true;  
            }
            temp=temp->link;
        }

        if(front!=-1)
        {
           queue_front(p,q,front);
           deletion(p,q,front,rear);
            cout<<"the vertex is : "<<q<<endl;
           vert=head;
           while(vert->v_link!=NULL && vert->data!=q)
           {
            vert=vert->v_link;
            }
            vert->visited=true;
           vert->processed=true;
           prev=vert;
           
        }
        else
        {
            vert=head;
            while(vert!=NULL && vert->processed==true)
            {
                vert=vert->v_link;
            }
            prev=vert;
        }
    }

}*/

int push(char p[],char q,int n,int &k)
{
    if(k==n-1)
    {
       cout<<"the stack is full"<<endl;
    }
    else
    {
        k++;
        p[k]=q;
    }
    return k;
}

char pop(char p[],char &q,int &k)
{
    if(k==-1)
    {
        cout<<"the stack is empty"<<endl;
    }
    else
    {
        q=p[k];
        k--;
    }
    return q;
    return k;
}

void dft()
{

}
int main()
{
    insert_vertex('A');
    insert_vertex('B');
    insert_vertex('C');
    insert_vertex('D');
    insert_vertex('F');
    insert_vertex('E');
    insert_vertex('C');
    insert_vertex('S');
    insert_vertex('S');
    insert_char('A','D');
    insert_char('S','A');
    insert_char('D','A');
    insert_char('S','F');
    insert_char('E','A');
    insert_char('C','B');
    display();
    //bft();
}
