#include<iostream>
#include<string.h>
using namespace std;

class solution
char findlength(char prefixin[])
{
    int len1 =0;
    int len2=0;
    if( prefixin[0] == '+' || prefixin[0] =='-' ||prefixin[0] == '*' ||prefixin[0] == '/')
    {
       len1= return findlen(prefixin + 1);
       len2 = return findlen(prefixin + 1 + len1);
    }
    else{
        len1=0;
        len2=0;
    }

    return (len1 + len2 + 1);
}

void  pretopostfix(char prefixin[],char pretopostfix[])
{
    int size=prefixin.size();
    if(size==1)
    {
       postfix[]=prefixin[];
    }
    int operator = prefixin[0];
    int lengthofexpr=findlen(prefixin[]);
    char temp[] = substring(prefixin[2,lengthofexpr]);

    pretopostfix(temp[], postfix1[]);

    temp[]= prefixin[lengthofexpr+1,(size-1)];

    pretopostfix(temp[],postfix2[]);

    postfix= postfix1[] + postfix2[] + operator ;

    return postfix[];

}

int main()
{
    char prefixin[50]={a*bc\+de-f};
    char postfix[50];
    findlength(prefixin);
    cout<<pretopostfix(prefixin,postfix)<<endl;

    return 0;
}
    
