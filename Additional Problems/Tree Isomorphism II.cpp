
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
 
int dfs1(int src, int par,vector<int>&size1,vector<vector<int>>&adj) {
    for (auto child : adj[src]) {
        if (child == par) continue;
        size1[src] += dfs1(child, src,size1,adj);
    }
    return size1[src];
}
 
void dfs2(int src, int par, int n, vector<int>& centroids,vector<int>&size1,vector<vector<int>>&adj) {
    bool is_centroid = true;
    for (auto child : adj[src]) {
        if (child == par) continue;
        if (size1[child] > n / 2) {
            is_centroid = false;
        }
            dfs2(child, src, n, centroids,size1,adj);
    }
    if (is_centroid && (n - size1[src]) <= n / 2) {
        centroids.push_back(src);
    }
}
map<vector<int>,int>treetype;
int type=0;
int dfs3(int x,int par,vector<vector<int>>&graph){
    vector<int>vec;
    for(auto i:graph[x]){
        if(i!=par)
        vec.pb(dfs3(i,x,graph));
    }
    sort(vec.begin(),vec.end());
    if(!treetype.count(vec))treetype[vec]=type++;
    return treetype[vec];
}
 
void solve(int xyz)
{
    int n;cin>>n;
    vector<vector<int>>graph1(n+1);vector<vector<int>>graph2(n+1);
    REP(i,0,n-1){
        int x,y;cin>>x>>y;graph1[x].pb(y);graph1[y].pb(x);
    }
    REP(i,0,n-1){
        int x,y;cin>>x>>y;graph2[x].pb(y);graph2[y].pb(x);
    }
    vector<int>size1(n+1,1);vector<int>size2(n+1,1);vector<int>centroids1;vector<int>centroids2;
    dfs1(1,-1,size1,graph1);dfs2(1,-1,n,centroids1,size1,graph1);
    dfs1(1,-1,size2,graph2);dfs2(1,-1,n,centroids2,size2,graph2);
    if(centroids1.size()!=centroids2.size()){cout<<"NO"<<endl;return;}
    REP(i,0,centroids1.size()){
    int ans1=dfs3(centroids1[0],-1,graph1);int ans2=dfs3(centroids2[i],-1,graph2);
    if(ans1==ans2){cout<<"YES"<<endl;return;}}
    {cout<<"NO"<<endl;return;}
}
 
signed main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif
  
ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int t;cin>>t;
  REP(xyz,0,t){
    solve(xyz);
  }
}
