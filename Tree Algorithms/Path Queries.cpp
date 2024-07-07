
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
int segtree[1600016];
int n;
int query(int l,int r,int ind,int left,int right){
    if(l>r)return 0;
    if(left>=l && right<=r){return segtree[ind];}
    int mid=left+(right-left)/2;
    int left1=query(l,min(r,mid),2*ind,left,mid);
    int right1=query(max(l,mid+1),r,2*ind+1,mid+1,right);
    return left1+right1;
}
void update(int x,int val,int ind,int left,int right){
    if(left==right){segtree[ind]=val;return;}
    int mid=left+(right-left)/2;
    if(x<=mid){update(x,val,2*ind,left,mid);}
    else{update(x,val,2*ind+1,mid+1,right);}
    segtree[ind]=segtree[2*ind]+segtree[2*ind+1];
}
vector<vector<int>>adj(200001);
vector<int>start(200001);vector<int>end1(200001);
int timer=0;
void dfs(int src,int par){
    start[src]=timer++;
    for(auto child:adj[src]){
        if(child==par)continue;
        dfs(child,src);
    }
    end1[src]=timer++;
}
void solve(int xyz)
{
    int q;cin>>n>>q;
    vector<int>initial(n+1);
    REP(i,1,n+1){cin>>initial[i];}
    REP(i,0,n-1){
        int x,y;cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs(1,-1);
    for(int i=1;i<n+1;i++){
        update(start[i],initial[i],1,0,2*(n-1));
        update(end1[i],-1*initial[i],1,0,2*(n-1));
    }
    // REP(i,1,n+1){cout<<i<<" "<<start[i]<<" "<<end1[i]<<endl;}
    // REP(i,0,10){cout<<i<<" "<<segtree[i]<<endl;}
    while(q--){
        int x;cin>>x;
        if(x==2){int y;cin>>y;cout<<query(start[1],end1[y]-1,1,0,2*(n-1))<<endl;}
        else{
            int y,z;cin>>y>>z;
            update(start[y],z,1,0,2*(n-1));
            update(end1[y],-1*z,1,0,2*(n-1));
        }
    }
    // cout<<"*"<<endl;
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
