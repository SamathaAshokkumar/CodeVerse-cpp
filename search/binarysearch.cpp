#include<iostream>
using namespace std;
int binsearch(int arr[],int n,int t,int locn)
{
    int b=0;
    int e=n-1;
    int mid;
    bool found;

    while(b<=n)
    {
        mid=(b+e)/2;

       if(t>arr[mid])
       {
        b=mid+1;

       }
       else if(t<arr[mid])
       {
         e=mid-1;

       }

       else 
       {
        b=e+1;
       }

    }
    locn=mid;

    if(t==arr[mid])
    {
        found=true;

    }
    else{
        found=false;
    }
    return found;
}
int main()
{
    int n,arr[100],t,locn;
    cout<<"enter n:"<<endl;
    cin>>n;
    
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    cout<<"enter the element to be found:"<<endl;
    cin>>t;
    int res=binsearch(arr,n,t,locn);
    if(res==true)
    {
        cout<<"the element is found at the location"<<locn+1<<endl;
    }

    else 
    {
        cout<<"element is not present"<<endl;
    }
    return 0;
    
}