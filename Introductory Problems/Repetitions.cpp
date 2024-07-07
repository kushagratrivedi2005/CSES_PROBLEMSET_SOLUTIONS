
#include<iostream>
using namespace std;
 
int main(){
string s;
cin>>s;
int count=0,count1=0;
for (int i = 0; i < s.length(); i++)
{
    if (s[i]==s[i+1])
       { count++;
        if (count>count1)
        count1=count;}
    else    
        count=0;
}
cout<<count1+1;
 
return 0;
}
