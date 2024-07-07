
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
void dfs(vector<vector<int>>&graph,vector<int>&visited,int n,stack<int>&st){
  visited[n]=1;
  for(int i:graph[n]){
    if(visited[i])continue;
    dfs(graph,visited,i,st);
  }
  st.push(n);
}
void solve(int xyz)
{
  int n,m;cin>>n>>m;
  vector<vector<int>>graph(n+1);
  REP(i,0,m){
    int x,y;cin>>x>>y;
    graph[y].pb(x);
  }
  vector<int>parent(n+1,-1);
  vector<int>dist(n+1,1);
  queue<int>q;
  vector<int>visited(n+1,0);
  stack<int>st;
  dfs(graph,visited,n,st);
  while(!st.empty()){
    int curr=st.top(); st.pop();
    for(int child:graph[curr]){
      if(dist[curr]+1>dist[child]){
        dist[child]=1+dist[curr];
        parent[child]=curr;
      }
    }
  }
  if(parent[1]==-1){cout<<"IMPOSSIBLE"<<endl; return;}
  cout<<dist[1]<<endl;
  int curr=1;
  cout<<curr<<" ";
  while(curr!=n){
    curr=parent[curr];
    cout<<curr<<" ";
  }
  return;
}
 
 
signed main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif
  
ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  // int t;cin>>t;/
  REP(xyz,0,1){
    solve(xyz);
  }
}
