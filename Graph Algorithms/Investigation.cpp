
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
void dijkstra2(vector<vector<pair<int,int>>>&graph,vector<int>&visited,vector<int>&max,vector<int>&min,vector<int>&num,vector<int>&dist){
    set<pair<int,int>>check;
    dist[1]=0;
    num[1]=1;
    check.insert({0,1});
    while(!check.empty()){
        ii curr=*check.begin();
        int distance=curr.first;
        int vertex=curr.second;
    check.erase(check.begin());
        if(visited[vertex])continue;
        visited[vertex]=1;
        for(auto child:graph[vertex]){
            if(dist[child.first]>child.second+dist[vertex]){
                dist[child.first]=child.second+dist[vertex];
                check.insert({dist[child.first],child.first});
            }
        }
    }
}
 
void dijkstra(vector<vector<pair<int,int>>>&graph,vector<int>&visited,vector<int>&max,vector<int>&min,vector<int>&num,vector<int>&dist){
    set<pair<int,int>>check;
    dist[1]=0;
    min[1]=0;
    max[1]=0;
    num[1]=1;
    check.insert({0,1});
    while(!check.empty()){
        ii curr=*check.begin();
        int distance=curr.first;
        int vertex=curr.second;
        check.erase(check.begin());
        if(visited[vertex])continue;
        visited[vertex]=1;
        for(auto child:graph[vertex]){
             if(dist[child.first]==child.second+dist[vertex]){
                num[child.first]+=num[vertex];
                num[child.first]=num[child.first]%mod;
                if(max[child.first]<1+max[vertex])max[child.first]=1+max[vertex];
                if(min[child.first]>1+min[vertex])min[child.first]=1+min[vertex];
                check.insert({dist[child.first],child.first});
            }
        }
    }
}
const int INF=1000000000000000;
void solve(int xyz)
{
  int n,k;cin>>n>>k;vector<vector<pair<int,int>>>graph(n+1);
  REP(i,0,k){
    int x,y,z;cin>>x>>y>>z;
    graph[x].pb({y,z});
  }
  vector<int>visited(n+1,0);
  vector<int>distance(n+1,INF);
    vector<int>num(n+1,0);
    vector<int>min(n+1,INF);
    vector<int>max(n+1,0);
    dijkstra2(graph,visited,max,min,num,distance);
    // REP(i,1,n+1){cout<<distance[i]<<" ";}
    // cout<<endl;
    // REP(i,1,n+1){distance[i]=INF;}
    REP(i,0,n+1){visited[i]=0;}
    dijkstra(graph,visited,max,min,num,distance);
    cout<<distance[n]<<" "<<num[n]%mod<<" "<<min[n]<<" "<<max[n]<<endl; return;
 
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
