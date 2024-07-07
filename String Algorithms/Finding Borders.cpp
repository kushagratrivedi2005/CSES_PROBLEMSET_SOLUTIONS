
#include<bits/stdc++.h>
#define mod 1000000007 
#define int long long
#define REP(i,m,n) for(int i=m;i<n;i++)
#define pb push_back
#define ff first
#define ss second
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>
using namespace std;
signed main(){
    string s;cin>>s;
    int len=0;int i=1;
    int s_len=s.length();
    int piarray[s_len+1];
    piarray[0]=0;
    // piarray[s_len]=INT_MAX;
    while(i<s_len)
    {
        if(s[i]==s[len]){
            len++;
            piarray[i]=len;
            i++;
        }
        else{
            if(len==0){
                piarray[i]=len;
                i++;
            }
            else{
                len=piarray[len-1];
            }
        }
    }
   vector<int>v;
   int z=piarray[s_len-1];
   while(z!=0){
    v.push_back(z);
    z=piarray[z-1];
   }
    sort(v.begin(),v.end());
    auto it =v.begin();
    for(it=v.begin(); it!=v.end(); it++)
    cout<<*(it)<<" ";
    
    
    
    
    
    
}
