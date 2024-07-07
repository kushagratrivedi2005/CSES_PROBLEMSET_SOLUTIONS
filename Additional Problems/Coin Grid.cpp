
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
const int inf = 1e18;
int counter = 0;
vector<int> visited(204, 0);
vector<int> level(204);
vector<int> parent(204);
vector<array<int, 3>> edges(80040);
vector<vector<int>> graph(204);
 
void addedge(int start, int end) {
    edges[counter] = {start, end, 1};
    graph[start].pb(counter++);
    edges[counter] = {end, start, 0};
    graph[end].pb(counter++);
}
 
int bfs(int source, int sink) {
    queue<int> Q;
    Q.push(source);
    level[source] = 1;
 
    while (!Q.empty()) {
        int curr = Q.front();
        Q.pop();
 
        for (int i : graph[curr]) {
            int start = edges[i][0];
            int end = edges[i][1];
            int flow = edges[i][2];
 
            if (!flow || level[end] != 0) continue;
 
            level[end] = level[curr] + 1;
            Q.push(end);
        }
    }
 
    return level[sink];
}
 
int dfs(int source, int sink, int flow) {
    if (source == sink || flow == 0) return flow;
 
    int finalflow = 0, tempflow;
 
    for (int &i = parent[source]; i < graph[source].size(); i++) {
        int edge_index = graph[source][i];
        int forstart = edges[edge_index][0];
        int forend = edges[edge_index][1];
        int forflow = edges[edge_index][2];
        int backflow = edges[edge_index ^ 1][2];
 
        if (level[forend] != level[source] + 1) continue;
 
        tempflow = dfs(forend, sink, min(flow, forflow));
        edges[edge_index][2] -= tempflow;
        edges[edge_index ^ 1][2] += tempflow;
        flow -= tempflow;
        finalflow += tempflow;
 
        if (flow == 0) break;
    }
 
    return finalflow;
}
 
int flow(int source, int sink) {
    int tempflow, ans = 0;
 
    while (true) {
        fill(level.begin(), level.end(), 0);
        if (!bfs(source, sink)) break;
 
        while (true) {
            fill(parent.begin(), parent.end(), 0);
            tempflow = dfs(source, sink, inf);
            if (tempflow == 0) break;
            ans += tempflow;
        }
    }
 
    return ans;
}
 
void dfs2(int source) {
    if (visited[source]) return;
    visited[source] = 1;
 
    for (int i : graph[source]) {
        int start = edges[i][0];
        int end = edges[i][1];
        int flow = edges[i][2];
 
        if (!flow) continue;
        dfs2(end);
    }
}
 
void solve(int xyz) {
    int n;
    cin >> n;
    REP(i, 1, n + 1) {
        addedge(0, i);
        addedge(100 + i, 201);
    }
 
    REP(i, 1, n + 1) {
        REP(j, 1, n + 1) {
            char c;
            cin >> c;
            if (c == '.') continue;
            addedge(i, 100 + j);
        }
    }
 
    cout << flow(0, 201) << endl;
    dfs2(0);
 
    REP(i, 1, n + 1) {
        if (!visited[i]) {
            cout << 1 << " " << i << endl;
        }
        if (visited[100 + i]) {
            cout << 2 << " " << i << endl;
        }
    }
}
 
signed main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    // int t; cin >> t;
    REP(xyz, 0, 1) {
        solve(xyz);
    }
}
