
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
 
 
 
int stirling[5001][5001];
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
void stirling1(){
     stirling[1][1] = 1;
    for(int n = 2; n < 5001; n++)
        for(int k = 1; k <= n; k++)
            stirling[n][k] = (stirling[n-1][k-1] + (n-1) * stirling[n-1][k]) % mod;
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
 
int pown[5001];
void solve(int xyz)
{
    int n;cin>>n;vector<int>ans(n+1);
     pown[0]=1;REP(i,1,5001){pown[i]=multmod(n,pown[i-1]);}
    int z=power(n,mod-2);
    REP(i,1,n+1){
        REP(j,1,n+1){
            int roots=multmod(multmod(ncr(n,j),j),z);
            int trees=pown[n-j];
            int combinations=stirling[j][i];
        ans[i]=addmod(ans[i],multmod(multmod(roots,trees),combinations));
        }
        cout<<ans[i]<<endl;
    }
    
 
}
 
signed main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif
  once();
  stirling1();
ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//   int t;cin>>t;
  REP(xyz,0,1){
    solve(xyz);
  }
}
