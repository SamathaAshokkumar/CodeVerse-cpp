#include<iostream>
using namespace std;
struct datanode
{
    int data;
    struct datanode*link;
};
struct datanode*head= NULL;
int main()
{
   
    int k=10;
  struct datanode*newnode=(struct datanode*) malloc(sizeof(struct datanode));
  newnode->data=k;
  newnode->link=head;
  head=newnode;

//cout<<newnode->data<<endl;
newnode->data=20;
cout<<newnode->data<<endl;
}
