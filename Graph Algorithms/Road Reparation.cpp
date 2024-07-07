
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
vector<int>size(100001,0);
vector<int>parent(100001,-1);
void make(int node){
    parent[node]=node;
    size[node]=1;
}
int find(int a){
    if(a==parent[a])return a;
    return parent[a]=find(parent[a]);
}
void Union(int a,int b){
    a=find(a); b=find(b);
    if(a==b)return;
    if(size[a]<size[b]){swap(a,b);}
    parent[b]=a;
    size[a]+=size[b];
}
void solve(int xyz)
{
  int n,m;cin>>n>>m;
  vector<vector<pair<int,int>>>graph(n+1);
    REP(i,1,n+1)make(i);
    vector<array<int,3>>edges;
    REP(i,0,m){
        int x,y,z;cin>>x>>y>>z;
        edges.pb({z,y,x});
    }
    sort(edges.begin(),edges.end());
    int ans=0;  
    
    REP(i,0,m){
        if(find(edges[i][1])==find(edges[i][2]))continue;
        else{Union(edges[i][1],edges[i][2]);ans+=edges[i][0];}
    }
    if(size[find(1)]!=n){cout<<"IMPOSSIBLE"<<endl; return;}
    cout<<ans<<endl;
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
