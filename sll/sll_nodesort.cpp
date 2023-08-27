#include<iostream>
using namespace std;
struct cricket
{
    char team_name[15];
    char player_name[20];
    double bat_avg;
    struct cricket *link;
}*head=NULL;


struct cricket* swap(struct cricket* ptr1,struct cricket* ptr2)
{
    struct cricket* tmp=ptr2->link;
    ptr2->link=ptr1;
    ptr1->link=tmp;
    return ptr2;
}

void insert(char* p_name,char* t_name,double b_avg)
{
    struct cricket *temp=(struct cricket *)malloc(sizeof(struct cricket));
        struct cricket *prev=(struct cricket *)malloc(sizeof(struct cricket));

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

void sort(struct cricket** hea)
{
    struct cricket** h;
  int i,j,swapped;
   int count=0;
              struct cricket *temp=(struct cricket *)malloc(sizeof(struct cricket));
              temp=head;
              while(temp->link!=NULL)
              {
                temp=temp->link;
                count++;
              }
              count=count+1;
              for(int i=0;i<=count;i++)
              {
                h=hea;
                swapped=0;

                for(j=0;j<count-i-1;j++)
                {
                struct cricket *prev=(struct cricket *)malloc(sizeof(struct cricket));
                struct cricket *curr=(struct cricket *)malloc(sizeof(struct cricket));
            prev=head;
            curr=prev->link;
            if(prev->bat_avg>curr->bat_avg)
            {
                *h=swap(prev,curr);
                swapped=1;
            }
            h=&(*h)->link;
                }
                if(swapped==0)
                break;
              }
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
              struct cricket* start=(struct cricket *)malloc(sizeof(struct cricket));
  start =NULL;
  sort(&start);
  display();

  return 0;

}