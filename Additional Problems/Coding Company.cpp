
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
int addmod(int x,int y){
    return (x+y)%mod;
}
 
int multmod(int x,int y){
    return (x*y)%mod;
}
/*
code BY-
 █ ▄▀  █  █  █▀▀▀█  █  █  █▀▀█  █▀▀█  █▀▀█  █▀▀█ 　 
 █▀▄   █  █  ▀▀▀▄▄  █▀▀█  █▄▄█  █ ▄▄  █▄▄▀  █▄▄█ 　 
 █  █  ▀▄▄▀  █▄▄▄█  █  █  █  █  █▄▄█  █  █  █  █ 　 
 
▀▀█▀▀ █▀▀█ ▀█▀  █   █  █▀▀▀ █▀▀▄ ▀█▀ 
  █   █▄▄▀  █    █ █   █▀▀▀ █  █  █
  █   █  █ ▄█▄   ▀▄▀   █▄▄▄ █▄▄▀ ▄█▄ 
*/
 
int offset=5e4;
 
void solve(int xyz)
{
    int n,x;cin>>n>>x;vector<int>values(n);REP(i,0,n)cin>>values[i];sort(values.begin(),values.end());
    vector<vector<int>>dp1((n+1)/2+2,vector<int>(offset+x+1,0));
    vector<vector<int>>dp2((n+1)/2+2,vector<int>(offset+x+1,0));
    dp1[0][offset]=1;
    REP(i,0,n){
      REP(j,0,min(i,(n-i))+1){
        REP(k,0,offset+x+1){
          if(!dp1[j][k])continue;
          dp2[j][k]=addmod(dp1[j][k],dp2[j][k]);
          if(j>0 && k+values[i]<=offset+x){
            dp2[j-1][k+values[i]]=addmod(dp2[j-1][k+values[i]],multmod(j,dp1[j][k]));
          }
          if(j+1<=n-(i+1)){
            dp2[j+1][k-values[i]]=addmod(dp2[j+1][k-values[i]],dp1[j][k]);
          }
          if(j<=n-(i+1)){
            dp2[j][k]=addmod(dp2[j][k],multmod(j,dp1[j][k]));
          }
        }
      }
        REP(j,0,min(i+2,(n-i+2))){
          REP(k,0,offset+x+1){
            dp1[j][k]=dp2[j][k];dp2[j][k]=0;
          }
        }
    }
    int ans=0;
    REP(i,offset,offset+x+1){
      ans=addmod(ans,dp1[0][i]);
    }
    cout<<ans<<endl;
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
