
#include<iostream>
#include<vector>
using namespace std;
#define INT_MAX 100000000
#define int long long
 
signed main() {
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    int i;
    for (i = 0; i < n; i++) {
        cin >> v[i];
    }
 
    vector<int> dp(x + 1, INT_MAX); 
    dp[0]=0;
    for (i = 1; i <= x; i++) { 
 
        for (int j = 0; j < n; j++) {
            if (i - v[j] >= 0 && dp[i - v[j]] != -1) {
                dp[i] = min(dp[i],dp[i - v[j]] + 1);
            }
            }
            if (dp[i]==INT_MAX)
            dp[i]=-1;
    }
 
    cout << dp[x] << endl;
 
    return 0;
}
