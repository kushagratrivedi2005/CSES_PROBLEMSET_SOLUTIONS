
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
const int maxi=2e5+2;
int n,q;vector<int>values(maxi);int prefixsums[maxi][30];
array<int,30> seg[2*maxi];
array<int,30>Union(array<int,30>&a,array<int,30>&b){
    array<int,30>ans;
    REP(i,0,30)ans[i]=min(a[i],b[i]);
    return ans;
}
// void print(array<int,30>&a){
//     REP(i,0,30){cout<<i<<" "<<a[i]<<endl;}
// }
array<int,30>query(int l,int r){
    array<int,30> ans;REP(i,0,30){ans[i]=1e9;}
    l+=maxi;r+=maxi+1;
    for (; l < r; r/=2, l/=2){
        if(l&1)ans=Union(ans,seg[l++]);
        if(r&1)ans=Union(seg[--r],ans);
    }
    return ans;
}
void solve(int xyz)
{
cin >> n >> q; memset(seg, 0x3f, sizeof(seg));
REP(i,1,n+1){int x;cin>>x;int ln=log2(x);seg[i+maxi][ln]=x;prefixsums[i][ln]=x;}
REP(j,0,30){REP(i,1,n+1){prefixsums[i][j]+=prefixsums[i-1][j];}}
for(int i=maxi-1;i>=0;i--){seg[i]=Union(seg[2*i],seg[2*i+1]);}
while(q--){
    int l,r;cin>>l>>r;array<int,30>check=query(l,r);int sum=0;
    // print(check);
    REP(i,0,30){
        if(sum+1<(1<<(i+1)) && check[i]>sum+1){
            break;
        }
        sum+=prefixsums[r][i]-prefixsums[l-1][i];
    }
    cout<<sum+1<<endl;
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
