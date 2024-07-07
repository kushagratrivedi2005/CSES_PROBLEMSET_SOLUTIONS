
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key
 
typedef struct node {
    int suffix;
    int prefix;
    int length;
    int maximum;
} node;
 
string s;
node segtree1[800010];
node segtree2[800010];
 
void build1(int index, int low, int high) {
    if (low == high) {
        segtree1[index].prefix = (s[low] == '1' ? 1 : 0);
        segtree1[index].suffix = (s[low] == '1' ? 1 : 0);
        segtree1[index].maximum = (s[low] == '1' ? 1 : 0);
        segtree1[index].length = 1;
        return;
    }
    int mid = (low + high) / 2;
    build1(2 * index + 1, low, mid);
    build1(2 * index + 2, mid + 1, high);
 
    segtree1[index].prefix = (segtree1[2 * index + 1].prefix == segtree1[2 * index + 1].length ? segtree1[2 * index + 1].length + segtree1[2 * index + 2].prefix : segtree1[2 * index + 1].prefix);
    segtree1[index].suffix = (segtree1[2 * index + 2].suffix == segtree1[2 * index + 2].length ? segtree1[2 * index + 2].length + segtree1[2 * index + 1].suffix : segtree1[2 * index + 2].suffix);
    segtree1[index].maximum = max({segtree1[2 * index + 1].suffix + segtree1[2 * index + 2].prefix, segtree1[2 * index + 1].maximum, segtree1[2 * index + 2].maximum});
    segtree1[index].length = segtree1[2 * index + 1].length + segtree1[2 * index + 2].length;
}
 
void update1(int index, int low, int high, int value, int ind) {
    if (low == high) {
        segtree1[index].prefix = (value == 1 ? 1 : 0);
        segtree1[index].suffix = (value == 1 ? 1 : 0);
        segtree1[index].maximum = (value == 1 ? 1 : 0);
        return;
    }
    int mid = (low + high) / 2;
    if (ind <= mid) {
        update1(2 * index + 1, low, mid, value, ind);
    } else {
        update1(2 * index + 2, mid + 1, high, value, ind);
    }
 
    segtree1[index].prefix = (segtree1[2 * index + 1].prefix == segtree1[2 * index + 1].length ? segtree1[2 * index + 1].length + segtree1[2 * index + 2].prefix : segtree1[2 * index + 1].prefix);
    segtree1[index].suffix = (segtree1[2 * index + 2].suffix == segtree1[2 * index + 2].length ? segtree1[2 * index + 2].length + segtree1[2 * index + 1].suffix : segtree1[2 * index + 2].suffix);
    segtree1[index].maximum = max({segtree1[2 * index + 1].suffix + segtree1[2 * index + 2].prefix, segtree1[2 * index + 1].maximum, segtree1[2 * index + 2].maximum});
}
 
void build2(int index, int low, int high) {
    if (low == high) {
        segtree2[index].prefix = (s[low] == '0' ? 1 : 0);
        segtree2[index].suffix = (s[low] == '0' ? 1 : 0);
        segtree2[index].maximum = (s[low] == '0' ? 1 : 0);
        segtree2[index].length = 1;
        return;
    }
    int mid = (low + high) / 2;
    build2(2 * index + 1, low, mid);
    build2(2 * index + 2, mid + 1, high);
 
    segtree2[index].prefix = (segtree2[2 * index + 1].prefix == segtree2[2 * index + 1].length ? segtree2[2 * index + 1].length + segtree2[2 * index + 2].prefix : segtree2[2 * index + 1].prefix);
    segtree2[index].suffix = (segtree2[2 * index + 2].suffix == segtree2[2 * index + 2].length ? segtree2[2 * index + 2].length + segtree2[2 * index + 1].suffix : segtree2[2 * index + 2].suffix);
    segtree2[index].maximum = max({segtree2[2 * index + 1].suffix + segtree2[2 * index + 2].prefix, segtree2[2 * index + 1].maximum, segtree2[2 * index + 2].maximum});
    segtree2[index].length = segtree2[2 * index + 1].length + segtree2[2 * index + 2].length;
}
 
void update2(int index, int low, int high, int value, int ind) {
    if (low == high) {
        segtree2[index].prefix = (value == 0 ? 1 : 0);
        segtree2[index].suffix = (value == 0 ? 1 : 0);
        segtree2[index].maximum = (value == 0 ? 1 : 0);
        return;
    }
    int mid = (low + high) / 2;
    if (ind <= mid) {
        update2(2 * index + 1, low, mid, value, ind);
    } else {
        update2(2 * index + 2, mid + 1, high, value, ind);
    }
 
    segtree2[index].prefix = (segtree2[2 * index + 1].prefix == segtree2[2 * index + 1].length ? segtree2[2 * index + 1].length + segtree2[2 * index + 2].prefix : segtree2[2 * index + 1].prefix);
    segtree2[index].suffix = (segtree2[2 * index + 2].suffix == segtree2[2 * index + 2].length ? segtree2[2 * index + 2].length + segtree2[2 * index + 1].suffix : segtree2[2 * index + 2].suffix);
    segtree2[index].maximum = max({segtree2[2 * index + 1].suffix + segtree2[2 * index + 2].prefix, segtree2[2 * index + 1].maximum, segtree2[2 * index + 2].maximum});
}
 
void solve(int xyz) {
    cin >> s;
    int q;
    cin >> q;
    build1(0, 0, s.length() - 1);
    build2(0, 0, s.length() - 1);
    while (q--) {
        int x;
        cin >> x;
        x--;
        if (s[x] == '0') {
            update1(0, 0, s.length() - 1, 1, x);
            update2(0,0,s.length()-1,1,x);
            s[x] = '1';
        } else {
            update1(0, 0, s.length() - 1, 0, x);
            update2(0, 0, s.length() - 1, 0, x);
            s[x] = '0';
        }
 
        cout << max(segtree1[0].maximum, segtree2[0].maximum) << " ";
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
