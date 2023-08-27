#include<iostream>
using namespace std;

struct node 
{
    int data;
    struct node *prev;
    struct node *succ;
}*root=NULL;

struct node*  insert_inorder(struct node *&root , int value)
{
struct node *temp=(struct node *)malloc(sizeof(struct node));

temp->data=value;
temp->prev=NULL;
temp->succ=NULL;

if(root==NULL)
{
root=temp;
return temp;
}

if(root->data>value)
{  
root->prev=insert_inorder(root->prev,value);
}

else if(root->data<value)

{ 
root->succ=insert_inorder(root->succ,value);
}
else
{
  cout<<"element is already present!!"<<endl;
}
return root;

}
struct node* minvaluenode(struct node *&root)
{
  struct node *temp=(struct node *)malloc(sizeof(struct node));
    struct node *prev=(struct node *)malloc(sizeof(struct node));

  temp=root;
  while(temp!=NULL && temp->prev!=NULL)
  {
    temp=temp->prev;
  }
  cout<<temp->data<<endl;
  /*prev=temp->prev;
  cout<<prev->data<<endl;
  cout<<prev->succ->data;*/
 return temp;
}

struct node* maxvaluenode(struct node *&root)
{
  struct node *temp=(struct node *)malloc(sizeof(struct node));
  temp=root;
  while(temp!=NULL && temp->succ!=NULL)
  {
    temp=temp->succ;
  }
 return temp;
}

struct node* search_bst(struct node *&root,int target)
{
  if(root==NULL)
  {
    cout<<"the element is not present in the list!!"<<endl;
    return root;
  }
  if(target<root->data)
  {
    return search_bst(root->prev,target);
  }
  else if(target>root->data)
  {
    return search_bst(root->succ,target);
  }
  else
  {
    if(root->data==target)
    {
    cout<<"the element is present in the list!!"<<endl;
    return root;
    }
    else
    {
      cout<<"element is not present in the list"<<endl;
    }
  }
  return root;
}

struct node* delete_node(struct node *&root,int value)
{
  if(root==NULL)
  {
    return root;
  }
  if(value<root->data)
  {
    root->prev=delete_node(root->prev,value);
  }
  else if(value>root->data)
  {
    root->succ=delete_node(root->succ,value);
  }
  else
  {
    if(root->prev==NULL)
    {
      struct node *temp=(struct node *)malloc(sizeof(struct node));
     temp=root->succ;
      free(root);
      return temp;
    }
    else if(root->succ==NULL)
    {
      struct node *temp=(struct node *)malloc(sizeof(struct node));
      temp=root->prev;
      free(root);
      return temp;
    }
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp=minvaluenode(root->succ);
    root->data=temp->data;
    root->succ=delete_node(root->succ,temp->data);
  }
  return root;
}

struct node* inorder(struct node *&root)
{
if(root==NULL)
{
return root;
}
else
{
 inorder(root->prev);
 cout<<root->data<<endl;
 inorder(root->succ);
}
return root;
}

struct node* preorder(struct node *&root)
{
if(root==NULL)
{
return root;
}
else
{
 cout<<root->data<<endl;
 preorder(root->prev);
 preorder(root->succ);
}
return root;
}

struct node* postorder(struct node *&root)
{
if(root==NULL)
{
return root;
}
else
{
 postorder(root->prev);
 postorder(root->succ);
 cout<<root->data<<endl;
}
return root;
}

int main()
{
  
  /*int j;
    int choice;
    cout<<"how many times do you  wanna perform operations:"<<endl;
    cin>>j;

    for(int i=0;i<=j;i++)
{
    cout<<"enter 1,2,3,4,5,6,7,8,9,10,11 for insert,order_insert,deletion,counting value,display_head_to _rear,display_rear_to_head,search,search_from_rear_to_head,empty_cdll,destroy" <<endl;
    cin>>choice;
   switch(choice)
   {
    
    case 1:
    int invalue;
    cout<<"element to be inserted!!"<<endl;
    cin>>invalue;
   insert_inorder(root,invalue);  
   break;

   case 2:
   int delvalue;
   cout<<"enter the value to be inserted : "<<endl;
   cin>>delvalue;
   delete_node(root,delvalue);
   break;

   case 3:
   
   minvaluenode(root);
   break;

   case 4:
   maxvaluenode(root);
    break;

    case 5:
    int value;
    cout<<"enter the value to be searched : "<<endl;
    cin>>value;
    search_bst(root,value);
    break;
    
    case 6:
    inorder(root);
    break;

    case 7:
     preorder(root);
    break;

    case 8:
    postorder(root);
    break;


   }

}*/
insert_inorder(root,100);
insert_inorder(root,50);
insert_inorder(root,70);
insert_inorder(root,150);
insert_inorder(root,170);
insert_inorder(root,40);
minvaluenode(root);
return 0;
}

