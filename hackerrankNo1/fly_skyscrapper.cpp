#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'solve' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

/*int solve(vector<int> arr) {
    int n=*max_element(arr.begin(),arr.end());
    int b[n],k=0,result=0;
    for(int i=0;i<=n;i++)
    {
        b[i]=0;
    }
    for(auto it=arr.begin();it!=arr.end();it++)
    {  k=*it;
        b[k]=b[k]+1;
    }
    for(int i=0;i<=n;i++)
    {
        cout<<b[i]<<endl;
    }
    for(int i=0;i<=n;i++)
    {
        if(b[i]>1)
        {
           result=result + (pow(2,b[i])-2);
        }
        
    }
    cout<<result<<endl;
return result;
}*/


int solve(vector<int> arr) {
    int count1=0,count2=0,result=0;
    for(auto it=arr.begin();it!=arr.end();it++)
    {
        count1++;
       int curr=*it;
       for(auto i=arr.begin();i!=arr.end();i++)
       {count2++;
         if(curr==*i)
         {
            int n=*max_element(arr.begin()+count1,arr.begin()+count2);
            if(n<=curr)
            {
                result=result+2;
            }

         }
       }
       count2=0;
    }
    return result;
}



int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string arr_count_temp;
    getline(cin, arr_count_temp);

    int arr_count = stoi(ltrim(rtrim(arr_count_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(arr_count);

    for (int i = 0; i < arr_count; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = solve(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
