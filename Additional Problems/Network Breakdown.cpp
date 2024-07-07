
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
int size[100001];
int parent[100001];
int components;
void make(int i){
    size[i]=1;
    parent[i]=i;
}
int find(int x){
    if(x==parent[x])return x;
    return find(parent[x]);
}
void Union(int x,int y){
    x=find(x);y=find(y);
    if(x==y)return;
    if(size[x]<size[y])swap(x,y);
    parent[y]=x;
    size[x]+=size[y];
    components--;
}
void solve(int xyz)
{
   int n,m,k;cin>>n>>m>>k;components=n;set<ii>graph;REP(i,0,m){
    int a,b;cin>>a>>b;graph.insert({min(a,b),max(a,b)});
   }
   vii toremove(k);
   REP(i,0,k){
    int a,b;cin>>a>>b;ii pa={min(a,b),max(a,b)};graph.erase(pa);
    toremove.pb(pa);
   }
   reverse(toremove.begin(),toremove.end());
   REP(i,1,n+1){make(i);}
   for(auto i=graph.begin();i!=graph.end();i++){
    ii x=*i;Union(x.first,x.second);
   }
   vector<int>ans;
   REP(i,0,k){
    ii y=toremove[i];ans.pb(components);Union(y.first,y.second);
   }
   REP(i,0,ans.size()){cout<<ans[ans.size()-i-1]<<" ";}
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
