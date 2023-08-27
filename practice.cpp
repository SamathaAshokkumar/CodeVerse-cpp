#include<iostream>
#include<string.h>
#include<cstring>
using namespace std;


struct cricket
{
    char team_name[15];
    char player_name[20];
    double bat_avg;
    struct cricket *link;
}*head=NULL;

void insert(char* p_name,char* t_name,double b_avg)
{
    struct cricket *temp=(struct cricket *)malloc(sizeof(struct cricket));
        struct cricket *prev=(struct cricket *)malloc(sizeof(struct cricket));
    strcpy(temp->player_name,p_name);
    strcpy(temp->team_name,t_name);
   temp->bat_avg=b_avg;

    if(head==NULL)
    {
       head=temp;
       head->link=NULL;
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
void display()
{
   struct cricket *temp=(struct cricket *)malloc(sizeof(struct cricket));
        struct cricket *prev=(struct cricket *)malloc(sizeof(struct cricket));
        prev=head;
        while(prev!=NULL)
        {
            cout<<prev->player_name<<"   "<<prev->team_name<<"   "<<prev->bat_avg<<endl;
            prev=prev->link;
        }
}

void sort()
{
    struct cricket *temp=(struct cricket *)malloc(sizeof(struct cricket));
        struct cricket *prev=(struct cricket *)malloc(sizeof(struct cricket));
int swapped;
temp=NULL;
do
{

      swapped=0;
        prev=head;
        while(prev->link!=temp)
        {
            if(prev->bat_avg>prev->link->bat_avg)
            {
                int t;
                t=prev->bat_avg;
                prev->bat_avg=prev->link->bat_avg;
                prev->link->bat_avg=t;
                strcpy(prev->team_name,prev->link->team_name);
                swapped=1;
            }
             prev=prev->link;

        }
        temp=prev;

}while(swapped);
}


int main()
{
    char pname[50];
    char tname[10];
    double avg;
for (int i=0;i<4;i++)
{
    cin>>pname;
    cin>>tname;
    cin>>avg;
   insert(pname,tname,avg);
}
    /*insert("samatha","aces",57);
    insert("ashokkumar","india",97.6);
    insert("appu","parrot",97.6);
    insert("sai","cocktails",98);
    insert("shanthi","lovable",97);*/
    
    display();

  sort();
  display();

  return 0;

}