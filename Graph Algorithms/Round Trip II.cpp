
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
void dfs(vector<vector<int>>&graph,vector<int>&temp,vector<int>&visited,stack<int>&st,int n,int &check,int &start,int &push){
    visited[n]=1;
    temp[n]=1;
    for(auto i:graph[n]){
        if(temp[i]==1){st.push(i);check=1;start=i;st.push(n);return;}
        if(!visited[i]){
            dfs(graph,temp,visited,st,i,check,start,push);
        }
        if(push==1){return;}
        if(check==1){st.push(n);if(start==n)push=1;return;}
    }
    temp[n]=0;
}
 
void solve(int xyz)
{
  int n,k;cin>>n>>k;
  vector<vector<int>>graph(n+1);
  REP(i,0,k){
    int x,y;cin>>x>>y;
    graph[x].pb(y);
  }
// REP(i,1,n+1){cout<<graph[i].size()<<" ";}
  vector<int>visited(n+1,0);
    vector<int>temp(n+1,0);
    stack<int>st;
    int check=0;
    int start=-1;
    int push=0;
    for(int i=1;i<n+1;i++){
        if(!visited[i]){
            dfs(graph,temp,visited,st,i,check,start,push);
        }
        if(check==1){
            cout<<st.size()<<endl;
            while(!st.empty()){
                cout<<st.top()<<" ";
                st.pop();
            }
            return;
        }
    }
    cout<<"IMPOSSIBLE"<<endl; return;   
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
