
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
 
void solve(int xyz)
{
    int n,q,m;cin>>n>>q>>m;vector<vector<int>>remcapacity(n+q+2,vector<int>(n+q+2,0));
    vector<vector<int>>adj(n+q+2);
    vector<vector<int>>real(n+q+2,vector<int>(n+q+2,0));
    REP(i,0,m){
        int x,y;cin>>x>>y;
        adj[0].pb(x);
        remcapacity[0][x]=1;
        adj[n+q+1].pb(n+y);
        adj[n+y].pb(n+q+1);
        remcapacity[y+n][n+q+1]=1;
        adj[x].pb(n+y);
        adj[n+y].pb(x);
        remcapacity[x][n+y]=1;
    }
    int ans=0;
    vector<int>parent(n+q+2,-1);
    while(reachable(adj,0,remcapacity,n+q+1,parent)){
        int flow=INT_MAX;
        int node=n+q+1;
        while(node!=0){
            int x=node;int y=parent[node];
            if(x!=n+q+1 && y!=0){
                if(x>n){real[x][y]+=1;}
                else{real[y][x]-=1;}
            }
            flow=min(flow,remcapacity[parent[node]][node]);
            node=parent[node];
        }
        node=n+q+1;
        while(node!=0){
            remcapacity[node][parent[node]]+=flow;
            remcapacity[parent[node]][node]-=flow;
            node=parent[node];
        }
        ans+=flow;
        REP(i,0,n+q+2){parent[i]=-1;}
    }
    cout<<ans<<endl;
    REP(i,0,n+q+2){
        REP(j,0,n+q+2){
            if(real[i][j]==1){cout<<j<<" "<<i-n<<endl;}
        }
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
