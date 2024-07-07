
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
int ancestor[200001][20];
int depth[200001];
void preprocess(int src,int par,vector<vector<int>>&graph){
    ancestor[src][0]=par;
    REP(i,1,20){
        if(ancestor[src][i-1]!=-1){
            ancestor[src][i]=ancestor[ancestor[src][i-1]][i-1];
        }
        else{
            ancestor[src][i]=-1;
        }
    }
    for(auto child:graph[src]){
        preprocess(child,src,graph);
    }
}
void dept(int src,int dep,vector<vector<int>>&graph){
    depth[src]=dep;
    for(auto child:graph[src]){
        dept(child,dep+1,graph);
    }
}
 
int lca(int a,int b){
    if(depth[a]<depth[b]){swap(a,b);}
    int d=depth[a]-depth[b];
    for(int i=0;i<20;i++){
        if(d&(1<<i)){
            a=ancestor[a][i];
        }
    }
    if(a==b)return a;
    for(int i=19;i>=0;i--){
        if(ancestor[a][i]!=ancestor[b][i]){
            a=ancestor[a][i];
            b=ancestor[b][i];
        }
    }
    return ancestor[a][0];
}
 
void solve(int xyz)
{
    int n,q;cin>>n>>q;
    vector<vector<int>>graph(n+1);
    REP(i,2,n+1){
        int x;cin>>x;
        graph[x].pb(i);
    }
    preprocess(1,-1,graph);
   dept(1,0,graph);
   while(q--){
    int x,y;cin>>x>>y;
    cout<<lca(x,y)<<endl;
   }
}
 
 
signed main(){
// #ifndef ONLINE_JUDGE
// freopen("input.txt","r",stdin);
// freopen("output.txt","w",stdout);
// #endif
  
ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//   int t;cin>>t;
  REP(xyz,0,1){
    solve(xyz);
  }
}
