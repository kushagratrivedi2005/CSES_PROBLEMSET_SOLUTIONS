
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
int found=0;
void dfs(vector<vector<int>>&graph,int n,vector<int>&visited,vector<int>&temp)
{
    visited[n]=1;
    temp[n]=1;
    for(auto i:graph[n]){
        if(temp[i]==1){found=1;return;}
        if(!visited[i]){
            dfs(graph,i,visited,temp);
        }
    }
    temp[n]=0;
}
void dfs2(vector<vector<int>>&graph,int n,vector<int>&visited2,stack<int>&st)
{
    visited2[n]=1;
    for(auto i:graph[n]){
        if(!visited2[i]){
            dfs2(graph,i,visited2,st);
        }
 
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
  vector<int>visited(n+1,0);
  vector<int>temp(n+1,0);
    REP(i,1,n+1){
        if(!visited[i]){
            dfs(graph,i,visited,temp);
            if(found){cout<<"IMPOSSIBLE";return;}
        }
    }
    // cout<<"*";
    stack<int>st;
    vector<int>visited2(n+1,0);
     REP(i,1,n+1){
        if(!visited2[i]){
            dfs2(graph,i,visited2,st);
        }
    }
    while(!st.empty()){
        cout<<st.top()<<" ";
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
