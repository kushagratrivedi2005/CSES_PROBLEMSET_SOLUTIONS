
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
    int n;cin>>n;
    string s;cin>>s;
    if(n==2){
        int a=0;int b=0;REP(i,0,2*n){if(s[i]=='A')a=i;if(s[i]=='B')b=i;}
        if(a>b){cout<<-1<<endl;return;}
        else{cout<<0<<endl;return;}
    }
    int blank=0;REP(i,0,2*n){if(s[i]=='.')blank=i;}
    vector<string>ans;
    if(blank==2*n-2){swap(s[0],s[2*n-3]);swap(s[1],s[2*n-2]);ans.pb(s);swap(s[0],s[2*n-2]);swap(s[1],s[2*n-1]);ans.pb(s);
    }
    else if(blank<2*n-2){
        swap(s[blank],s[2*n-1]);swap(s[blank-1],s[2*n-2]);ans.pb(s);
    }
    while(1){
        int a=0;int b=0;
        REP(i,0,2*n){if(s[i]=='B'){b=i;break;}}
        REP(i,b+2,2*n){if(s[i]=='A'){a=i;break;}}
        if(a==2*n-3){
            if(s[b+1]!='A'){
            swap(s[n-2],s[2*n-2]);swap(s[n-1],s[2*n-1]);ans.pb(s);
            swap(s[2*n-3],s[b]);swap(s[2*n-2],s[b+1]);ans.pb(s);break;}
            swap(s[b],s[2*n-2]);swap(s[b+1],s[2*n-1]);ans.pb(s);
            swap(s[2*n-3],s[b]);swap(s[2*n-2],s[b+1]);ans.pb(s);
            swap(s[b+1],s[2*n-3]);swap(s[b+2],s[2*n-2]);ans.pb(s);
            swap(s[b+1],s[2*n-2]);swap(s[b+2],s[2*n-1]);ans.pb(s);
            swap(s[2*n-4],s[2*n-2]);swap(s[2*n-3],s[2*n-1]);ans.pb(s);
            swap(s[b+1],s[2*n-4]);swap(s[b+2],s[2*n-3]);ans.pb(s);
            swap(s[b+1],s[2*n-3]);swap(s[b+2],s[2*n-2]);ans.pb(s);
            int a=0;int b=0;
            REP(i,0,2*n){if(s[i]=='B'){b=i;break;}}
            REP(i,b+1,2*n){if(s[i]=='A'){a=i;break;}}
            if(a==0){break;}else{cout<<-1<<endl;return;}
        }
        else if(a==0){
            REP(i,b+1,2*n){if(s[i]=='A'){a=i;break;}}
            if(a==0)break;
            else{
                swap(s[2*n-1],s[2*n-3]);swap(s[2*n-2],s[2*n-4]);ans.pb(s);
                swap(s[a-1],s[2*n-4]);swap(s[a],s[2*n-3]);ans.pb(s);
                swap(s[2*n-3],s[a-1]);swap(s[2*n-2],s[a]);ans.pb(s);
            }
            int a=0;int b=0;
            REP(i,0,2*n){if(s[i]=='B'){b=i;break;}}
            REP(i,b+1,2*n){if(s[i]=='A'){a=i;break;}}
            if(a==0){break;}else{cout<<-1<<endl;return;}
        }
        else{
            swap(s[a],s[2*n-2]);swap(s[a+1],s[2*n-1]);ans.pb(s);
            swap(s[b],s[a]);swap(s[b+1],s[a+1]);ans.pb(s);
            swap(s[b],s[2*n-2]);swap(s[b+1],s[2*n-1]);ans.pb(s);
        }
    }
    cout<<ans.size()<<endl;
    for(auto x:ans){cout<<x<<endl;}
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
