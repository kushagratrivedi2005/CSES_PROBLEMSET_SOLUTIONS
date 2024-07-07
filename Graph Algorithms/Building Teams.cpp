
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
int team[1000001]={0};
bool bipar=true;
bool bipart(int curr,int col){
    vis[curr]=true;
    team[curr]=col;
    for(int v: graph[curr]){
        if(vis[v]==false){
            bool res=(bipart(v,col^1));
            if(res==false) return false;
        }
        else
        if(team[v]==team[curr]) return false;
 
    }    
    return true;
}
 
 
signed main(){
    int m; cin>>n>>m;
    REP(i,0,m){
        int x,y; cin>>x>>y;
        graph[x].pb(y);
        graph[y].pb(x);
    }
    REP(i,1,n+1){
        if(!vis[i])
        bipar=bipart(i,0);
        if(bipar==false){
            cout<<"IMPOSSIBLE";
            return 0;
        };
        
    }
    REP(i,1,n+1) cout<<team[i]+1<<" ";
}
