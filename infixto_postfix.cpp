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
return k;
}

int pop(char p[],int &k,char &q)
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

return k;
}

int priority (char alpha){
    if(alpha == '+' || alpha =='-')
        return 1;
 
    if(alpha == '*' || alpha =='/')
        return 2;
 
    if(alpha == '^')
        return 3;

   else
   {
    return 0;
   }
}


char stacktop(char p[],int &k,char &q)
{
if(k==-1)
{
cout<<"stack is empty"<<endl;
}
else
{
q=p[k];
}
return q;
}



bool emptystack(char p[],int &k)
{
    
if(k==-1)
{
//cout<<"the stack is empty"<<endl;
return true;
}
else
{
return false;
}
}

string convert(string infix,int n,int &k)
{
     n=100;
    int i = 0;
    string postfix = "";
    char q;
    char p[n];

    while(infix[i]!='\0')
    {
        
        if(infix[i]>='a' && infix[i]<='z'|| infix[i]>='A'&& infix[i]<='Z')          
        {
            postfix += infix[i];
            i++;
        }
        else if(infix[i]=='(')
        {
           
            push(p,n,infix[i],k);
            i++;
        }
        else if(infix[i]==')')
        {
            stacktop(p,k,q);
            while(stacktop(p,k,q)!='('){
                postfix += stacktop(p,k,q);
                pop(p,k,q);
            }
            pop(p,k,q);
            i++;
        }
        else            
        {
            while (!emptystack(p,k) && priority(infix[i]) <= priority(stacktop(p,k,q))){
                postfix +=stacktop(p,k,q);
                pop(p,k,q);
            }
            push(p,n,infix[i],k);
            i++;
        }
    }
    while(!emptystack(p,k)){
        postfix += stacktop(p,k,q);
        pop(p,k,q);
    }


    cout << "Postfix is : " << postfix; 
    return postfix;
}

int main()
{
    int n=100;
    int k=-1;
    //string infix = "((a+(b*c))-d)"; 
    string infix;
    cout<<"enter the infix expression"<<endl;
    cin>>infix;
    string postfix;
    postfix = convert(infix,n,k);
   // convert(infix,n,k);
    
    return 0;
}