#include<iostream>
using namespace std;

void seqsearch(int arr[],int n,int t)
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
        cout<<"the element is not found in the given array!"<<endl;
    }
}

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
    else{
        return recseqsearch(arr,i+1,n,locn,t);
    }
}

int main()
{
    int n,arr[100],t,loc,res;
cout<<"enter n:"<<endl;
cin>>n;
for(int i=0;i<n;i++)
{
    cin>>arr[i];
}
cout<<"enter the target element:"<<endl;
cin>>t;
int c;
cout<<"enter your choice!! type 1 or 2.."<<endl;
cin>>c;
switch(c)
{
    case 1:
    seqsearch(arr,n,t);
    break;

    case 2:
   res=recseqsearch(arr,0,n,loc,t);

  if(res==1)
  {
    cout<<"element found is found at the location:"<<loc+1<<endl;
  }
  else
 {
     cout<<"element not found in the given array!"<<endl;
  }
  break;

  default:
  cout<<"invalid choice !!"<<endl;
}

    return 0;

}