
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
bool dfs(vector<vector<int>>&graph,vector<int>&visited,int n,vector<int>&path,int&add,int &start,int parent){
    visited[n]=1;
    for(int i:graph[n]){
        if(visited[i] && i!=n && i!=parent ){
            path.pb(i);
            path.pb(n);
            start=i;
            add=1;
            return true;
        }
        else if(!visited[i]){
        if(dfs(graph,visited,i,path,add,start,n)==true){
            if(add==1){path.pb(n);}
            if(n==start){add=0;}
            return true;
        }}
    }
    return false;
}
 
void solve(int xyz)
{
  int n,m;cin>>n>>m;vector<vector<int>>graph(n+1);
  REP(i,0,m){
    int x,y;cin>>x>>y;
    graph[x].pb(y);
    graph[y].pb(x);
  }
  vector<int>visited(n+1,0);
  vector<int>path;
  int add=1;
  int start=-100;
    for(int i=1;i<n+1;i++){
        if(!visited[i]){
            if(dfs(graph,visited,i,path,add,start,0)==true){
                cout<<path.size()<<endl;
    reverse(path.begin(),path.end());
    for(int i=0;i<path.size();i++){
        cout<<path[i]<<" ";
    }return;
            }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
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
