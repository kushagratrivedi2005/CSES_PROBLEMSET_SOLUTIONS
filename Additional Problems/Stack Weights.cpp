
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
const int maxn=2e5;
int maxi[4*maxn];   
int mini[4*maxn];
int lazy[4*maxn];
void push(int index){
    lazy[2*index+1]+=lazy[index];
    lazy[2*index+2]+=lazy[index];
    maxi[2*index+1]+=lazy[index];
    maxi[2*index+2]+=lazy[index];
    mini[2*index+1]+=lazy[index];
    mini[2*index+2]+=lazy[index];
    lazy[index]=0;
}
void update(int index,int low,int high,int l,int r,int val){
    if(l>high || r<low)return;
    if(l<=low && high<=r){
        maxi[index]+=val;
        mini[index]+=val;
        lazy[index]+=val;
        return;
    }
    push(index);
    int mid=(low+high)/2;
    update(2*index+1,low,mid,l,r,val);
    update(2*index+2,mid+1,high,l,r,val);
    maxi[index]=max(maxi[2*index+1],maxi[2*index+2]);
    mini[index]=min(mini[2*index+1],mini[2*index+2]);
    return;
}
 
void solve(int xyz)
{
    int n;cin>>n;
    REP(i,0,n){
        int x,y;cin>>x>>y;
        if(y==1){update(0,0,n-1,0,x-1,1);}
        else{update(0,0,n-1,0,x-1,-1);}
        if(maxi[0]>=0 && mini[0]>=0){cout<<'>'<<endl;}
        else if(maxi[0]<=0 && mini[0]<=0){cout<<'<'<<endl;}
        else{cout<<'?'<<endl;}
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
