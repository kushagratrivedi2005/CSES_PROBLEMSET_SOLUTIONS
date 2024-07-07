
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
void build(int ind,int low,int high){
    if(low==high){segtree[ind]=1;return;}
    int mid=(low+high)>>1;
    build(2*ind+1,low,mid);
    build(2*ind+2,mid+1,high);
    segtree[ind]=segtree[2*ind+1]+segtree[2*ind+2];
}   
void update(int ind,int low,int high,int i){
    if(low==high){segtree[ind]=0;return;}
    int mid=(low+high)/2;
    if(i>mid){update(2*ind+2,mid+1,high,i);}
    else{update(2*ind+1,low,mid,i);}
    segtree[ind]=segtree[2*ind+1]+segtree[2*ind+2];
}
int query(int ind,int low,int high,int i){
    if(low==high){return low;}
    int mid=(low+high)>>1;
    if(segtree[2*ind+1]>i)return query(2*ind+1,low,mid,i);
    return query(2*ind+2,mid+1,high,i-segtree[2*ind+1]);
}
void solve(int xyz)
{
   int n;cin>>n;vector<int>values(n);REP(i,0,n)cin>>values[i];
   vector<int>ans(n);
   build(0,0,n-1);
   REP(i,0,n){
    int x;cin>>x;   
    x--;
    int z=query(0,0,n-1,x);
    ans[i]=values[z];
    update(0,0,n-1,z);
   }
   REP(i,0,n){cout<<ans[i]<<" ";}
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
