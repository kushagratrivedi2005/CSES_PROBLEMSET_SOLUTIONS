
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
 
int dp[100001][101];
 
signed main(){
    int n;cin>>n;
    int x;cin>>x;
    vector<int>num(n+1);
    REP(i,1,n+1) cin>>num[i];
    if(num[1]!=0)
    dp[1][num[1]]=1;
    if(num[1]==0)
    REP(i,1,x+1) dp[1][i]=1;
    REP(i,2,n+1){
        if(num[i]!=0){
            REP(j,max(1LL,num[i]-1),min(num[i]+2,x+1))
            dp[i][num[i]]+=dp[i-1][j]%mod;
        }
        if(num[i]==0){
            REP(k,1,x+1){
                REP(j,max(1LL,k-1),min(x+1,k+2)){
                    dp[i][k]+=dp[i-1][j]%mod;
                }
            }
        }
    }
    int sum=0;
    REP(i,1,x+1) sum+=dp[n][i]%mod;
    cout<<sum%mod;
}
