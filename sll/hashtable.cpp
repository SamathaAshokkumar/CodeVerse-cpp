#include<iostream>
using namespace std;
struct node 
{
    int data;
    int div;
    //struct node *prev;
    struct node *link;
}*head[10];

void insert(int num,int div)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
        struct node *prev=(struct node*)malloc(sizeof(struct node));
                struct node *h=(struct node*)malloc(sizeof(struct node));


    int i =0;
    int rem=num%div;
    temp->data=num;
    temp->div=div;
    temp->link=NULL;
    
    //temp->div=div;
    /*if(head[i]==NULL)
    {
        head[i]->data=rem;
        head[i]->link=temp;
    }
    else{*/
       while(head[i]!=NULL && head[i]->data!=rem)
        {
            i++;
        }
        cout<<i<<endl;
        if(head[i]==NULL)
        {
            h=head[i];
            h->data=rem;
           h->link=temp;
        }
        else{
            prev=head[i];
            while(prev->link!=NULL)
            {
                prev=prev->link;
            }
            prev->link=temp;
            
        }
    }

//}

void display(int r)
{
   struct node *prev=(struct node*)malloc(sizeof(struct node));
  int i=0;
  while(head[i]!=NULL && head[i]->data!=r)
  {
    i++;
  }
  if(head[i]->data==r)
  prev=head[i]->link;
  while(prev->link!=NULL)
  {
    cout<<"the numbers and divisors for a remainder r are follows : "<<endl;
    cout<<"the number is : "<<prev->data<<endl;
    cout<<"the divisor is : "<<prev->div<<endl;
  }
}

int main()
{
    insert(10,5);
    insert(11,5);
    insert(12,5);
    insert(4,2);
    insert(4,3);
    insert(30,4);
    display(0);

    return 0;
}
