#include<iostream>
using namespace std;

int push(int p[],int n,int q,int &k)
{
if(k==n-1)
{
cout<<"stack is full!"<<endl;
}
else
{
k++;
p[k]=q;
return k;
}
return k;
}
 
int pop(int p[],int &k,int q)
{
if(k==-1)
{
cout<<"stack is empty!"<<endl;
}
else
{
p[k]=q;
k--;
return k;
}
return k;

}

int emptystack(int p[],int &k)
{
if(k==-1)
{
cout<<"the stack is empty"<<endl;

}
else
{
cout<<"the stack is full"<<endl;
return false;
}
return k;

}

int fullstack(int p[],int &k,int n)
{
if(k==n-1)
{
cout<<"the stack is full"<<endl;

}
else
{
cout<<"the stack is empty"<<endl;
return false;
}
return k;

}

int stacktop(int p[],int &k)
{
if(k==-1)
{
cout<<"stack is empty"<<endl;
}
else
{
return p[k];
}
return k;

}

int display(int p[],int &k)
{
for(int j=k;j>=0;j--)
{
cout<<p[j]<<endl;
}
return k;
}


int main()
{
 int n, p[n],q,top;
 top=-1;
cout<<"enter n:"<<endl;
cin>>n;
cout<<endl;
int choice,j;
cout<<"how many times do you  wanna perform operations:"<<endl;
cin>>j;


for(int i=0;i<j;i++)
{
    cout<<"enter 1,2,3,4,5,6 for push,pop and to check fullstack,emptystack,stacktop,display"<<endl;
cin>>choice;
    switch(choice)
    {
        case 1:
        cout<<"enter data:"<<endl;
        cin>>q;
        push(p,n,q,top);
        display(p,top);
        cout<<endl;
        break;

        case 2:
        cout<<"enter data:"<<endl;
        cin>>q;
        pop(p,top,q);
        pop(p,top,q);
        display(p,top);
        cout<<endl;
        break;


        case 3:
        emptystack(p,top);
        break;

        case 4:
        fullstack(p,top,n);
        break;
        
        case 5:
        stacktop(p,top);
        break;
        
        case 6:
        display(p,top);
        break;

    }
}

return 0;
}

