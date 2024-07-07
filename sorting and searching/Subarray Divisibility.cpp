
#include<iostream>
#include<vector>
#include<map>
#define int long long
using namespace std;
 
signed main(){
    int n;
    cin>>n;
    vector<int>values(n);
    for (int i = 0; i < n; i++)
    {
        cin>>values[i];
    }
    int count=0;
    vector<int>dp(n+1);
    dp[0]=0;
    for (int i = 1; i <= n; i++)
    {
        dp[i]=(((dp[i-1]+values[i-1])%n)+n)%n;
    }
    // for (int j = 0; j < n+1; j++)
    // {
    //     cout<<dp[j]<<endl;
    // }
    int i=0;
    int sum=0;
    int j=0;
    map<int,int>seen;
    seen[0]=1;
    for (int i = 1; i < n+1; i++)
    {
      count+=seen[dp[i]];
      seen[dp[i]]++;  
    }
    cout<<count;
}
