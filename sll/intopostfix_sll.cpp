#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct node 
{
    char data;
    struct node *link;
}*head=NULL;

int priority(char q)
{
    if(q=='+' || q=='-')
    {
        return 1;
    }
    else if(q=='*'||q=='/')
    {
        return 2;
    }
    else if(q=='^')
    {
       return 3;
    }
    else
    {
        return 0;
    }
}

void insert(char value)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    struct node *prev=(struct node*)malloc(sizeof(struct node));
  temp->data=value;
  if(head==NULL)
  {
    temp->link=NULL;
    head=temp;
  }
  else
  {
    prev=head;
    temp->link=prev;
    head=temp;
  }
}

char deletion(char &q)
{
      struct node *temp=(struct node*)malloc(sizeof(struct node));
    struct node *prev=(struct node*)malloc(sizeof(struct node));
if(head==NULL)
{
    //cout<<"the list is empty"<<endl;
}
else
{
    q=head->data;
    prev=head;
    temp=prev->link;
    head=temp;
    free(prev);   
}
return q;
}

void convert(string infix)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    struct node *prev=(struct node*)malloc(sizeof(struct node));
    string postfix;
    int i=0;
    char q;
  while(infix[i]!='\0')
  {
    if(infix[i]=='(')
    {
        //cout<<".."<<endl;
        insert(infix[i]);
        i++;
    }
    else if(infix[i]>='a' && infix[i]<='z'|| infix[i]>='A'&& infix[i]<='Z')          
    {
        cout<<",,"<<endl;
        postfix +=infix[i];
        i++;
    }
    else if(infix[i]==')')
    {
      prev=head;
      //cout<<prev->data<<endl;
      //cout<<prev->link->data<<endl;
      
      while(prev!=NULL)
      {
        if(prev->data!='(')
    {
        deletion(q);
        postfix += q;
        prev=head;
        //cout<<prev->data<<endl;
      }
      else
      {
        prev=NULL;
      }
      }
      deletion(q);
      i++;
    }
    else
    {
        prev=head;
        cout<<">>"<<endl;
        if(prev!=NULL)
        {
            while(prev!=NULL)
            {
                 if(priority(infix[i])<=priority(prev->data))
                 {
                    postfix += prev->data;
                    deletion(q);
                    //postfix += q;
                    prev=head;
                 }
                 else
                 {
                    prev=NULL;
                 }
            }
        }
            insert(infix[i]);
            i++;
        
    }
  }
  temp=head;
  while(temp!=NULL)
  {
    //cout<<"$$"<<endl;
    postfix += temp->data;
    deletion(temp->data);
    temp=head;
  }
  cout<<"the postfix is : "<<postfix<<endl;
}

int main()
{
    string infix="a+b*(c^d-e)^(f+g*h)-i";
     //string infix="k+L-M*N+(O^P)*W/U/V*T+Q";
    //string infix="(A+B)*(C+D)";
    convert(infix);
    return 0;
}

    
