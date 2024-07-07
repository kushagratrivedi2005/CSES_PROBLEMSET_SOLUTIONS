
#include<bits/stdc++.h>
#define mod 1000000007 
#define ll long long
#define REP(i,m,n) for(int i=m;i<n;i++)
#define pb push_back
#define ff first
#define ss second
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>
using namespace std;
 
void dfs(int v, vector<vi>&tree, vi&dp,vi&visited){
    int ans=0;
    visited[v]=true;
    for(int x:tree[v]){
        if(!visited[x]){
            dfs(x,tree,dp,visited);
            ans+=1+dp[x];
        }
    }
    dp[v]=ans;
}
 
signed main(){
    int n;cin>>n;
    vector<int>dp(n+1,0);
    vector<int>visited(n+1,0);
    vector<vector<int>>tree(n+1);
    int subordinate=2;
    for (int i = 0; i < n-1; i++)
    {
        int k;cin>>k;
        tree[k].push_back(subordinate);
        subordinate++;
    }
    dfs(1,tree,dp,visited);
    for (int i = 1; i < n+1; i++)
    {
        cout<<dp[i]<<" ";
    }
    
}
