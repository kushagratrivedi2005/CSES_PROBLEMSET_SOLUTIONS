
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
void dfs(vector<int>&values,int i,vector<int>&visited,queue<int>&path,int&counter,vector<int>&dist){
    path.push(i); 
    counter++;
    visited[i]=1;
    if(visited[values[i]]){
        counter+=dist[values[i]];
        path.push(values[i]);
        return;
    }
    dfs(values,values[i],visited,path,counter,dist);
}
 
void solve(int xyz)
{
    int n;cin>>n;vector<int>values(n+1);REP(i,1,n+1)cin>>values[i];
    vector<int>visited(n+1,0);
    queue<int>path;
    int counter=0;
    vector<int>dist(n+1,0);
    int minus=1;
    REP(i,1,n+1){
        if(!visited[i]){
            counter=0;
            minus=1;
            dfs(values,i,visited,path,counter,dist);
            // cout<<path.size()<<endl;
            while(!path.empty()){
                if(path.front()==path.back()){
                    minus=0;
                }
                dist[path.front()]=counter;
                counter-=minus;
                path.pop();
            }
        }
    }
    REP(i,1,n+1){cout<<dist[i]<<" ";}
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
