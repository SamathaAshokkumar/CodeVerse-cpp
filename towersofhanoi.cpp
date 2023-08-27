#include<iostream>
#include<string.h>
using namespace std;
void towersofhanoi(int no_of_disks,char source,char destination,char auxilary )
{
    if(no_of_disks==0)
    {
        return;
    }
    if(no_of_disks==1)
    {
      cout<<"move disk "<<no_of_disks<<" from rod "<<source <<" to "<< destination<<endl;
    }
    else
    {
        towersofhanoi(no_of_disks-1,source,auxilary,destination);
        cout<<"move disk "<<no_of_disks<<" from rod "<<source <<" to "<< destination<<endl;
        towersofhanoi(no_of_disks-1,auxilary,destination,source);
    }
 
}

int main()
{
    int no_of_disks;
    cout<<"enter the no of disks:"<<endl;
    cin>>no_of_disks;
    
    towersofhanoi(no_of_disks,'A','C','B');
    return 0;
}