#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct node
{
int data;
struct node *link;

}*head=NULL;


void insert(int num)
{
struct node *temp=(struct node *)malloc(sizeof(struct node));
struct node *prev=(struct node *)malloc(sizeof(struct node));
temp->data=num;

if(head==NULL)
{
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
}

int palindrome(int value)
{
    int original=value;
    int rev=0;
    int val;
   while(value!=0)
{
 val=value % 10;
 rev=(rev*10)+val;
value=value/10;
}

if(original==rev)
{
return 1;
}
else
{
return 0;
}

}


void del_palindrome()
{
struct node *temp=(struct node *)malloc(sizeof(struct node));
struct node *prev=(struct node *)malloc(sizeof(struct node));

prev=head;
while(prev->link!=NULL)
{
    if(palindrome(prev->data)==1)
    {
        cout<<prev->data<<endl;
        temp=prev->link;
        if(prev==head)
        {
            head=prev->link;
        }
        else if(prev->link==NULL)
        {
           prev=head;
           while(prev!=NULL)
           {
            prev=prev->link;
           }
           prev->link=NULL;
        }
        free(prev);
        prev=temp;
    }
else
{
prev=prev->link;
}
}
cout<<"element deleted"<<endl;
}



void display()
{
struct node *prev=(struct node *)malloc(sizeof(struct node));
prev=head;
while(prev!=NULL)
{
 cout<<prev->data<<endl;
prev=prev->link;

}
}


int main()
{
insert(1002);
insert(2003);
insert(4004);
insert(8008);
insert(9087);
cout<<"elements inserted"<<endl;
cout<<"the elements are"<<endl;
display();
cout<<"after checking palindrome:"<<endl;
cout<<"the element deleted are:"<<endl;
del_palindrome();
display();
return 0;
}
