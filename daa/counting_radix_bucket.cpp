#include<iostream>
#include<fstream>
#include<cstdlib>
#include<math.h>
using namespace std;
int count=0;
float b[100];
int n;
struct node
{
    float data;
    struct node *link;
    struct node *l;
}*head[50];

void create_head()
{
        struct node *prev=(struct node*)malloc(sizeof(struct node));
                struct node *h=(struct node*)malloc(sizeof(struct node));
                 int i=0;
while(i<=10)
{
    count++;
    struct node *temp=(struct node*)malloc(sizeof(struct node));
   temp->data=i;
   //cout<<temp->data<<endl;
   temp->link=NULL;
   temp->l=NULL;
   //prev=temp;
   head[i]=temp;
   
    i++;
}

}

void insert(float n,int d,int size)
{
     struct node *temp=(struct node*)malloc(sizeof(struct node));
        struct node *prev=(struct node*)malloc(sizeof(struct node));
                struct node *pre=(struct node*)malloc(sizeof(struct node));
                                struct node *p=(struct node*)malloc(sizeof(struct node));

               int num;
                n=n/pow(10,d);
                num=n*size;
                prev=head[num];
                //cout<<num<<endl;
                temp->data=n;
                 //cout<<prev->data<<endl;
               if(prev->link==NULL)
               {
                prev->link=temp;
                temp->link=NULL;
                temp->l=prev;
               }
               else if(prev->link->data>n)
               {
                  p=prev->link;
                  prev->link=temp;
                  temp->l=prev;
                  temp->link=p;
                  p->l=temp;
               }
              else if(prev->link->link==NULL)
               {
 
                if(prev->link->data<n)
               {
                 p=prev->link;
                         p->link=temp;
                    temp->link=NULL;
                    temp->l=p;
                   
  }
        }
               else
               {
           
                p=prev->link;
                /*if(p->data>n)
                {
                    prev->link=temp;
                    p->l=temp;
                    temp->l=prev;
                    temp->link=p;
                }*/
               
               
               
                while(p->link!=NULL && p->data<n)
                {
                    count++;
                    p=p->link;
                   
                }
               if(p->link==NULL)
                {
                  //pre=prev->link;
                  if(p->data<n)
                  {
                   // cout<<",,"<<endl;
                    p->link=temp;
                    temp->link=NULL;
                    temp->l=p;
                  }
                  else
                {
                   // cout<<",.,.,.,."<<endl;
                    p=p->l;
                   pre=p->link;
                   p->link=temp;
                   temp->l=p;
                   temp->link=pre;
                   pre->l=temp;
                }
                }
                /*if(p==NULL)
                {
                 
                    p->link=temp;
                    temp->link=NULL;
                    temp->l=p;

                }*/
                /*else if(p->link==NULL)
                {
                    if(p->data<n)
                    {
                         p->link=temp;
                    temp->link=NULL;
                    temp->l=p;
                    }
                }*/
                else
                {
                p=p->l;
                  pre=p->link;
                   p->link=temp;
                   temp->l=p;
                   temp->link=pre;
                   pre->l=temp;
                }
               
               }
               
    //cout<<"inserted!!"<<endl;
}

void display(int a[],int d)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
        struct node *prev=(struct node*)malloc(sizeof(struct node));
        int i=0,j=1;
         int ans,p;
        while(head[i]!=NULL)
        {
        prev=head[i];
if(prev->link==NULL)
{

}
        else if(prev->data==i)
        {
            prev=prev->link;
            while(prev!=NULL)
            {
                count++;
                 //cout<<prev->data<<endl;
                 p=pow(10,d);
                 ans=(p*(prev->data));
                 a[j]=ans;
                 b[j]=prev->data;
                //cout<<ans<<endl;
                 prev=prev->link;
                 j++;
            }
        }
          i++;
        }
   
}

void countingSort(int a[],int k,int n)
{
int b[n],c[k];
for(int i=0;i<=k;i++)
{
count++;
c[i]=0;
}
for(int i=1;i<=n;i++)
{
count++;
c[a[i]]=c[a[i]]+1;
}
for(int i=1;i<=k;i++)
{
count++;
c[i]=c[i-1]+c[i];
}
for(int i=n;i>=1;i--)
{
count++;
b[c[a[i]]]=a[i];
c[a[i]]=c[a[i]]-1;
}

for(int i=1;i<=n;i++)
{
count++;
a[i]=b[i];
}
}

int getDigit(int x,int i)
{
int d;
x=x/pow(10,(i-1));
d=x%10;

return d;
}

void countingSort(int a[],int k,int n,int d)
{
int b[n],c[k],s;
for(int i=0;i<=k;i++)
{
count++;
c[i]=0;
}
for(int i=1;i<=n;i++)
{
count++;
s=getDigit(a[i],d);
c[s]=c[s]+1;
}
for(int i=1;i<=k;i++)
{
count++;
c[i]=c[i-1]+c[i];
}
for(int i=n;i>=1;i--)
{
count++;
s=getDigit(a[i],d);
b[c[s]]=a[i];
c[s]=c[s]-1;
}

    for(int i=1;i<=n;i++)
{
count++;
a[i]=b[i];
}


}

void radixSort(int a[],int n,int d)
{
for(int i=1;i<=d;i++)
{
count++;
countingSort(a,9,n,i);
}

}

int num_digit(int g)
{
int d=0,rem;
while(g!=0)
{
rem=g%10;
d++;
g=g/10;
}
return d;
}

int main()
{
ofstream fout;
ifstream fin;
int *a;
int d,num;
int g,s;
cout<<"enter the size of an array:"<<endl;
cin>>n;
a=new int[n];
fout.open("b_in.txt");
for(int i=1;i<=n;i++)
{
s=rand()%(n+i);
if(g<s)
{
g=s;
}
fout<<s<<"\t";
}
fout.close();
fin.open("b_in.txt");
for(int i=1;i<=n;i++)
{
fin>>a[i];
}
fin.close();
cout<<"the g is:"<<g<<endl;
countingSort(a,g,n);
cout<<endl;
fout.open("counting_sort_output.txt");
for(int i=1;i<=n;i++)
{
fout<<a[i]<<"\t";
}
fout.close();
cout<<"the total number of operations for counting sort is :"<<count<<endl;
count=0;
fin.open("b_in.txt");
for(int i=1;i<=n;i++)
{
fin>>a[i];
}
fin.close();
d=num_digit(g);
cout<<"the num of digit is :"<<d<<endl;
radixSort(a,n,d);
fout.open("radix_sort_output.txt");
for(int i=1;i<=n;i++)
{
fout<<a[i]<<"\t";
}
fout.close();
cout<<"the total number of operations for radix sort is :"<<count<<endl;
count=0;
fin.open("b_in.txt");
for(int i=1;i<=n;i++)
{
fin>>a[i];
}
fin.close();
create_head();
for(int i=1;i<=n;i++)
 {
    //cout<<"main num is"<<a[i]<<endl;
    insert(a[i],d,n);
 }
 display(a,d);
  fout.open("bucket_sort_output.txt");
for(int i=1;i<=n;i++)
{
fout<<a[i]<<"\t";
}
fout.close();
cout<<"the total number of operations for bucket sort is :"<<count<<endl;
count=0;

return 0;
}