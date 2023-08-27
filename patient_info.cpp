#include<iostream>
#include<string.h>
#include<cstring>
using namespace std;

struct patientinfo
{
    char patient_name[15];
    int age;
    char gender[7];
    char blood_group[3];

};

void insert()
{
    struct patientinfo s[5];
    int n;
    cout<<"how many patient info do you wanna enter : "<<endl;
    cin>>n;
     for(int i=0;i<n;i++)
     {
        cout<<"enter patient name:"<<endl;
        cin>>s[i].patient_name;
        cout<<"enter patient age:"<<endl;
        cin>>s[i].age;
        cout<<"enter patient gender:"<<endl;
        cin>>s[i].gender;
        cout<<"enter patient blood group:"<<endl;
        cin>>s[i].blood_group;
     }
     cout<<"information stored"<<endl;

     int begin=0;
     int end=n-1;
     int mid;
     int speage;
     cout<<"enetr specific age:"<<endl;
     cin>>speage;
     while(begin<=end)
     {
      mid=(begin+end)/2;
        if(speage>s[mid].age)
        {
           begin=mid+1;
        }
        else if(speage<s[mid].age)
        {
            end=mid-1;
        }
        else
        {
            begin=end+1;
        }
     }
       int len=strlen(s[mid].gender);
     int locn=mid;
     //cout<<mid<<endl;
     if(speage==s[mid].age && 4==len)
     {
        cout<<s[mid].patient_name<<endl;
     }
     else
     {
        cout<<"no such patient found"<<endl;
     }
    
}


int main()
{
    insert();
    return 0;
}
