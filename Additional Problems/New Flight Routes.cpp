
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
 
int finalnode = 100006;
int scccounter = 0;
vector<int>visited(100010,0);vector<int>cycle(100010,0);
vector<int> indegree(100010), outdegree(100010), sccid(100010), finalsccnode(100010);
vector<vector<int>> graph(100010), reverse1(100010);
vector<vector<pair<int,int>>> markededge(100010);
vector<int> kosaraju, outcycle, incycle, onlyout, onlyin;
vector<pair<int, int>> ans;
 
void dfs1(int node) {
    if (visited[node]) return;
    visited[node] = 1;
    for (int i : graph[node]) dfs1(i);
    kosaraju.pb(node);
}
 
void DFS(int node) {
    if (sccid[node]) return;
    sccid[node] = scccounter;
    for (int i : reverse1[node]) DFS(i);
}
 
bool cyclefind(int node) {
    if (node == finalnode) return true;
    for (auto &i : markededge[node]) {
        int y = i.first;
        int &foundcycle = i.second;
        if (foundcycle) continue;
        foundcycle = 1;
        if (cyclefind(y)) {
            if (!indegree[node]) outcycle.pb(node), cycle[node] = 1;
            if (!outdegree[node]) incycle.pb(node), cycle[node] = 1;
            return true;
        }
    }
    return false;
}
 
 
void solve(int xyz)
{
 int n, m, x, y;
    cin >> n >> m;
    while (m--) {
        cin >> x >> y;
        graph[x].pb(y);
        reverse1[y].pb(x);
    }
 
    REP(i,1,n+1) dfs1(i);
    reverse(kosaraju.begin(), kosaraju.end());
 
    for (int i : kosaraju) {
        if (!sccid[i]) scccounter++;
        DFS(i);
    }
 
    if (scccounter == 1) {
        cout << 0<<endl;
        return ;
    }
 
    REP(i,1,n+1) {
        finalsccnode[sccid[i]] = i;
        for (int x : graph[i]) {
            if (sccid[x] == sccid[i]) continue;
            markededge[sccid[i]].pb({sccid[x], 0});
        }
    }
 
    REP(i,1,scccounter+1) {
        markededge[i].erase(unique(markededge[i].begin(), markededge[i].end()), markededge[i].end());
        for (auto x : markededge[i]) {
            int y = x.first;
            indegree[y]++;
            outdegree[i]++;
        }
    }
 
    REP(i,1,scccounter+1) {
        if (!outdegree[i]) markededge[i].pb({finalnode, 0});
    }
 
    REP(i,1,scccounter+1) {
        if (!indegree[i]) cyclefind(i), x = i;
        if (!outdegree[i]) y = i;
    }
 
    REP(i,1,scccounter+1) {
        if (cycle[i]) continue;
        if (!indegree[i]) onlyout.pb(i);
        if (!outdegree[i]) onlyin.pb(i);
    }
 
    REP(i,0,outcycle.size()-1) {
        ans.pb({incycle[i], outcycle[i + 1]});
    }
    if (outcycle.size()) ans.pb({incycle.back(), outcycle[0]});
 
    for (int i = 0; i < min(onlyout.size(), onlyin.size()); i++) {
        ans.pb({onlyin[i], onlyout[i]});
    }
    if (onlyout.size() > onlyin.size()) {
        REP(i,onlyin.size(),onlyout.size()) {
            ans.pb({y, onlyout[i]});
        }
    } else {
        REP(i,onlyout.size(),onlyin.size()) {
            ans.pb({onlyin[i], x});
        }
    }
    cout << ans.size() <<endl;
    REP(i,0,ans.size())
        cout << finalsccnode[ans[i].first] << " " << finalsccnode[ans[i].second] <<endl;
    return ;
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
