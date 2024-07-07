
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
int count1;
vector<int>visited(200005,0);
void dfs(int n,vector<vector<int>>&graph){
    visited[n]=1;
    count1++;
    for(auto i:graph[n]){
        if(!visited[i])dfs(i,graph);
    }
}
    int BIT[200005];
void update(int x){
    for(int i=x;i<200005;i+=(-i)&i){
        BIT[i]++;
    }
}
int query(int x){
    int ans=0;
    for(int i=x;i>0;i-=(-i)&i){
        ans+=BIT[i];
    }
    return ans;
}
 
void solve(int xyz)
{
int n;cin>>n;vector<vector<int>>graph(n+1);
vector<int>values(n);REP(i,0,n){cin>>values[i];graph[i+1].pb(values[i]);graph[values[i]].pb(i+1);}
int ans1=0;int ans2=0;int ans3=0;int ans4=0;
REP(i,0,n){
    update(values[i]);
    ans1+=values[i]-query(values[i]);
}
    const int INF = 1e9;
    vector<int> d(n+1, INF);d[0] = -INF;
    REP(i,0,n) {int l = upper_bound(d.begin(), d.end(), values[i]) - d.begin();if (d[l-1] < values[i] && values[i] < d[l])d[l] = values[i];}
    int ans = 0;
    REP(i,0,n+1) {if (d[i] < INF)ans=i;}
    ans3=n-ans;
    REP(i,1,n+1){
        count1=0;
        if(visited[i])continue;
        dfs(i,graph);
        ans2+=count1-1;
    }
    int curr=n;int nums=0;
    for(int i=n-1;i>=0;i--){
        if(values[i]==curr){curr--;nums++;}
    }
    ans4=n-nums;
    cout<<ans1<<" "<<ans2<<" "<<ans3<<" "<<ans4;
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
