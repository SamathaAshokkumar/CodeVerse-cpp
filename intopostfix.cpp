#include<iostream>
#include<string.h>
#include<cstring>
using namespace std;
int push(char p[],int n,char q,int &k)
{
if(k==n-1)
{
cout<<"stack is full!"<<endl;
}
else
{
k++;
p[k]=q;

}
return k,q;
}

int pop(char p[],int &k,char q)
{
if(k==-1)
{
cout<<"stack is empty"<<endl;
}
else
{
q=p[k];
k--;

}
return k,q;
}

int priority(char a)
{
int check_val;
switch (a)
{
case '+':
check_val=1;
break;

case '-':
check_val=1;
break;

case '*':
check_val=2;
break;

case '/':
check_val=2;
break;

case '^':
check_val=3;
break;

default: check_val=-1;

}
return check_val;
}

int stacktop(char p[],int &k,char q)
{
/*if(k==-1)
{
cout<<"stack is empty"<<endl;
}
else
{*/

p[k]=q;
//}
return k;
}

int emptystack(char p[],int &k)
{
if(k==-1)
{
//cout<<"the stack is empty"<<endl;
return true;
}
else
{
cout<<"the stack is full"<<endl;
return false;
}
}


char* peep(char p[],int n,int &k,char postfix[])
{
  char q;
//char postfix[50];
for(int i=0;i<=8;i++)
{
  cout<<p[i]<<endl;
if(p[i]=='(')
{
push(p,n,p[i],k);
cout<<"( pushed"<<endl;
}
else if(p[i]==')')
{
pop(p,k,q);
cout<<") popped"<<endl;
char value[]={q};
for(int j=0;j<10;j++)
{
while(value[j]!='(')
{
strcat(postfix,value);
//postfix[]=value;
pop(p,k,q);
value[j]=q;

}
}
}
else if(p[i]=='+'||'-'||'*'||'/'||'^')
{
  cout<<p[i]<<endl;
//priority(p[i]);
stacktop(p,k,q);
cout<<q<<endl;
while(emptystack(p,k) && priority(p[i])<priority(q))
{
pop(p,k,q);
char value[]={q};
strcat(postfix,value);
//postfix[]=q;
stacktop(p,k,q);
}
}
else
{
    char value[]={p[i]};
    strcat(postfix,value);
//postfix[]=p[i];
}

}


while(emptystack(p,k))
{
pop(p,k,q);
char value[]={q};
strcat(postfix,value);
//postfix[]=q;
}

return postfix;
}

int display(char p[],int &k)
{
for(int j=k;j>=0;j--)
{
cout<<p[j]<<endl;
}
return k;
}

int main()
{
int n=50,k=-1;
char p[50]={'(','+','b','+','-','c','*','d'};
char postfix[50];

peep(p,n,k,postfix);

return 0;
}



