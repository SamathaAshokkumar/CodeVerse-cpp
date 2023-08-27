#include<iostream>
using namespace std;
int recursiveSeqSearch(int arr[],int i,int n,int locn,int t)
{
    if(i>n)
    {
        locn=-1;
        cout<<"element not found"<<endl;
        return false;
    }
    else if(t==arr[i])
    {
        locn=i;
        cout<<"element found at "<<locn<<endl;
        return true;
    }
    else{
        return recursiveSeqSearch(arr,i+1,n,locn,t);
    }
}
int main()
{
int n,arr[100],t,i=0,locn;
cout<<"enter n:"<<endl;
cin>>n;
for(int j=0;j<n;j++)
{
    cin>>arr[i];
}
cout<<"enter the element to be found:"<<endl;
cin>>t;

recursiveSeqSearch(arr,i+1,n,locn,t);
return 0;
}