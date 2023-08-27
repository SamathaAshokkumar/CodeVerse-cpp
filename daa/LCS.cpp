#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<cstring>
using namespace std;

struct lcs
{
    char b[100][100];
    int c[100][100];
};

lcs lengthLCS(char x[],char y[],int m,int n)
{
     lcs s;
    
    for(int i=0;i<=n;i++)
    {
       s.c[0][i]=0;

    }
    for(int i=0;i<=m;i++)
    {
        s.c[i][0]=0;
    }
    /*for(int j=0;j<=n;j++)
    {
        s.c[0][j]=0;
    }
    for(int j=0;j<=n;j++)
    {
        s.c[j][0]=0;
    }*/
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(x[i]==y[j])
            {
               s.b[i][j]='/';
               s.c[i][j]=(s.c[(i-1)][(j-1)])+1;
            }
            else if(s.c[i][j-1]>s.c[i-1][j])
            {
                s.b[i][j]='-';
                s.c[i][j]=s.c[i][j-1];
            }
            else
            {
                s.b[i][j]='|';
                s.c[i][j]=s.c[i-1][j];
            }
        }
    }
    return s;
}

void printLcs(char b[100][100],char x[],int i,int j)
{
    if(i==0 || j==0)
    {
        return ;
    }
    if(b[i][j]=='|')
    {
        printLcs(b,x,i-1,j);
    }
    else if(b[i][j]=='-')
    {
        printLcs(b,x,i,j-1);
    }
    else
    {
        //cout<<x[i]<<endl;
        printLcs(b,x,i-1,j-1);
        cout<<x[i]<<endl;
    }

}

int main()
{
     lcs be;
    int n=7,m=5;
    //int x[100]={1,0,0,1,0,1,0,1};
    //int y[100]={0,1,0,1,1,0,1,1,0};
    //char x[100]={'A','B','C','B','D','A','B'};
    //char y[100]={'B','D','C','A','B','A'};
    char x[100],y[100];
    for(int i=1;i<=m;i++)
    {
        cin>>x[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>y[i];
    }
    cout<<"......."<<endl;
    be=lengthLCS(x,y,m,n);
    printLcs(be.b,x,m,n);
    cout<<"maximum length is "<<be.c[m][n]<<endl;
    cout<<max(1,2)<<endl;
    return 0;

}

/*
int lsc_dc(char x[],char y[],int m,int n)
{
    if(m==0||n==0)
    {
        return 0;
    }
    if(x[m]==y[n])
    {
        return 1+lcs_dc(x,y,m-1,n-1);
    })
    else
    {
        return max(lcs_dc(x,y,m-1,n),lcs_dc(x,y,m,n-1));
    }
}
*/