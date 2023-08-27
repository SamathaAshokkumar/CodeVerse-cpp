#include<iostream>
using namespace std;

int gcdrec(int a,int b)
{
    if(a==0)
    {
        return b;
    }
    else if(b==0)
    {
        return a;
    }
    else
    {
        return gcdrec(b%a,a);
    }
}

int main()
{
    int a,b;
    cout<<"enter 1st number:"<<endl;
    cin>>a;
    cout<<"enter 2st number:"<<endl;
    cin>>b;
    cout<<gcdrec(a,b)<<endl;

    return 0;

}