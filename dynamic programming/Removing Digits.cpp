
#include<iostream>
#include<string>
#include<cmath>
#include<vector>
using namespace std;
#define int long long
 
signed main(){
    int n;
    cin>>n;
    vector<int>dp(n+1,1e6);
    dp[0]=0;
    
    for (int i = 0; i <=n; i++)
    {
        string str;
        str=to_string(i);
        for( char c:str){
            dp[i]=min(dp[i],dp[i-c+48]+1);
        }
    }
    cout<<dp[n];
    return 0;
}
