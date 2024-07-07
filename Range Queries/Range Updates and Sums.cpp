
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
 
/*
code BY-
 █ ▄▀  █  █  █▀▀▀█  █  █  █▀▀█  █▀▀█  █▀▀█  █▀▀█ 　 
 █▀▄   █  █  ▀▀▀▄▄  █▀▀█  █▄▄█  █ ▄▄  █▄▄▀  █▄▄█ 　 
 █  █  ▀▄▄▀  █▄▄▄█  █  █  █  █  █▄▄█  █  █  █  █ 　 
 
▀▀█▀▀ █▀▀█ ▀█▀  █   █  █▀▀▀ █▀▀▄ ▀█▀ 
  █   █▄▄▀  █    █ █   █▀▀▀ █  █  █
  █   █  █ ▄█▄   ▀▄▀   █▄▄▄ █▄▄▀ ▄█▄ 
*/
int segtree[800010];
pair<int, int> lazy[800010] = {{0, 0}};
 
void build(int ind, int low, int high, vector<int>& values) {
    if (low == high) {
        segtree[ind] = values[low];
        return;
    }
    int mid = (low + high) >> 1;
    build(2 * ind + 1, low, mid, values);
    build(2 * ind + 2, mid + 1, high, values);
    segtree[ind] = segtree[2 * ind + 1] + segtree[2 * ind + 2];
}
 
void propagate(int ind, int low, int high) {
    if (lazy[ind].second == 1) { // Add
        segtree[ind] += (high - low + 1) * lazy[ind].first;
        if (low != high) {
            lazy[2 * ind + 1].first += lazy[ind].first;
            lazy[2 * ind + 2].first += lazy[ind].first;
            if(lazy[2*ind+1].second!=2)
            lazy[2 * ind + 1].second = 1;
            if(lazy[2*ind+1].second!=2)
            lazy[2 * ind + 2].second = 1;
        }
        lazy[ind] = {0, 0};
    }
    if (lazy[ind].second == 2) { // Set
        segtree[ind] = (high - low + 1) * lazy[ind].first;
        if (low != high) {
            lazy[2 * ind + 1].first = lazy[ind].first;
            lazy[2 * ind + 2].first = lazy[ind].first;
            lazy[2 * ind + 1].second = lazy[ind].second;
            lazy[2 * ind + 2].second = lazy[ind].second;
        }
        lazy[ind] = {0, 0};
    }
}
 
void update(int ind, int low, int high, int l, int r, int val, int z) {
    propagate(ind, low, high);
    if (l > high || r < low) return;
    if (low >= l && high <= r) {
        if (z == 2) { // Set
            lazy[ind] = {val, 2};
        } else if (z == 1) { // Add
            lazy[ind] = {val, 1};
        }
        propagate(ind, low, high);
        return;
    }
    int mid = (low + high) >> 1;
    update(2 * ind + 1, low, mid, l, r, val, z);
    update(2 * ind + 2, mid + 1, high, l, r, val, z);
    segtree[ind] = segtree[2 * ind + 1] + segtree[2 * ind + 2];
}
 
int query(int ind, int low, int high, int l, int r) {
    propagate(ind, low, high);
    if (l > high || r < low) return 0;
    if (low >= l && high <= r) return segtree[ind];
    int mid = (low + high) >> 1;
    return query(2 * ind + 1, low, mid, l, r) + query(2 * ind + 2, mid + 1, high, l, r);
}
 
void solve(int xyz) {
    int n, q;
    cin >> n >> q;
    vector<int> values(n);
    REP(i, 0, n) cin >> values[i];
    build(0, 0, n - 1, values);
    while (q--) {
        int x;
        cin >> x;
        if (x == 3) {
            int y, z;
            cin >> y >> z;
            cout << query(0, 0, n - 1, y - 1, z - 1) << endl;
        }
        if (x == 2) {
            int l, r, z;
            cin >> l >> r >> z;
            update(0, 0, n - 1, l - 1, r - 1, z, 2);
        }
        if (x == 1) {
            int l, r, z;
            cin >> l >> r >> z;
            update(0, 0, n - 1, l - 1, r - 1, z, 1);
        }
    }
}
 
signed main() {
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //   int t;cin>>t;
    REP(xyz, 0, 1) {
        solve(xyz);
    }
}
