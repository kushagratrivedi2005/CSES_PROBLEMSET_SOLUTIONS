
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
// code for constructing dominator tree from online resource
///////////////////////////////////////////////////// 
struct edge{
    int destination, weight;
};
int k = 0;
array<int, 100004>  P, rev, L, sdom, idom, pre, DSU;
// P and rev are inverse of each other
array<vector<int>, 100004> R, buk;
int find(int u, int x = 0){
    if(u == DSU[u]) return x? -1 : u;
    int v = find(DSU[u], x + 1);
    if(v < 0) return u;
    if(sdom[L[DSU[u]]] < sdom[L[u]]) L[u] = L[DSU[u]];
    DSU[u] = v;
    return x? v : L[u];
}
void onion(int u, int v){
    DSU[v] = u;
}
void DFS(int u,vector<vector<int>>&dijkstragraph){
    P[u] = ++k, rev[k] = u, L[k] = k, sdom[k] = k, DSU[k] = k;
    for(int v : dijkstragraph[u]){
        if(!P[v]){
            DFS(v,dijkstragraph);
            pre[P[v]] = P[u];
        }
        R[P[v]].pb(P[u]);
    }
}
void DOM(int n){
    int w;
    for(int u = n; u; u--){
        for(int v : R[u]){
            sdom[u] = min(sdom[u], sdom[find(v)]);
        }
        if(u > 1) buk[sdom[u]].pb(u);
        for(int v : buk[u]){
            w = find(v);
            if(sdom[v] == sdom[w]) idom[v] = sdom[v];
            else idom[v] = w;
        }
        onion(pre[u], u);
    }
    for(int u = 2; u <= n; u++){
        if(sdom[u] != idom[u]) idom[u] = idom[idom[u]];
    }
}
//////////////////////////////////////////////////
vector<int> ans;
void path(int node){
    ans.pb(rev[node]);
    if(node==1)return;
    path(idom[node]);
}
void solve(int xyz)
{
int n,m,x,y,z;cin>>n>>m;
    vector<vector<int>>graph(100004);
    REP(i,0,m){cin>>x>>y;graph[x].pb(y);}
    DFS(1,graph);
    DOM(n);
    path(P[n]);
    sort(ans.begin(), ans.end());
    cout<<ans.size()<<endl;
    REP(i,0,ans.size()) cout << ans[i] << " ";
    cout << endl;
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
