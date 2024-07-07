
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
        for (int k = 0; k < n; k++)
        {
            if (coins[k]==i)
                dp[i]+=1;
        }
        
            for (int j = 0; j < n; j++)
            {
                if (i - coins[j] >= 0)
                {
                     y = i - coins[j];
                    if (dp[y] != 0)
                    {
                        dp[i] += dp[y];
                    }
                }
            }
            dp[i]%=mod;
        }
      
    cout<<dp[x];
    return 0;
}
