
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
int lazy[800010]={0};
void build(int ind,int low,int high,vector<int>&values){
    if(low==high){segtree[ind]=values[low];return;}
    int mid=(low+high)>>1;
    build(2*ind+1,low,mid,values);
    build(2*ind+2,mid+1,high,values);
    segtree[ind]=segtree[2*ind+1]+segtree[2*ind+2];
}
 
void update(int ind,int low,int high,int l,int r,int val){
    if(lazy[ind]!=0){segtree[ind]+=(high-low+1)*lazy[ind];
    if(low!=high){lazy[2*ind+1]+=lazy[ind]; lazy[2*ind+2]+=lazy[ind];}lazy[ind]=0;}
    if(l>high || r<low)return;
    if(low>=l && high<=r){
        segtree[ind]+=(high-low+1)*val;
        if(low!=high){lazy[2*ind+1]+=val; lazy[2*ind+2]+=val;}
        return;
    }
    int mid=(low+high)>>1;
    update(2*ind+1,low,mid,l,r,val);
    update(2*ind+2,mid+1,high,l,r,val);
    segtree[ind]=segtree[2*ind+1]+segtree[2*ind+2];
}
int query(int ind,int low,int high,int i){
    if(lazy[ind]!=0){segtree[ind]+=(high-low+1)*lazy[ind];
    if(low!=high){lazy[2*ind+1]+=lazy[ind]; lazy[2*ind+2]+=lazy[ind];}lazy[ind]=0;}
    if(low==high){return segtree[ind];}
    int mid=(low+high)>>1;
    if(i<=mid)return query(2*ind+1,low,mid,i);
    return query(2*ind+2,mid+1,high,i);
}
 
void solve(int xyz)
{
    int n,q;cin>>n>>q;vector<int>values(n);REP(i,0,n)cin>>values[i];
    build(0,0,n-1,values);
    while(q--){
        int x;cin>>x;
        if(x==2){int y;cin>>y; cout<<query(0,0,n-1,y-1)<<endl;}
        else{
            int z,y;cin>>z>>y;z--;y--;
            int l;cin>>l;
            update(0,0,n-1,z,y,l);
        }
    }
 
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
