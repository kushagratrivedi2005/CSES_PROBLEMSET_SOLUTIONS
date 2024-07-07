
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
 
 
void solve(int xyz) 
{
 int n,m;cin>>n>>m;vector<vector<int>>grid(n+1,vector<int>(m+2));
 REP(i,1,n+1){REP(j,1,m+1){char x;cin>>x;if(x=='.')grid[i][j]=1;else{grid[i][j]=0;}}grid[i][m+1]=0;}
 vector<vector<int>>prefix(n+2,vector<int>(m+2,0));
 stack<ii>st;
 vector<int>h(m+2);
 REP(i,1,n+1){
    int maxwidth=0;
    st.push({0,0});
    REP(j,1,m+2){
        if(grid[i][j]==0){h[j]=0;}else{h[j]+=grid[i][j];}
        maxwidth=j;while(!st.empty()){
            int height=st.top().first;
            int width=st.top().second;
            if(h[j]<height){
                prefix[height][j-width]++;st.pop();maxwidth=width;
                int h2=st.top().first;
                prefix[max(h[j],h2)][j-width]--;
            }else{break;}
        }st.push({h[j],maxwidth});
    }
 }
 for(int i=n;i>0;i--){for(int j=m;j>0;j--){prefix[i][j]+=prefix[i][j+1];}}
    for(int i=n;i>0;i--){for(int j=m;j>0;j--){
        prefix[i][j]+=prefix[i+1][j]+prefix[i][j+1]-prefix[i+1][j+1];
    }}
    REP(i,1,n+1){
        REP(j,1,m+1){
            cout<<prefix[i][j]<<" ";
        }cout<<endl;
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
