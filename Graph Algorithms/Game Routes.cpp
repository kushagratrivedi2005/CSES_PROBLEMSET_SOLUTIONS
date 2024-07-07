
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
    graph[x].pb(y);
  }
  vector<int>ways(n+1,0);
  vector<int>visited(n+1,0);
  stack<int>st;
  REP(i,1,n+1)
  dfs(graph,visited,i,st);
    stack<int>rev;
    while(!st.empty()){
        rev.push(st.top());
        st.pop();
    }
    while(!rev.empty()){
        int curr=rev.top(); rev.pop();
        if(curr==n){ways[curr]++;}
        for(auto i:graph[curr]){
            ways[curr]+=ways[i]%mod;
        }
        // cout<<curr<<endl;
    }
    cout<<ways[1]%mod<<endl;
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
