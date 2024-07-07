
#include<iostream>
using namespace std;
# define int long long
int dp[1000000];
 
signed main(){
int n;
cin>>n;
const int mod=1e9+7;
for (int i = 0; i <=n; i++)
{
    if(i==0)
        dp[i]=1;
    else{
        for (int j = 0; j <=6; j++)
        {
            if(j<=i)
            dp[i]+=dp[i-j];
        }
    }
    dp[i]%=mod;
}
cout<<dp[n];
}
