
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
 
 
 
 
// const int n=2e5+5;
// int power(int a,int b){
//     if(b==0)return 1;
//     if(a==0)return 0;
//     if(a==1)return 1;
//     int ans=1;
//     a=a%mod;
//     while(b>0){
//         if(b&1){
//             ans=ans*a%mod;
//         }
//         b>>=1;
//         a=(a*a)%mod;
//     }
//     return ans;
// }
// int fact[n]; int inv[n];
// void once(){
//     fact[0]=1;
//     REP(i,1,n){
//         fact[i]=fact[i-1]*i%mod;
//     }
//     inv[0]=1;
//     REP(i,1,n){
//         inv[i]=power(fact[i],mod-2)%mod;
//     }
// }
// int ncr(int n,int r){
//     int ans=fact[n]%mod;
//     ans*=inv[r]%mod;
//     ans%=mod;
//     ans*=inv[n-r]%mod;
//     ans%=mod;
//     return ans;
// }
// int addmod(int x,int y){
//     return (x+y)%mod;
// }
 
// int multmod(int x,int y){
//     return (x*y)%mod;
// }
/*
code BY-
 █ ▄▀  █  █  █▀▀▀█  █  █  █▀▀█  █▀▀█  █▀▀█  █▀▀█ 　 
 █▀▄   █  █  ▀▀▀▄▄  █▀▀█  █▄▄█  █ ▄▄  █▄▄▀  █▄▄█ 　 
 █  █  ▀▄▄▀  █▄▄▄█  █  █  █  █  █▄▄█  █  █  █  █ 　 
 
▀▀█▀▀ █▀▀█ ▀█▀  █   █  █▀▀▀ █▀▀▄ ▀█▀ 
  █   █▄▄▀  █    █ █   █▀▀▀ █  █  █
  █   █  █ ▄█▄   ▀▄▀   █▄▄▄ █▄▄▀ ▄█▄ 
*/
int size1[100001];int parent[100001];
void make(int i){
    parent[i]=i;size1[i]=1;
}
int find(int i){
    if(i==parent[i])return i;
    return parent[i]=find(parent[i]);
}
void Union(int x,int y){
    x=find(x); y=find(y);
    if(x==y)return;
    if(size1[x]<size1[y]){swap(x,y);}
    parent[y]=x;
    size1[x]+=size1[y];
}
int dfs(vector<int>&visited,vector<vector<int>>&graph,int n){
    visited[n]=1;
    int cycle=0;
    for(int i:graph[n]){
        if(visited[i]==1)return 1;
        cycle +=dfs(visited,graph,i);
    }
    visited[n]=2;
    return cycle;
}
void solve(int xyz)
{
   int n,m;cin>>n>>m;vector<vector<int>>graph(n);
   REP(i,0,n){make(i);}
   REP(i,0,m){
    int a,b;cin>>a>>b;a--;b--;graph[a].pb(b);Union(a,b);
   }
   int K=1;
   map<int,int>id;
   vector<vector<int>>connectedcomps(n);
   REP(i,0,n){
    int x=find(i);
    if(!id[x]){
        id[x]=K++;
    }
    connectedcomps[id[x]].pb(i);
   }
   K--;
   int ans=0;
   vector<int>visited(n,0);
    REP(i,1,K+1){
        int cycle=0;
        int sz=connectedcomps[i].size();
        for(int j:connectedcomps[i]){
            if(!visited[j]){
                cycle+=dfs(visited,graph,j);
            }
        }
            ans+=cycle?sz:sz-1;
    }
    cout<<ans<<endl;
 
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
