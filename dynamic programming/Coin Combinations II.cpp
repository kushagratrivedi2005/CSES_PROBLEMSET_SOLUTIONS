
#include <iostream>
using namespace std;
#define int long long 
 
signed main()
{
    int mod=1e9+7;
    int n, x,y;
    cin >> n >> x;
    int coins[n];
    int dp[x+1];
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    for (int i = 0; i <= x; i++)
    {
        dp[i]=0;
    }
    
    for (int i = 0; i < n; i++)
    {
        dp[0]=1;
            for (int j = 1; j <= x; j++)
            {
                if (j - coins[i] >= 0)
                {
                     y = j - coins[i];
                    if (dp[y] != 0)
                    {
                        dp[j] += dp[y];
                    }
                }
                dp[j]%=mod;
            }
        }
      
    cout<<dp[x];
    return 0;
}
