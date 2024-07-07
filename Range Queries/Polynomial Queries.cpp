
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
pair<int,int> lazy[800010]={{0,0}};
long long gauss(int start, int len, int step)
        {
            return 1LL * start * len + 1LL * step * (len - 1) * len / 2;
        }
        void lz(int node, int L, int R)
        {
            segtree[node] += gauss(lazy[node].first, R - L + 1, lazy[node].second);
            int mid = (L + R) / 2;
            if(L != R)
            {
                lazy[node*2+1].first += lazy[node].first;
                lazy[node*2+1].second += lazy[node].second;
                lazy[node*2+2].first += lazy[node].first + 1LL * lazy[node].second * (mid - L + 1);
                lazy[node*2+2].second += lazy[node].second;
            }
            lazy[node] = {0, 0};
        }
void build(int ind,int low,int high,vector<int>&values){
    if(low==high){segtree[ind]=values[low];return;}
    int mid=(low+high)>>1;
    build(2*ind+1,low,mid,values);
    build(2*ind+2,mid+1,high,values);
    segtree[ind]=segtree[2*ind+1]+segtree[2*ind+2];
}
 
void update(int ind,int low,int high,int l,int r,int val){
    int mid=(low+high)>>1;
    if(lazy[ind].first){lz(ind,low,high);}
    if(l>high || r<low)return;
    if(low>=l && high<=r){
        lazy[ind].first = val + (low-l);
                lazy[ind].second++;
                lz(ind, low, high);
                return;
    }
    update(2*ind+1,low,mid,l,r,val);
    update(2*ind+2,mid+1,high,l,r,val);
    segtree[ind]=segtree[2*ind+1]+segtree[2*ind+2];
}
int query(int ind,int low,int high,int l,int r){
    int mid=(low+high)>>1;
        if(lazy[ind].first){lz(ind,low,high);}
    if(low>r || high<l)return 0;
     if(low>=l && high<=r)return segtree[ind];
     return query(2*ind+1,low,mid,l,r)+query(2*ind+2,mid+1,high,l,r);
}
 
void solve(int xyz)
{
    int n,q;cin>>n>>q;vector<int>values(n);REP(i,0,n)cin>>values[i];
    build(0,0,n-1,values);
    while(q--){
        int x;cin>>x;
        if(x==2){int y,z;cin>>y>>z;y--;z--;cout<<query(0,0,n-1,y,z)<<endl;}
        else{
            int z,y;cin>>z>>y;z--;y--;
            update(0,0,n-1,z,y,1);
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
