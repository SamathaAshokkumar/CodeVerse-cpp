#include<iostream>
using namespace std;

int fibonaccirec(int n)
{
    if(n==0 || n==1)
    {
        return n;
    }
    else
    {
        return fibonaccirec(n-1)+fibonaccirec(n-2);
    }
}

int main()
{
    int n,i=0;
    cout<<"enter n:"<<endl;
    cin>>n;
    int arr[n];
    while(i<n)
    {
//cout<<fibonaccirec(i)<<" 1";
    arr[i]=fibonaccirec(i);
    i++;
    }
    for(int y=0;y<n;y++)
    {
        cout<<arr[y]<<endl;
    }

    return 0;
}