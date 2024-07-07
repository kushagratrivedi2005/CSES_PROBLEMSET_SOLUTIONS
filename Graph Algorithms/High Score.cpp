
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
void dfs(vector<vector<pair<int,int>>>&graph,vector<int>&visited,int n){
    visited[n]=1;
    for(auto i:graph[n]){
        if(!visited[i.first]){
            dfs(graph,visited,i.first);
        }
    }
}
const int INF=10000000000000000;
void solve(int xyz)
{
 int n,m;cin>>n>>m;
 vector<vector<pair<int,int>>>reverse(n+1);
 vector<vector<pair<int,int>>>graph(n+1);
 vector<array<int,3>>edges(m);
 REP(i,0,m){
    int x,y,z;cin>>x>>y>>z;
    edges[i]={x,y,-z};
    graph[x].pb({y,z});
    reverse[y].pb({x,z});
 }
 vector<int>visited(n+1,0);
 vector<int>visited2(n+1,0);
    {dfs(reverse,visited,n);}
    {dfs(graph,visited2,1);}
//  REP(i,1,n+1){cout<<visited[i]<<" ";}
 vector<int>dist(n+1,INF);
 dist[1]=0;
 REP(j,0,n-1){
    REP(i,0,m){
        if(visited[edges[i][1]] && visited[edges[i][0]] && visited2[edges[i][1]] && visited2[edges[i][0]])
        if(dist[edges[i][1]]>dist[edges[i][0]]+edges[i][2]){
            dist[edges[i][1]]=dist[edges[i][0]]+edges[i][2];
        }
    }
 }
//   REP(i,1,n+1){cout<<dist[i]<<" ";}
    REP(i,0,m){
         if(visited[edges[i][1]] && visited[edges[i][0]] && visited2[edges[i][1]] && visited2[edges[i][0]])
        if(dist[edges[i][1]]>dist[edges[i][0]]+edges[i][2]){
            cout<<-1<<endl;return;
        }
    }
    cout<<-dist[n]<<endl;return;
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
