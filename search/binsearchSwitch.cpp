#include<iostream>
using namespace std;
int binsearch(int arr[],int n , int t,int &locn)
{
    int begin=0;
    int end=n-1;
    int mid;
    while(begin<=end)
    {
         mid=(begin+end)/2;
        if(t>arr[mid])
        {
            begin=mid+1;
        }
        else if(t<arr[mid])
        {
            end=mid-1;
        }
        else{
            begin=end+1;
        }
    }

        locn=mid;
        if(t==arr[mid])
        {
            return 1;
        }
        else
        {
            return -1;
        }

    
}

int recbinsearch(int arr[],int i,int n,int &locn,int t)
{
    int l=n-1;
    int mid;
    if(i>l)
    {
        locn=-1;
        return -1;
    }
    else{
        mid=(i+l)/2;
        if(t<arr[mid])
        {
            return recbinsearch(arr,i,mid-1,locn,t);
        }
        else if(t>arr[mid])
            {
                return recbinsearch(arr,mid+1,n,locn,t);

            }
            else{
                locn=mid;
                return 1;
            }
        

    }
}

int main()
{
    int n,arr[100],t,loc,result,res;
    cout<<"enter n:"<<endl;
    cin>>n;
    
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    cout<<"enter the element to be found : "<<endl;
    cin>>t;

    int c;
    cout<<"enter the choice !! type 1 or 2!!"<<endl;
    cin>>c;
    switch(c)
    {
        case 1:

     res=binsearch(arr,n,t,loc);
    if(res==1)
    {
        cout<<"the element is found at the location:"<<loc+1<<endl;

    }
    else{
        cout<<"element not found in the given array!!"<<endl;
    }
    break;

    case 2:
     result=recbinsearch(arr,0,n,loc,t);
    if(result==1)
    {
        cout<<"element is found at the location:"<<loc+1<<endl;
    }
    else{
        cout<<"element is not found!!"<<endl;
    }
    break;

    default:
     cout<<"invalid type of choice"<<endl;
    }
    return 0;
}