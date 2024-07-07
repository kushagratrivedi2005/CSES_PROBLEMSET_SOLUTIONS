
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
void dfs(vector<vector<int>>&graph,vector<int>&visited,int n,vector<vector<int>>&edges,vector<int>&degree,stack<int>&st){
    while(degree[n]<graph[n].size()){
      int child=graph[n][degree[n]];
      int edge=edges[n][degree[n]];
      degree[n]++;
      if(visited[edge])continue;
      visited[edge]=1;
      dfs(graph,visited,child,edges,degree,st);
    }
    st.push(n);
}
 
void solve(int xyz)
{
    int n,k;cin>>n>>k;
    vector<vector<int>>edges(n+1);
    vector<vector<int>>graph(n+1);
    vector<int>degree(n+1,0);
    vector<int>visited(k,0);
    REP(i,0,k){
        int x,y;cin>>x>>y;
        graph[x].pb(y);
        graph[y].pb(x);
        degree[x]++;
        degree[y]++;
        edges[x].pb(i);
        edges[y].pb(i);
    }
    REP(i,1,n+1){
      if(degree[i]%2!=0){cout<<"IMPOSSIBLE"<<endl;return;}
    }
    REP(i,1,n+1){degree[i]=0;}
    stack<int>st;
    dfs(graph,visited,1,edges,degree,st);
    if(st.size()!=k+1){cout<<"IMPOSSIBLE"<<endl;return;}
    while(!st.empty()){
      int x=st.top();
      cout<<x<<" ";
      st.pop();
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
