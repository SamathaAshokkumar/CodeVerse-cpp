#include<iostream>
using namespace std;

struct node
{
    int data;
    int div;
    struct node *link;
}*head[50];

struct node* create_head(int num,int div)
{
     struct node *temp=(struct node*)malloc(sizeof(struct node));
        struct node *prev=(struct node*)malloc(sizeof(struct node));
                struct node *h=(struct node*)malloc(sizeof(struct node));
                 int i=0;
                if(div==0)
                {
                    cout<<"the divider cannot be 0 !"<<endl;
                }
                else
                {
    int rem=num%div;
    //int rem=num%5;
     temp->data=rem;
    temp->link=NULL;
    if(head[i]==NULL)
    {
        head[i]=temp;
    }
    else{
    while(head[i]!=NULL && head[i]->data!=rem )
    {
      i++;
    }
    //cout<<i<<endl;
    /*if(head[i]->data!=rem)
    {
    head[i+1]=temp;    
    }
    else
    {
        return head[i];
    }*/
    if(head[i]==NULL)
    {
    head[i]=temp;
    }
    else
    {
        return head[i];
    }
}

}
return head[i];
}

void insert(int num,int div)
{
     struct node *temp=(struct node*)malloc(sizeof(struct node));
        struct node *prev=(struct node*)malloc(sizeof(struct node));
                prev= create_head(num,div);
                temp->data=num;
                temp->div=div;
                temp->link=NULL;

                while(prev->link!=NULL)
                {
                    
                    prev=prev->link;
                }
           prev->link=temp; 
    ///cout<<"inserted!!"<<endl;
}

void display(int r)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
        struct node *prev=(struct node*)malloc(sizeof(struct node));
        int i=0;
        //prev=head[i];
        while(head[i]!=NULL && head[i]->data!=r)
        {
            i++;
        }
        prev=head[i];
cout<<"the numbers and divisors for a remainder "<<r<<" are follows : "<<endl;
if(prev->link==NULL)
{
    cout<<"the list is empty!!"<<endl;
}
        else if(prev->data==r)
        {
            prev=prev->link;
            while(prev!=NULL)
            {
                //cout<<",,"<<endl;
                // cout<<"the numbers and divisors for a remainder "<<r<<" are follows : "<<endl;
                 cout<<"the number is : "<<prev->data<<endl;
                 cout<<"the divider is : "<<prev->div<<endl;
                 prev=prev->link;
            }
        }
    
}

void search_hash(int num,int div)

{
  struct node *temp=(struct node*)malloc(sizeof(struct node));
        struct node *prev=(struct node*)malloc(sizeof(struct node));
        prev=create_head(num,div);
        prev=prev->link;
        while(prev!=NULL && prev->data!=num)
        {
          prev=prev->link;  
        }
        if(prev==NULL)
        {
            cout<<"the element and the divider is not present in the list!!"<<endl;
        }
        else
        {
        if(prev->data==num)
        {
            cout<<"the number and the divider is present!"<<endl;
        }
        else
        {
            cout<<"the element and the divider is not present in the list!!"<<endl;
        }
        }

}

int main()
{
    /*
    insert(10,5);//0
    insert(11,5);//1
    insert(12,5);//2
    insert(4,2);//0
    insert(4,3);//1
    insert(30,4);//2
    insert(8,2);//0
    insert(100,3);//1
    insert(75,7);//5
    insert(8,0);

    display(0);
  display(1);
  display(2);
  display(5);

  search_hash(8,2);
  search_hash(45,10);
  search_hash(75,7);
  search_hash(9,10);
  */
 int j;
 int choice;
 cout<<"enter how many operations do you wanna perform:"<<endl;
 cin>>j;
 for(int i=0;i<=j;i++)
 {
    cout<<"choose 1,2 or 3 for insert,display and search"<<endl;
    cin>>choice;
 switch(choice)
 {
    case 1:
    int num,div;
    cout<<"enter the number and divider:"<<endl;
    cin>>num;
    cin>>div;
    insert(num,div);
    break;

    case 2:
    int rem;
    cout<<"enter the remainder:"<<endl;
    cin>>rem;
    display(rem);
    break;

    case 3:
    int numb,divi;
    cout<<"enter the number and divider:"<<endl;
    cin>>numb;
    cin>>divi;
    search_hash(numb,divi);
    break;

    default:
    cout<<"choose 1,2 or 3 for operations!"<<endl;
 }
 }
    return 0;
}