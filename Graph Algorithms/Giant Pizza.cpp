
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
    for(auto i:graph[n]){
        if(!visited[i]){dfs(graph,visited,i,st);}
    }
    st.push(n);
}
void dfs2(vector<vector<int>>&graph,vector<int>&components,int n,int counter){
    components[n]=counter;
    for(auto i:graph[n]){
        if(components[i]==-1){dfs2(graph,components,i,counter);}
    }
}
void solve(int xyz){
   int n,m;cin>>n>>m;
   vector<vector<int>>graph(2*m+1);
    REP(i,0,n){
        char x,y;int x1,y1;
        cin>>x>>x1>>y>>y1;
        // cout<<x<<" "<<x1<<" "<<y<<" "<<y1<<endl; 
        if(x=='+'){if(y=='+')graph[x1+m].pb(y1);else{graph[x1+m].pb(y1+m);}}
        if(y=='+'){if(x=='+')graph[y1+m].pb(x1);else{graph[y1+m].pb(x1+m);}}
        if(x=='-'){if(y=='+')graph[x1].pb(y1);else{graph[x1].pb(y1+m);}}
        if(y=='-'){if(x=='+')graph[y1].pb(x1);else{graph[y1].pb(x1+m);}}
    }
    vector<vector<int>>reverse(2*m+1);
    REP(i,1,2*m+1){
        REP(j,0,graph[i].size()){reverse[graph[i][j]].pb(i);}
    }
    vector<int>visited(2*m+1,0);
    stack<int>st;
    REP(i,1,2*m+1){
        if(!visited[i]){dfs(graph,visited,i,st);}
    }
    int counter=0;
    vector<int>components(2*m+1,-1);
    while(!st.empty()){
        int x=st.top();
        // cout<<st.top();
        st.pop();
        if(components[x]==-1){
            dfs2(reverse,components,x,counter);
            counter++;
            // cout<<x<<" "<<counter<<endl;
        }
    }
    // cout<<counter<<endl;
    vector<char>ans(m+1);
    REP(i,1,m+1){
        if(components[i]==components[m+i]){cout<<"IMPOSSIBLE"<<endl; return;}
        else if(components[i]>components[m+i]){
            ans[i]='+';
        }
        else{ans[i]='-';}
    }
    REP(i,1,m+1){
        cout<<ans[i]<<" ";
    }
    cout<<endl;return;
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
