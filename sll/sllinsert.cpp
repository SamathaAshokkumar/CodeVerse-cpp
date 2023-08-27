#include<iostream>
using namespace std;
struct node
{
int info;
struct node *link;
}*head= NULL;

node*create_node(int value)
{
struct node*temp;
temp=new(struct node);

if(temp==NULL)
{
cout<<"memory not allocated!"<<endl;
return 0;
}

else
{
temp->info=value;
temp->link=NULL;
return temp;
}
}


void insert_begin()
{
int value;
cout<<"enter the value to be inserted:"<<endl;
cin>>value;
struct node *temp,*prev;
temp=create_node(value);
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
cout<<"element has been inserted at beginning "<<endl;
cout<<endl;
}

void insert_end()
{
int value;
cout<<"enter the value to be inserted:"<<endl;
cin>>value;
struct node *temp,*prev;
temp=create_node(value);
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
prev->link=temp;
}
cout<<"element inserted at the end"<<endl;
cout<<endl;
}

void display()
{
struct node *temp;
temp=head;
while(temp!=NULL)
{
cout<<temp->info<<endl;
temp=temp->link;
}
}

void insert_mid()
{
int value,pos,i;
cout<<"enetr the value to be inserted:"<<endl;
cin>>value;
cout<<"enetr the position to be inserted:"<<endl;
cin>>pos;

struct node*temp,*prev;
temp=create_node(value);
if(head==NULL)
{
temp->link=head;
head=temp;
}
else
{
i=1;
prev=head;
while(i<(pos-1)&&prev!=NULL)
{
prev=prev->link;
i++;
}
if(prev!=NULL)
{
temp->link=prev->link;
prev->link=temp;
}
else
{
cout<<"invalid position!"<<endl;
}
}
}


void del()
    {
        int value;
        struct node *temp,*prev;
        prev=head;
        cout<<"enter the value to be deleted"<<endl;
        cin>>value;
        if(head==NULL)
        {
            cout<<"emepty list"<<endl;
        }
        else{
            prev=NULL;
            temp=head->link;
            while(temp!=NULL && temp->info != value)
            {
                prev=temp;
                temp=temp->link;
            }
            if(temp==NULL)
            {
                cout<<"invalid element"<<endl;
            }
            else{
                if(prev==NULL)
                {
                    head->link=temp->link;

                }
                else{
                    prev->link=temp->link;
                }
                free(temp);
            }

        }  
    }


int main()
{
    int j;
    int choice;
    cout<<"how many times do you  wanna perform operations:"<<endl;
    cin>>j;

    for(int i=0;i<j;i++)
{
    cout<<"enter 1,2,3,4,5, for insert_begin,inset_mid,insert_end,deletion,display" <<endl;
    cin>>choice;
   switch(choice)
   {
    
    case 1:
   insert_begin();
   break;
   case 2:
   insert_mid();
   break;
   case 3:
   insert_end();
   break;
   case 4:
   del();
    break;
    case 5:
    display();
    break;
   }
}

return 0;
}

