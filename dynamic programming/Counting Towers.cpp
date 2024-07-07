
#include<bits/stdc++.h>
#define mod 1000000007 
#define int long long
#define REP(i,m,n) for(int i=m;i<n;i++)
#define pb push_back
#define ff first
#define ss second
#define vi vector<int>
#define ii pair<int,int>
#define mp make_pair
#define vii vector<ii>
using namespace std;
 
 
/*
code BY-
 █ ▄▀  █  █  █▀▀▀█  █  █  █▀▀█  █▀▀█  █▀▀█  █▀▀█ 　 
 █▀▄   █  █  ▀▀▀▄▄  █▀▀█  █▄▄█  █ ▄▄  █▄▄▀  █▄▄█ 　 
 █  █  ▀▄▄▀  █▄▄▄█  █  █  █  █  █▄▄█  █  █  █  █ 　 
 
▀▀█▀▀ █▀▀█ ▀█▀  █   █  █▀▀▀ █▀▀▄ ▀█▀ 
  █   █▄▄▀  █    █ █   █▀▀▀ █  █  █
  █   █  █ ▄█▄   ▀▄▀   █▄▄▄ █▄▄▀ ▄█▄ 
*/
 
int dp[1000000][8];
void solve(){
    REP(i,0,8) dp[0][i]=1;
    REP(i,1,1000000){
        REP(j,0,8){
            if(j==0 or j==2 or j==3 or j==5 or j==4)
            dp[i][j]=(dp[i-1][0]%mod+dp[i-1][1]%mod+dp[i-1][5]%mod+dp[i-1][3]%mod+dp[i-1][4]%mod)%mod;
            else
            dp[i][j]=(dp[i-1][2]%mod+dp[i-1][6]%mod+dp[i-1][7]%mod)%mod;
        }
    }
}
 
 
 
signed main(){
    int t; cin>>t;
    solve();
    while(t--){
    int n;cin>>n;
    cout<<(dp[n-1][2]%mod+dp[n-1][6]%mod)%mod<<endl; 
    }
}
