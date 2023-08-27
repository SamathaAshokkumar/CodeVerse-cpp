#include<iostream>
using namespace std;

int facrec(int n)
{
    if(n==0 || n==1)
    {
        return 1;
    }
    else
    {
        return (n*facrec(n-1));
    }
}


int main()
{
    int n,i=0;
    cout<<"enter n:"<<endl;
    cin>>n;
    cout<<facrec(n)<<" ";
       
    return 0;
}