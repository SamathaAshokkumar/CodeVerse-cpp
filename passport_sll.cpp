#include<iostream>
#include<string.h>
#include<cstring>
using namespace std;

struct passport
{
    char applicant_name[25];
    int passport_num;
    struct passport *link;
}*head=NULL;

void insert(char* name,int id)
{
    struct passport *temp=(struct passport *)malloc(sizeof(struct passport));
    struct passport *prev=(struct passport *)malloc(sizeof(struct passport));
     strcpy(temp->applicant_name,name);
     temp->passport_num=id;
     if(head==NULL)
     {
    temp->link=NULL;
    head=temp;
     }
     else{
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

void deletion()
{
    struct passport *temp=(struct passport *)malloc(sizeof(struct passport));
    struct passport *prev=(struct passport *)malloc(sizeof(struct passport));
    prev=head;
    cout<<"the departure details of a applicant : "<<endl;
    cout<<"name : "<<prev->applicant_name<<"  "<<"passport number : "<<prev->passport_num<<endl;
    temp=prev->link;
    head=temp;
    free(prev);
}

void display()
{
     struct passport *temp=(struct passport *)malloc(sizeof(struct passport));
    struct passport *prev=(struct passport *)malloc(sizeof(struct passport));
    prev=head;
    while(prev!=NULL)
    {
        cout<<"applicant name : "<<prev->applicant_name<<"   "<<"passport number : "<<prev->passport_num<<endl;
        prev=prev->link;
    }

}

int main()
{
    int choice,j;
    char name[20];
    int id;
    cout<<"enter how many operations do you wanna perform : "<<endl;
    cin>>j;
    for(int i=0;i<=j;i++)
    {
        int choice;
        cout<<"enter your choice 1 for arrival, 2 for departure : "<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1:
            cout<<"enter the appliacnt name : "<<endl;
            cin>>name;
            cout<<"enter the applicant passport number : "<<endl;
            cin>>id;
            insert(name,id);
            break;

            case 2:
            deletion();
            break;
              
        }
    }
    return 0;
}