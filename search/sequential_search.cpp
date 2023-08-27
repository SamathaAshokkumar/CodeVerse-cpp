#include<iostream>
using namespace std;
int seqsearch(int arr[],int n,int t)
{
    int l=0;
    bool found;
    while(l<n && t!=arr[l] )
    {
        l++;
    }

    if(t==arr[l])
    {
        found=true;
        cout<<"the element is found at the location: "<<l+1<<endl;
    }
    else
    {
        found=false;
        cout<<"the element is not found"<<endl;
    }

    //return found;
}

int main()
{
    int n, arr[100], t;
    cout<<"enter n:"<<endl;
    cin>>n;

    
    cout<<"Enter the element to be found:"<<endl;
    cin>>t;
    for(int i=0;i<n;i++)
    {
    cin>>arr[i];
    }
    

    seqsearch(arr,n,t);


    return 0;

}