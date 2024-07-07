
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
 
 
 
 
const int n=2e5+5;
int power(int a,int b){
    if(b==0)return 1;
    if(a==0)return 0;
    if(a==1)return 1;
    int ans=1;
    a=a%mod;
    while(b>0){
        if(b&1){
            ans=ans*a%mod;
        }
        b>>=1;
        a=(a*a)%mod;
    }
    return ans;
}
int fact[n]; int inv[n];
void once(){
    fact[0]=1;
    REP(i,1,n){
        fact[i]=fact[i-1]*i%mod;
    }
    inv[0]=1;
    REP(i,1,n){
        inv[i]=power(fact[i],mod-2)%mod;
    }
}
int ncr(int n,int r){
    int ans=fact[n]%mod;
    ans*=inv[r]%mod;
    ans%=mod;
    ans*=inv[n-r]%mod;
    ans%=mod;
    return ans;
}
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
 
int dp[501][501];
string s;
int calc(int l,int r){
    if(dp[l][r]!=-1)return dp[l][r];
    if((r-l+1)&1){return 0;}
    if(l>r)return 1;
    int ways=0;
    REP(i,l+1,r+1){
        if(s[i]==s[l]){
            int twoparts=multmod(calc(l+1,i-1),calc(i+1,r));
            int combine=multmod(twoparts,ncr((r-l+1)/2,(i-l+1)/2));
            ways=addmod(ways,combine);
        }
    }
    return dp[l][r]=ways;
}
void solve(int xyz)
{
    cin>>s;
    REP(i,0,501){REP(j,0,501)dp[i][j]=-1;}
    cout<<calc(0,s.length()-1);
}
 
signed main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif
  once();
ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//   int t;cin>>t;
  REP(xyz,0,1){
    solve(xyz);
  }
}
