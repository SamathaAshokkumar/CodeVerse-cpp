#include<iostream>
#include<string.h>
#include<cstring>
using namespace std;

struct student
{
    char stu_name[10];
    char gender[7];
    char stay[10];
    double cgpa;
    struct student *link;
}*head=NULL;

void insertb(char* name , char* gender,char* stay,double cgpa)
{
    struct student *temp=(struct student *)malloc(sizeof(struct student));
        struct student *prev=(struct student *)malloc(sizeof(struct student));
    strcpy(temp->stu_name,name);
    strcpy(temp->gender,gender);
    strcpy(temp->stay,stay);
    temp->cgpa=cgpa;
    if(head==NULL)
{
head=temp;
head->link=NULL;
}
else{
    prev=head;
    head=temp;
   temp->link=prev;
     


}
    cout<<"element inserted"<<endl;
}

void inserte(char* name , char* gender,char* stay,double cgpa)
{
    struct student *temp=(struct student *)malloc(sizeof(struct student));
        struct student* prev=(struct student *)malloc(sizeof(struct student));
    strcpy(temp->stu_name,name);
    strcpy(temp->gender,gender);
    strcpy(temp->stay,stay);
    temp->cgpa=cgpa;
    if(head==NULL)
{
head=temp;
head->link=NULL;
}
else
{
prev=head;
while(prev->link!=NULL)
{
prev=prev->link;
}
temp->link=NULL;
prev->link=temp;
}
cout<<"element inserted at the end"<<endl;
cout<<endl;
}
    


void display()
{
     struct student *temp=(struct student *)malloc(sizeof(struct student));
        struct student *prev=(struct student *)malloc(sizeof(struct student));
    prev=head;
    while(prev!=NULL)
    {
        cout<<"student name : "<<prev->stu_name<<endl<<"gender : "<<prev->gender<<endl<<"stay : "<<prev->stay<<endl<<"cgpa : "<<prev->cgpa<<endl;
       cout<<endl;
        prev=prev->link;
    }

}

int main()
{
  char gen[8];
  char name[15];
  char stay[10];
  double cgpa;
  int j,r;
  cout<<"how many students's details do you  wanna enter :"<<endl;
  cin>>j;
  for(int i=0;i<j;i++)
  {
    cout<<"enter student name:"<<endl;
    cin>>name;
    cout<<"enetr gender f for female m for male:"<<endl;
    cin>>gen;
    cout<<"where are you staying in home or hostel:"<<endl;
    cin>>stay;
    cout<<"enetr cgpa:"<<endl;
    cin>>cgpa;
    char str[8]="female";
    int r=strcmp(gen,str);
    if(r==0)
    {
         insertb(name,gen,stay,cgpa);

    }
    else{
               inserte(name,gen,stay,cgpa);

    }
  

  }
  display();

  return 0;
}