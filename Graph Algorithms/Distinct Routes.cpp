
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
bool reachable(vector<vector<int>>&adj,int source,vector<vector<int>>&remcapacity,int sink,vector<int>&parent){
    queue<int>q;
    q.push(source);
    while(!q.empty()){
        int curr=q.front();q.pop();
        for(auto child:adj[curr]){
            int w=remcapacity[curr][child];
            if(w==0 || parent[child]!=-1)continue;
            parent[child]=curr;
            if(child==sink)return true;
            q.push(child);
        }
    }
    return false;
}
void dfs(vector<vector<int>>& graph, int n, vector<vector<int>>& visited, int end, vector<int>& path,int start,int &state) {
    path.pb(n);
    // cout<<n<<" "<<state<<endl;
    for(auto child:graph[n]){
        // cout<<n<<" "<<child<<endl;
        if(n==start)state=0;
        if(state==1)return;
        if(visited[n][child])continue;
        visited[n][child]=1;
        dfs(graph,child,visited,end,path,start,state);
        if(child==end-1){
            state=1;
            cout<<path.size()<<endl;
            REP(i,0,path.size()){cout<<path[i]+1<<" ";}
            cout<<endl;
            path.clear();
            path.pb(0);
        }
    }
}
void solve(int xyz)
{
    int n,m;cin>>n>>m;vector<vector<int>>remcapacity(n,vector<int>(n,0));
    vector<vector<int>>adj(n);
    vector<vector<int>>inpath(n,vector<int>(n,0));
    set<pair<int,int>>check;
    REP(i,0,m){
        int x,y;cin>>x>>y;x--;y--;
        adj[x].pb(y);
        adj[y].pb(x);
        check.insert({x,y});
        remcapacity[x][y]=1;
    }
    int ans=0;
    vector<int>parent(n,-1);
    while(reachable(adj,0,remcapacity,n-1,parent)){
        int flow=INT_MAX;
        int node=n-1;
        while(node!=0){
            int y=node;int x=parent[node];
            // cout<<x+1<<" "<<y+1<<endl;
            if(check.find({x,y})!=check.end()){
                inpath[x][y]++;
            }
            else{inpath[y][x]--;}
            flow=min(flow,remcapacity[parent[node]][node]);
            node=parent[node];
        }
        node=n-1;
        while(node!=0){
            
            remcapacity[node][parent[node]]+=flow;
            remcapacity[parent[node]][node]-=flow;
            node=parent[node];
        }
        
        ans+=flow;
        REP(i,0,n){parent[i]=-1;}
    }
    cout<<ans<<endl;
    vector<vector<int>>graph(n);
    REP(i,0,n){
        REP(j,0,n){
            if(inpath[i][j]==1){
                graph[i].pb(j);
            }
        }
    }
    vector<vector<int>>visited1(n+1,vector<int>(n+1,0));
    vector<int>path;
    int state=0;
    dfs(graph,0,visited1,n,path,0,state);
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
