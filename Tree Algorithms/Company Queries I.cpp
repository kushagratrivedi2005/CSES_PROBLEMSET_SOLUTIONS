
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
void preprocess(int node,int par,vector<vector<int>>&parent,vector<vector<int>>&tree){
    for(int i=1;i<20;i++){
        if(parent[node][i-1]!=-1){
            parent[node][i]=parent[parent[node][i-1]][i-1];
        }
        else{parent[node][i]=-1;}
    }
    for(auto ch:tree[node]){
        preprocess(ch,node,parent,tree);
    }
}
 
int query(int node,int num,vector<vector<int>>&parent){
    if(node==-1)return -1;
    if(num==0)return node;
    for(int i=0;i<20;i++){
            if(num&(1<<i)){
                return query(parent[node][i],num-(1<<i),parent);
            }
        }
}
void solve(int xyz)
{
    int n,x;cin>>n>>x;
    vector<vector<int>>graph(n+1);
    vector<vector<int>>parent(n+1,vector<int>(20));
    parent[1][0]=-1;
    REP(i,2,n+1){
        int x;cin>>x;
        graph[x].pb(i);
        parent[i][0]=x;
    }
    preprocess(1,-1,parent,graph);
    while(x--){
        int node,num;cin>>node>>num;
        cout<<query(node,num,parent)<<endl;
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
