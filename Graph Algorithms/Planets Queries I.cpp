
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
 
void solve(int xyz)
{
  int n,k;cin>>n>>k; vector<int>values(n); REP(i,0,n)cin>>values[i];
  vector<vector<int>>table(30,vector<int>(n+1));
  REP(i,1,n+1){table[0][i]=values[i-1];}
    REP(i,1,30){
        REP(j,1,n+1){
            table[i][j]=table[i-1][table[i-1][j]];
        }
    }
    // cout<<"*"<<endl;
    // REP(i,0,4){
    //     REP(j,1,n+1){cout<<table[j][i]<<" ";}
    //     cout<<endl;
    // }
    while(k--){
        int x,y;cin>>x>>y;
        int ans=x;
        int curr=0;
        while(y!=0){
            if(y&1==1){ans=table[curr][ans];}
            curr++;
            y/=2;
        }
        cout<<ans<<"\n";
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
