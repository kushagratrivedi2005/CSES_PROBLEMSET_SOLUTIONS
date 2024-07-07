
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
    int n,m;cin>>n>>m;vector<vector<int>>remcapacity(n,vector<int>(n,0));
    vector<vector<int>>adj(n);
    vector<vector<int>>real(n);
    REP(i,0,m){
        int x,y,z;cin>>x>>y;x--;y--;
        adj[x].pb(y);
        adj[y].pb(x);
        real[x].pb(y);
        remcapacity[x][y]+=1;
        remcapacity[y][x]+=1;
    }
    int ans=0;
    vector<int>parent(n,-1);
    while(reachable(adj,0,remcapacity,n-1,parent)){
        int flow=INT_MAX;
        int node=n-1;
        while(node!=0){
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
        REP(i,0,n){parent[i]=-1;}
    cout<<ans<<endl;
    set<int>check;
      queue<int>q;
    q.push(0);
    check.insert(0);
    while(!q.empty()){
        int curr=q.front();q.pop();
        for(auto child:adj[curr]){
            int w=remcapacity[curr][child];
            if(w==0 || parent[child]!=-1)continue;
            parent[child]=curr;
            check.insert(child);
            q.push(child);
        }
    }
    REP(i,0,n){
        for(auto j:real[i]){
            if(check.find(i)!=check.end() && check.find(j)!=check.end()){continue;}
            if(check.find(i)==check.end() && check.find(j)==check.end()){continue;}
            cout<<i+1<<" "<<j+1<<endl;
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
