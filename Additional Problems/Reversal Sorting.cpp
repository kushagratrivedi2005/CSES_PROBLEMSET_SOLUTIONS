
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
// treap functions from online resource
const int inf = 1e9;
struct treap{
    int val, mini, size1, priority;
    bool rev;
    treap *left, *right;
    treap(int v){
        val = mini = v;size1 = 1;priority = rand();
        rev = 0;left = right = NULL;
    }
};
  void pull(treap*root){
        root->mini = min(min(root->left? root->left->mini : inf, root->right? root->right->mini : inf), root->val);
        root->size1 = (root->left? root->left->size1 : 0) + (root->right? root->right->size1 : 0) + 1;
    }
void push(treap*root){
        if(!root->rev) return;
        swap(root->left, root->right);
        if(root->left) root->left->rev ^= 1;
        if(root->right) root->right->rev ^= 1;
        root->rev = 0;
    }
 int find(treap*root,int k){
        push(root);
        int leftside = (root->left? root->left->size1 : 0) + 1;
        if(root->val == k) return leftside;
        if(root->left && root->left->mini == k) return find(root->left,k);
        else return find(root->right,k) + leftside;
    }
 
int size(treap *t){
    return t? t->size1 : 0;
}
treap* merge(treap *left, treap *right){
    if(!left || !right) return left? left : right;
    if(left->priority > right->priority){
        push(left);
        left->right = merge(left->right, right);
        pull(left);
        return left;
    }else{
        push(right);
        right->left = merge(left, right->left);
        pull(right);
        return right;
    }
}
void split(treap *root, treap *&left, treap *&right, int pos){
    if(!root){
        left = right = NULL;return;
    }
    push(root);
    if(pos <= size(root->left)){
        right = root;
        split(root->left, left, right->left, pos);
        pull(right);
    }else{
        left = root;
        split(root->right, left->right, right, pos - size(root->left) - 1);
        pull(left);
    }
}
 
vector<pair<int, int>> ans;
void solve(int xyz)
{
  srand(time(NULL));
    int n;cin>>n;
    treap *temp1 = NULL, *temp2 = NULL, *temp3 = NULL, *temp4 = NULL;
    REP(i,1,n+1){
        int x;cin >> x;temp1 = merge(temp1, new treap(x));}
    REP(i,1,n+1){
        split(temp1,temp2,temp3,i-1);int pos = find(temp3,i);ans.pb({i,i+pos-1});
        split(temp3, temp3, temp4, pos);
        temp3->rev ^= 1;
        temp1 = merge(temp2, merge(temp3, temp4));}
    cout << ans.size() <<endl;
    REP(i,0,ans.size()){cout<<ans[i].first<<" "<<ans[i].second<<endl;}
    return;
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
