
#include<bits/stdc++.h>
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
 
 
/*
code BY-
 █ ▄▀  █  █  █▀▀▀█  █  █  █▀▀█  █▀▀█  █▀▀█  █▀▀█ 　 
 █▀▄   █  █  ▀▀▀▄▄  █▀▀█  █▄▄█  █ ▄▄  █▄▄▀  █▄▄█ 　 
 █  █  ▀▄▄▀  █▄▄▄█  █  █  █  █  █▄▄█  █  █  █  █ 　 
 
▀▀█▀▀ █▀▀█ ▀█▀  █   █  █▀▀▀ █▀▀▄ ▀█▀ 
  █   █▄▄▀  █    █ █   █▀▀▀ █  █  █
  █   █  █ ▄█▄   ▀▄▀   █▄▄▄ █▄▄▀ ▄█▄ 
*/
vector<int>graph[1000001];
int n;
bool vis[1000001];
int dist[1000001];
int par[1000001];
bool bfs(int source){
    queue<int>q;
    vis[source]=1;
    dist[source]=0;
    q.push(source);
    while(q.size()>0){
        int curr_ele=q.front();
        if(curr_ele==n) return true;
        q.pop();
        for(int child: graph[curr_ele]){
            if(vis[child]) continue;
            par[child]=curr_ele;
            dist[child]=dist[curr_ele]+1;
            vis[child]=1;
            q.push(child);
        }
    }
    return false;
}
 
signed main(){
    int m; cin>>n>>m;
    REP(i,0,m){
        int x,y; cin>>x>>y;
        graph[x].pb(y);
        graph[y].pb(x);
    }
    if(bfs(1)){
        cout<<dist[n]+1<<endl;
        vector<int>path;
        int node=n;
        path.pb(n);
        while(node!=1){
            node=par[node];
            path.pb(node);
        }
        reverse(path.begin(),path.end());
        REP(i,0,path.size()) cout<<path[i]<<" ";
    }
    else
    cout<<"IMPOSSIBLE";
}
