#include<iostream>
#include<string.h>
using namespace std;

struct cricket
{
    char team_name[15];
    char player_name[20];
    double bat_avg;
};

void sort()
{
    struct cricket s[5],t;
    int i,j,n=5;
    float p;
    cout<<"enter details of 5 players:"<<endl;
    for(int i=0;i<n;i++)
    {
       cout<<"enter player name:"<<endl;
       cin>>s[i].player_name;
       cout<<"enter team name:"<<endl;
       cin>>s[i].team_name;
       cout<<"enter batting average:"<<endl;
       cin>>s[i].bat_avg;

    }
    cout<<"before sorting"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"player name : "<<s[i].player_name<<endl;
        cout<<"team name : "<<s[i].team_name<<endl;
        cout<<"batting average : "<<s[i].bat_avg<<endl;
    }
   cout<<endl;
   cout<<"......*******........"<<endl;

    for(i=1;i<=n-1;i++)
    {
        for(j=0;j<=n-i;j++)
        {
            if(s[j-1].bat_avg>s[j].bat_avg)
            {
                
                t=s[j-1];
                s[j-1]=s[j];
                s[j]=t;
            }
        }
    }

    

    cout<<"after sorting :"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"player name : "<<s[i].player_name<<endl;
        cout<<"team name : "<<s[i].team_name<<endl;
        cout<<"batting average : "<<s[i].bat_avg<<endl;
    }
   
}

int main()
{
    
    sort();
    return 0;
}