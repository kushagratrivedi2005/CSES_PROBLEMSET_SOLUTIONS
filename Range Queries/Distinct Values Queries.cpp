
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
int bit[200001];
int n;
void update(int a,int val){
    a++;
    for(int i=a;i<=n;i+=i&(-i)){
        bit[i]+=val;
    }
}
int query(int b){
    b++;
    int ans=0;for(int i=b;i>0;i-=i&(-i)){ans+=bit[i];}
    return ans;
}
void solve(int xyz) {
  int q;cin>>n>>q;vector<int>values(n);REP(i,0,n)cin>>values[i];
  vector<vector<pair<int,int>>> queries(n);
  vector<int>solution(q);
  map<int,int>index;
  REP(i,0,q){
    int a,b;cin>>a>>b;a--;b--;queries[b].push_back({a,i});
  }
  REP(i,0,n){
    int val=values[i];
    if(index.count(val)>0){update(index[val],-1);}
    index[val]=i;update(i,1);
    for(auto q:queries[i]){
        solution[q.second]=query(i)-query(q.first-1);
    }
  }
  REP(i,0,q){cout<<solution[i]<<endl;}
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
