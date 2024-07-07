
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define mod 1000000007
#define int long long
#define REP(i, m, n) for (int i = m; i < n; i++)
#define pb push_back
#define ff first
#define ss second
#define vi vector<int>
#define ii pair<int, int>
#define mp make_pair
#define vii vector<ii>
using namespace std;
using namespace __gnu_pbds;
template <class T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key
 
int timer = 1;
vector<pair<int, int>> ans;
 
void dfs(vector<int>& visited, vector<int>& odd, vector<vector<int>>& graph, int n, int parent) {
    visited[n] = timer++;
    for (auto i : graph[n]) {
        if (i == parent) continue;
        if (!visited[i]) {
            dfs(visited, odd, graph, i, n);
            if (odd[i]) {
                ans.pb({i, n});
                odd[i] ^= 1;
            } else {
                ans.pb({n, i});
                odd[n] ^= 1;
            }
        } else if(visited[n]>visited[i]) {
            ans.pb({i, n});
            odd[i] ^= 1;
        }
    }
}
 
void solve(int xyz) {
    int n, m;   
    cin >> n >> m;
    vector<vector<int>> graph(n);
    REP(i, 0, m) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        graph[x].pb(y);
        graph[y].pb(x);
    }
    vector<int> visited(n, 0);
    vector<int> odd(n, 0);
    REP(i, 0, n) {
        if (!visited[i]) dfs(visited, odd, graph, i, -1);
    }
    int sum = accumulate(odd.begin(), odd.end(), 0);
    if (sum) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    REP(i, 0, m) {
        cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl; 
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
    //   int t;cin>>t;
    REP(xyz, 0, 1) {
        solve(xyz);
    }
}
