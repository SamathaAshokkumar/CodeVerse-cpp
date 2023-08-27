#include<iostream>
#include<string.h>
#include<cstring>
using namespace std;

struct Student
{
    char name[100];
    int age;
    struct Student * link;
} *head;

 struct Student *one= (struct Student *)malloc(sizeof(struct Student));
    struct Student *two = (struct Student *)malloc(sizeof(struct Student));
    struct Student *three = (struct Student *)malloc(sizeof(struct Student));

void insert_1(char* name,int age)
{
    


    strcpy(one->name,name);
    one->age=age;
    one->link=two;
    head=one;
    
}

void insert_2(char* name,int age)
{
    strcpy(two->name,name);
    two->age=13;
    two->link=three;
    

}

void insert_3(char* name,int age)
{
     strcpy(three->name,name);
    three->age=14;
    three->link=NULL;
}

void display()
{
     struct Student *temp;
  temp=head;
  cout<<temp->age<<endl;
  while(temp!=NULL)
  {
      cout<<"name:  "<<temp->name<<" "<<"age:  "<<temp->age<<endl;
      temp=temp->link;
  }
}

int main()
{

   int age_1,age_2,age_3;
  char name_1[100];
    char name_2[100];
  char name_3[100];

  cout<<"enter student name:"<<endl;
    cin>>name_1;
    cout<<"enter age of the student"<<endl;
    cin>>age_1;
    cout<<"enter student name:"<<endl;
    cin>>name_2;
    cout<<"enter age of the student"<<endl;
    cin>>age_2;
     cout<<"enter student name:"<<endl;
    cin>>name_3;
    cout<<"enter age of the student"<<endl;
    cin>>age_3;
   insert_1("samatha",17);
    insert_1(name_1,age_1);
    insert_2(name_2,age_2);
    insert_3(name_3,age_3);

    display();
}