#include<iostream>
using namespace std;
int recseqsearch(int arr[],int i,int n,int &locn,int t)
{
    
     locn =0;
    if(i>n-1)
    {
        locn=-1;
        return -1;

    }
    if(t==arr[i])
    {
        locn =i;
        //cout<<locn<<endl;
        return 1;
       
    }
    
        return recseqsearch(arr,i+1,n,locn,t);
  
}
int main() {

int n,arr[100],t,loc,res;
cout<<"enter n:"<<endl;
cin>>n;
for(int i=0;i<n;i++)
{
    cin>>arr[i];
}
cout<<"enter the target element:"<<endl;
cin>>t;
res=recseqsearch(arr,0,n,loc,t);

if(res==1)
{
    cout<<"element found :"<<loc+1<<endl;
}
else
{
    cout<<"element not found"<<endl;
}
    return 0;
}