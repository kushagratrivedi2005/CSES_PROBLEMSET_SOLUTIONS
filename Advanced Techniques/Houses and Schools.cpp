
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
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
using namespace __gnu_pbds;
template<class T> using oset= tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key
 
 
 
 
// const int n=2e5+5;
// int power(int a,int b){
//     if(b==0)return 1;
//     if(a==0)return 0;
//     if(a==1)return 1;
//     int ans=1;
//     a=a%mod;
//     while(b>0){
//         if(b&1){
//             ans=ans*a%mod;
//         }
//         b>>=1;
//         a=(a*a)%mod;
//     }
//     return ans;
// }
// int fact[n]; int inv[n];
// void once(){
//     fact[0]=1;
//     REP(i,1,n){
//         fact[i]=fact[i-1]*i%mod;
//     }
//     inv[0]=1;
//     REP(i,1,n){
//         inv[i]=power(fact[i],mod-2)%mod;
//     }
// }
// int ncr(int n,int r){
//     int ans=fact[n]%mod;
//     ans*=inv[r]%mod;
//     ans%=mod;
//     ans*=inv[n-r]%mod;
//     ans%=mod;
//     return ans;
// }
// int addmod(int x,int y){
//     return (x+y)%mod;
// }
 
// int multmod(int x,int y){
//     return (x*y)%mod;
// }
/*
code BY-
 █ ▄▀  █  █  █▀▀▀█  █  █  █▀▀█  █▀▀█  █▀▀█  █▀▀█ 　 
 █▀▄   █  █  ▀▀▀▄▄  █▀▀█  █▄▄█  █ ▄▄  █▄▄▀  █▄▄█ 　 
 █  █  ▀▄▄▀  █▄▄▄█  █  █  █  █  █▄▄█  █  █  █  █ 　 
 
▀▀█▀▀ █▀▀█ ▀█▀  █   █  █▀▀▀ █▀▀▄ ▀█▀ 
  █   █▄▄▀  █    █ █   █▀▀▀ █  █  █
  █   █  █ ▄█▄   ▀▄▀   █▄▄▄ █▄▄▀ ▄█▄ 
*/
int values[3001]; int prefixsums[3][3001];
int dp[3001][3001];
const int inf=1e16;
 
int houseataandb(int a,int b,int n){
    int m=(a+b)/2;
    int ans=(prefixsums[1][m]-prefixsums[1][a-1])-a*(prefixsums[0][m]-prefixsums[0][a-1]);
    ans+=(prefixsums[2][b]-prefixsums[2][m])-(n-b+1)*(prefixsums[0][b]-prefixsums[0][m]);
    return ans;
}
 
void recurse(int j,int a,int b,int x,int y,int n){
    if(a>b)return;int m=(a+b)/2;pair<int,int>curr={inf,-1};
    REP(i,x,min(m,y)+1){curr=min(curr,{dp[i][j-1]+houseataandb(i,m,n),i});}
    dp[m][j]=curr.first;
    recurse(j,a,m-1,x,curr.second,n);
    recurse(j,m+1,b,curr.second,b,n);
}
 
void solve(int xyz)
{
 int n,k;cin>>n>>k;REP(i,0,n){
    cin>>values[i];
    prefixsums[0][i+1]=prefixsums[0][i]+values[i];
    prefixsums[1][i+1]=prefixsums[1][i]+(i+1)*values[i];
    prefixsums[2][i+1]=prefixsums[2][i]+(n-i)*values[i];
 }
 REP(i,1,n+1){dp[i][1]=prefixsums[2][i]-(n-i+1)*prefixsums[0][i];}
 REP(i,0,k-1){recurse(i+2,1,n,1,n,n);}
 int ans=inf;
 REP(i,1,n+1){ans=min(ans,dp[i][k]+(prefixsums[1][n]-prefixsums[1][i-1])-i*(prefixsums[0][n]-prefixsums[0][i-1]));}
 cout<<ans;
}
 
signed main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif
  
ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//   int t;cin>>t;
  REP(xyz,0,1){
    solve(xyz);
  }
}
