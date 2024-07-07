
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
const int maxn = 2e5 + 1;
const int logmax = 19;
 
int n, d, centroidparent[maxn], size1[maxn], depth[maxn], timer, ancestor[maxn][logmax], nearest[maxn], intime[maxn], outtime[maxn], visited[maxn];
vector<int> graph[maxn];
 
void dfs(int x, int par) {
    intime[x] = ++timer;
    depth[x] = depth[par] + 1;
    size1[x] = 1;
    ancestor[x][0] = par;
    REP(i, 1, logmax) {
        ancestor[x][i] = ancestor[ancestor[x][i - 1]][i - 1];
    }
    for(auto i : graph[x]) {
        if(i != par) {
            dfs(i, x);
            size1[x] += size1[i];
        }
    }
    outtime[x] = ++timer;
}
int dfs2(int x,int par){
    if(visited[x])return 0;
    size1[x]=1;for(int i:graph[x]){if(i!=par){size1[x]+=dfs2(i,x);}}return size1[x];
}
bool isancestor(int x, int y) {
    return intime[x] <= intime[y] && outtime[x] >= outtime[y];
}
 
int lca(int x, int y) {
    if (isancestor(x, y)) return x;
    if (isancestor(y, x)) return y;
    for (int i = logmax - 1; i >= 0; i--) {
        if (!isancestor(ancestor[x][i], y)) {
            x = ancestor[x][i];
        }
    }
    return ancestor[x][0];
}
 
int dist(int x, int y) {
    return depth[x] + depth[y] - 2 * depth[lca(x, y)];
}
 
int find_centroid(int n, int par, int nodes) {
    for (int i : graph[n]) {
        if (i != par) {
            if (!visited[i] && size1[i] > nodes / 2)
                return find_centroid(i, n, nodes);
        }
    }
    return n;
}
 
void build_centroid(int n, int par) {
    dfs2(n,-1);
    int x = find_centroid(n, -1, size1[n]);
    visited[x] = true;
    centroidparent[x] = par;
    for (auto i : graph[x]) {
        if (!visited[i]) {
            build_centroid(i, x);
        }
    }
}
 
bool comp(int a, int b) {
    return depth[a] > depth[b];
}
 
void update(int x) {
    nearest[x] = 0;
    int curr = x;
    while(centroidparent[curr] != -1) {
        curr = centroidparent[curr];
        nearest[curr] = min(nearest[curr], dist(x, curr));
    }
}
 
int query(int x) {
    int ans = nearest[x];
    int curr = x;
    while(centroidparent[curr] != -1) {
        curr = centroidparent[curr];
        ans = min(nearest[curr] + dist(curr, x), ans);
    }
    return ans;
}
 
void solve(int xyz) {
    cin >> n >> d;
    REP(i, 0, n - 1) {
        int x, y;
        cin >> x >> y;
        graph[x].pb(y);
        graph[y].pb(x);
    }
    dfs(1, 1);
    build_centroid(1, -1);
    REP(i, 0, maxn) {
        nearest[i] = INT_MAX;
    }
    vector<int> nodes(n);
    REP(i, 0, n) {
        nodes[i] = i + 1;
    }
    sort(nodes.begin(), nodes.end(), comp);
    vector<int> ans;
    for(int x : nodes) {
        int nearest_office = query(x);
        if(nearest_office >= d) {
            update(x);
            ans.pb(x);
        }
    }
    cout << ans.size() << endl;
    for(auto i : ans) {
        cout << i << " ";
    }
    cout << endl;
}
 
signed main() {
    #ifndef ONLINE_JUDGE    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
  
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    REP(xyz, 0, 1) {
        solve(xyz);
    }
}
