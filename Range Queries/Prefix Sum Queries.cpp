
#include <bits/stdc++.h>
 
#define range(it, a, b) for (ll it = a; it < b; it++)
#define all(x) begin(x), end(x)
#define ll long long
#define ull unsigned long long
#define INF64 ((ll) 1 << 60)
#define INF32 (1 << 30)
#define mset multiset
#define uset unordered_set
#define umap unordered_map 
#define pqueue priority_queue
#define ptr(A) shared_ptr<A>
 
using namespace std;
 
void setio (string name) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }   
}
 
const ll MAX_N = (ll) 2e5;
 
struct SegTree {
    struct Node {
        ptr(Node) left, right;
        ll l, r, maxi, lazy = 0;
 
        ll get_left() { return (l + r) / 2; }
        ll get_right() { return get_left() + 1; }
    };
 
    ptr(Node) root;
 
    SegTree () {
        root = ptr(Node) (new Node);
        root->l = 0;
        root->r = MAX_N - 1;
 
        build_tree(root);
    }
 
    void build_tree(ptr(Node) node) {
        if (node->l == node->r)
            return;
        
        node->left = ptr(Node) (new Node);
        node->left->l = node->l;
        node->left->r = node->get_left();
        build_tree(node->left);
 
        node->right = ptr(Node) (new Node);
        node->right->l = node->get_right();
        node->right->r = node->r;
        build_tree(node->right);
    }
 
    void push(ptr(Node) node) {
        node->left->lazy += node->lazy;
        node->left->maxi += node->lazy;
 
        node->right->lazy += node->lazy;
        node->right->maxi += node->lazy;
 
        node->lazy = 0;
    }
 
    ll _query(ll l, ll r, ptr(Node) node) {
        if (node->l == l && node->r == r)
            return node->maxi;
 
        push(node);
        ll ans = -INF64;
        if (l <= node->get_left())
            ans = _query(l, min(r, node->get_left()), node->left);
        if (r >= node->get_right())
            ans = max(ans, _query(max(l, node->get_right()), r, node->right));
 
        return ans;
    }
 
    ll query(ll l, ll r) { return _query(l, r, root); }
 
    void _update(ll l, ll r, ptr(Node) node, ll d) {
        if (node->l == l && node->r == r) {
            node->maxi += d;
            node->lazy += d;
            return;
        }
 
        push(node);
        if (l <= node->get_left())
            _update(l, min(r, node->get_left()), node->left, d);
        if (r >= node->get_right())
            _update(max(l, node->get_right()), r, node->right, d);
 
        node->maxi = max(node->left->maxi, node->right->maxi);
    }
 
    void update(ll l, ll r, ll d) { _update(l, r, root, d); }
};
 
ll n, q;
vector<ll> arr;
SegTree st;
 
void solve() {
    cin >> n >> q;
    arr.resize(n);
 
    ll x;
    range(i, 0, n) {
        cin >> x;
        st.update(i, n - 1, x);
    }
 
    ll t, a, b;
    range(i, 0, q) {
        cin >> t >> a >> b;
 
        if (t == 1) {
            a--;
            ll dif = b - (st.query(a, a) - (a ? st.query(a - 1, a - 1) : 0));
            st.update(a, n - 1, dif);
            continue;
        }
 
        a--; b--;
        cout << max(0ll, st.query(a, b) - (a ? st.query(a - 1, a - 1) : 0)) << '\n'; 
    }
}
 
int main () {
    setio("");
    ll t = 1; 
    // cin >> t;
    while (t--) solve();
}
