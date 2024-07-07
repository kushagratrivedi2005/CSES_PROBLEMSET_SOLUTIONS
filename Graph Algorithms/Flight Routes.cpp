
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
const int INF=1000000000000000;
int k;
void dijkstra(vector<vector<pair<int,int>>>&graph,vector<vector<int>>&dist){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>check;
    dist[1][0]=(0);
    check.push({0,1});
    while(!check.empty()){
        ii curr=check.top();
        check.pop();
        int vertex=curr.second;
        int d=curr.first;
        if(dist[vertex][k-1]<d)continue;
        for(auto i:graph[vertex]){
            if(dist[i.first][k-1]>i.second+d){
                dist[i.first][k-1]=i.second+d;
                check.push({dist[i.first][k-1],i.first});
                sort(dist[i.first].begin(),dist[i.first].end());
            }
        }
 
    }
 
}
void solve(int xyz)
{
    int n,m;cin>>n>>m>>k;
    vector<vector<pair<int,int>>>graph(n+1);
    vector<vector<int>>dist(n+1,vector<int>(k));
    REP(i,1,n+1){
        REP(j,0,k){
            dist[i][j]=INF;
        }
    }
    REP(i,0,m){
        int x,y,w;cin>>x>>y>>w;
        graph[x].pb({y,w});
    }
 
    dijkstra(graph,dist);
    REP(i,0,k){
        cout<<dist[n][i]<<" ";
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
