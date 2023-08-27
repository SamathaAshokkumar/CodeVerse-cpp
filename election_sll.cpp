#include<iostream>
#include<string.h>
#include<cstring>
using namespace std;

struct election
{
    char contestant_name[20];
    int no_of_votes;
     struct election *link;
}*head=NULL;

void insert(char* name,int votes)
{
    struct election *temp=(struct election *)malloc(sizeof(struct election));
    struct election *prev=(struct election *)malloc(sizeof(struct election));
    strcpy(temp->contestant_name,name);
    temp->no_of_votes=votes;
    
    if(head==NULL){
        temp->link=NULL;
        head=temp;
    }

    else
    {
        prev=head;
        while(prev->link!=NULL)
        {
            prev=prev->link;
        }
        temp->link=prev->link;
        prev->link=temp;
    }

    cout<<"element inserted"<<endl;

}

void check_display(int value)
{
     struct election *temp=(struct election *)malloc(sizeof(struct election));
    struct election *prev=(struct election *)malloc(sizeof(struct election));

    prev=head;
    int count=0;
 cout<<"the no.of contestants who scored above the given number are:  "<<endl;    
 while(prev!=NULL )
    {
        if(prev->no_of_votes>value)
        {
        cout<<"contestant name:  "<<prev->contestant_name<<"   "<<"no of votes :  "<<prev->no_of_votes<<endl;
        count++;
        }
         prev=prev->link;
    }
    /*if(prev->no_of_votes>value)
    {
        cout<<"contestant name:  "<<prev->contestant_name<<"   "<<"no of votes :  "<<prev->no_of_votes<<endl;
      count=count+1;
    }*/
    cout<<"the no.of contestants who scored above the given number are:  "<<count<<endl;
}

void display()
{
    struct election *temp=(struct election *)malloc(sizeof(struct election));
    struct election *prev=(struct election *)malloc(sizeof(struct election));

    prev=head;
    while(prev!=NULL)
    {
        cout<<"contestant name:  "<<prev->contestant_name<<"   "<<"no of votes :  "<<prev->no_of_votes<<endl;
        prev=prev->link;
    }

}

int main()
{
    char name[100];
    int votes;
    int data;
    cout<<"enter the number of votes above whose details you need:"<<endl;
 cin>>data;
  for(int i=0;i<4;i++)
  {
    cout<<"enter your name:"<<endl;
    cin>>name;
    cout<<"enter no.of votes:"<<endl;
    cin>>votes;
    insert(name,votes);
  }
  display();
  check_display(data);
  return 0;
}