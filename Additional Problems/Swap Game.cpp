
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
int power[10];
int swaper(int state,int pos1,int pos2){
    return state-(state%power[pos1+1]/power[pos1])*(power[pos1]-power[pos2])+(state%power[pos2+1]/power[pos2])*(power[pos1]-power[pos2]);
}
void solve(int xyz)
{
 
   vector<bool>visited(power[9],0);
   int final=0;
   REP(i,0,9){final+=(i)*power[8-i];}
   int num=0;
   REP(i,0,9){int x;cin>>x;x--;num+=x*power[8-i];}
   queue<ii>q;
   q.push({num,0});
   while(!q.empty()){
    ii x=q.front();q.pop();
    if(x.first==final){cout<<x.second;return;}
    REP(i,0,9){
        if(i%3==2){continue;}
        int swapped=swaper(x.first,i,i+1);
        if(!visited[swapped]){
            visited[swapped]=1;q.push({swapped,x.second+1});
        }
    }
    REP(i,3,9){
        int swapped=swaper(x.first,i,i-3);
        if(!visited[swapped]){
            visited[swapped]=1;q.push({swapped,x.second+1});
        }
    }
   }
}
 
signed main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif
  
ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//   int t;cin>>t;
power[0]=1;
REP(i,1,10){power[i]=9*power[i-1];}
  REP(xyz,0,1){
    solve(xyz);
  }
}
