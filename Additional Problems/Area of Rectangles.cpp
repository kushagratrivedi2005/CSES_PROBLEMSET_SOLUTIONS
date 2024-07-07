
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
 
const int N=2*1e6+2;
 
struct rectangle {
    int t, x, y0, y1;
};
 
bool comp(const rectangle &a, const rectangle &b) {
    return a.x < b.x;
}
 
int n;
vector<rectangle> recs;
ii seg[4 * N];
int lazy[4 * N];
 
ii Union(ii a, ii b) {
    if (a.first < b.first) return a;
    if (a.first > b.first) return b;
    return {a.first, a.second + b.second};
}
 
void prop(int ind, int low, int high) {
    if (lazy[ind] != 0) {
        seg[ind].first += lazy[ind];
        if (low != high) { 
            lazy[2 * ind] += lazy[ind];
            lazy[2 * ind + 1] += lazy[ind];
        }
        lazy[ind] = 0;
    }
}
 
void build(int index, int low, int high) {
    if (low == high) {
        seg[index] = {0, 1};
        return;
    }
    int mid = (low + high) / 2;
    build(2 * index, low, mid);
    build(2 * index + 1, mid + 1, high);
    seg[index] = Union(seg[2 * index], seg[2 * index + 1]);
}
 
void update(int index, int low, int high, int val, int l, int r) {
    prop(index, low, high);
    if (low > r || high < l) return;
    if (l <= low && high <= r) {
        lazy[index] += val;
        prop(index, low, high);
        return;
    }
    int mid = (low + high) / 2;
    update(2 * index, low, mid, val, l, r);
    update(2 * index + 1, mid + 1, high, val, l, r);
    seg[index] = Union(seg[2 * index], seg[2 * index + 1]);
}
 
int query() {
    return N - seg[1].second;
}
 
void solve(int xyz) {
    cin >> n;
    build(1, 1, N);
    REP(i, 0, n) {
        int x0, y0, x1, y1;
        cin >> x0 >> y0 >> x1 >> y1;
        x0 += 1e6; y0 += 1e6+1; x1 += 1e6; y1 += 1e6+1;
        recs.pb({1, x0, y0, y1 - 1});
        recs.pb({-1, x1, y0, y1 - 1});
    }
    sort(recs.begin(), recs.end(), comp);
    int ans = 0;
    update(1, 1, N, recs[0].t, recs[0].y0, recs[0].y1);
    REP(i, 1, 2 * n) {
        ans += query() * (recs[i].x - recs[i - 1].x);
        update(1, 1, N, recs[i].t, recs[i].y0, recs[i].y1);
    }
    cout << ans;
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
