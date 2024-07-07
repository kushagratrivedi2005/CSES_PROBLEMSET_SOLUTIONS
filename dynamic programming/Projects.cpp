
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
 int dp[200001];
 int fill(vector<int>&search,vector<array<int,3>>&array,int n){
  if(n<0)return 0;
  if(dp[n]!=-1){return dp[n];}
  int index=lower_bound(search.begin(),search.end(),array[n][1])-search.begin()-1;
  // cout<<n<<" "<<index<<endl;
  return dp[n]=max(fill(search,array,n-1),array[n][2]+fill(search,array,index));
 }
 
void solve(int xyz)
{
 int n;cin>>n;vector<array<int,3>>values(n+1);
 REP(i,1,n+1){cin>>values[i][1]>>values[i][0]>>values[i][2];}
 vector<int>search(n+1);
 sort(values.begin(),values.end());
 REP(i,1,n+1){search[i]=values[i][0];}
 memset(dp,-1,sizeof(dp));
 dp[0]=0;
cout<<fill(search,values,n);
return;
 
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
