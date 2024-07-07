
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
 
int subtreeans[300000];
int subtreesize[300000];
int ans[300000];
vector<int> graphs[300000];
 
void dfs(int source,int par){
    int numofnodes=1;
    int ansoftree=0;
    for(int child: graphs[source]){
        if(child!=par){
            dfs(child,source);
            ansoftree+=subtreeans[child]+subtreesize[child];
            numofnodes+=subtreesize[child];
        }
    }
    subtreesize[source]=numofnodes;
    subtreeans[source]=ansoftree;
}
 
void ansfill(int source,int par, int par_ans, int noofnodes){
    ans[source]=subtreeans[source]+(par_ans+noofnodes-subtreesize[source]);
    for(auto child: graphs[source]){
        if(child!=par){
            ansfill(child,source,ans[source]-(subtreesize[child]+subtreeans[child]),noofnodes);
        }
    }
}
 
signed main(){
    int n;cin>>n;
    REP(i,1,n){
        int x,y; cin>>x>>y;
        graphs[x].pb(y);
        graphs[y].pb(x);
    }
    dfs(1,0);
    ansfill(1,0,0,n);
    REP(i,1,n+1) cout<<ans[i]<<" ";
}
