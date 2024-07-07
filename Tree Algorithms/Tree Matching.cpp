
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
#define ll long long
int dp[200001][2];
void sol(int src,int par,vector<vector<int>>&graph){
    dp[src][0]=0;dp[src][1]=0;
    int leaf=0;
    for(auto it:graph[src]){
        if(it==par)continue;
        leaf=1;
        sol(it,src,graph);
    }
    if(!leaf)return;
    vector<int>prefix;vector<int>suffix;
    for(auto child:graph[src]){
        if(child==par)continue;
        prefix.pb(max(dp[child][0],dp[child][1]));
        suffix.pb(max(dp[child][0],dp[child][1]));
    }
    REP(i,0,prefix.size()-1){prefix[i+1]+=prefix[i];}
    for(int j=suffix.size()-2;j>=0;j--){
        suffix[j]+=suffix[j+1];
    }
    dp[src][0]=suffix[0];
    // if(src==3){cout<<dp[src][0]<<" "<<dp[src][1]<<endl;}
    int no=0;
    for(int child:graph[src]){
        int sum=1;
        if(child==par)continue;
        if(no!=0){sum+=prefix[no-1];}
    
        if(no!=suffix.size()-1){sum+=suffix[no+1];}
        dp[src][1]=max(dp[src][1],sum+dp[child][0]);
        no++;
    }
 
    
 
}
void solve(int xyz)
{
    int n;cin>>n;vector<vector<int>>graph(n+1);
    REP(i,0,n-1){
        int x,y;cin>>x>>y;
        graph[x].pb(y);
        graph[y].pb(x);
    }
    sol(1,-1,graph);
    cout<<max(dp[1][0],dp[1][1]);
   
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
