
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
 
 
int vis[300000][3];
int lev[300000][3];
vector<int>graphs[300000];
void dfs(int source,int n){
    vis[source][n]=1;
    // cout<<lev[source][n]<<endl;
    for(int child : graphs[source]){
        if(vis[child][n]) continue;
        lev[child][n]=lev[source][n]+1;
        dfs(child,n);
    }
}
 
signed main(){
    int n; cin>>n;
    REP(i,1,n){
        int x,y; cin>>x>>y;
        graphs[x].pb(y);
        graphs[y].pb(x);
    }
    dfs(1,0);
    int max_dist=0;
    int max_node=0;
    REP(i,1,n+1){
        if(lev[i][0]>max_dist){
        max_dist=lev[i][0];
        max_node=i;}
    }
    dfs(max_node,1);
    max_dist=0;
    max_node=0;
    REP(i,1,n+1){
        if(lev[i][1]>max_dist){
        max_dist=lev[i][1];
        max_node=i;}
    }
    dfs(max_node,2);
    REP(i,1,n+1){
        if(lev[i][1]>lev[i][2])
        cout<<lev[i][1]<<" ";
        else
        cout<<lev[i][2]<<" ";
    }
}
