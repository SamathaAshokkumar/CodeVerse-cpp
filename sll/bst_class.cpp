
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node * front;
    struct node * back;
}*root=NULL;
class Root
{
    public:
    struct node  *root;
    Root()
    {
        root=NULL;
    }

void insert(int value)
{
struct node * nnode=(struct node*)malloc(sizeof(struct node ));

if(root==NULL)
{
nnode->data=value;
       nnode->front=NULL;
       nnode->back=NULL;
root=nnode;
cout<<root->data;
}
else
{
if(root->data<value)
{
   cout<<"\nright";
root=root->front;
insert(value);

}
else
{   cout<<"\nleft";
   root=root->back;
insert(value);

}
}
}
void inorder()
{
  struct node *temp=(struct node *)malloc(sizeof(struct node));

if(root==NULL)
{
  cout<<"the list is empty!!"<<endl;
}
else
{
    root=root->back;
 inorder();
 cout<<root<<endl;
 root=root->front;
 inorder();
}
}
};
int main()
{
    Root r;
    r.insert(3);
    r.insert(2);
    r.insert(4);
    r.insert(5);
    r.insert(1);
    r.inorder();
   
    return 0;
}
