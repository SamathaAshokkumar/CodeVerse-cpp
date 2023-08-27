#include<iostream>
using namespace std;

int n=4;

struct matrix
{
    int m[100][100];
    int s[100][100];
};

matrix MCO(int p[],int n)
{
    matrix res;
    int min;
    for(int i=1;i<=n;i++)
    {
        res.m[i][i]=0;
    }
    for(int l=2;l<=n;l++)
    {
        for(int i=1;i<=n-l+1;i++)
        {   int j=i+l-1;
            res.m[i][j]=99999;
            for(int k=i;k<=j-1;k++)
            {
                 min=res.m[i][k]+res.m[k+1][j]+(p[i-1]*p[k]*p[j]);
                if(min<res.m[i][j])
                {
                   res.m[i][j]=min;
                   res.s[i][j]=k;
                }
            }
        }
    }
   //res.m[1][n];
   // cout<<"the total number of multiplications :"<<res.m[1][n]<<endl;
    
    return res;
   
}

void printMCO(int s[100][100],int i,int j)
{
    if(i==j)
    {
        cout<<"A"<<i;

    }
    else
    {
        cout<<"(";
        printMCO(s,i,s[i][j]);
        printMCO(s,(s[i][j]+1),j);
        cout<<")";
    }
}

int main()
{
    int p[100];
    matrix result;
    cout<<"enter array elements:"<<endl;
    for(int i=0;i<=n;i++)
    {
        cin>>p[i];
    }
    result=MCO(p,n);
    printMCO(result.s,1,n);
    cout<<"\ntotal number of multiplications required is : "<<result.m[1][n]<<endl;
    return 0;
}