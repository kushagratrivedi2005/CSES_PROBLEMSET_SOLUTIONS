
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
int dp[20][10][2][2];
int cnt(string &a,int n,int x,bool zeros,bool tight){
    if(n==0)return 1;
    if(dp[n][x][zeros][tight]!=-1){return dp[n][x][zeros][tight];}
    int low=0;
    int high= tight?a[a.length()-n]-'0':9;
    int answer=0;
    REP(i,low,high+1){
        if(zeros==0 && i==x)continue;
        answer+=cnt(a,n-1,i,zeros && i==0 ,tight && i==high);
    }
    return dp[n][x][zeros][tight]=answer;
}
 
void solve(int xyz)
{
    int a,b;cin>>a>>b;
    string A=to_string(a-1);
    string B=to_string(b);
    memset(dp,-1,sizeof(dp));
    int ans1=cnt(A,A.length(),-1,1,1);
    memset(dp,-1,sizeof(dp));
    int ans2=cnt(B,B.length(),-1,1,1);
    cout<<ans2-ans1;
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
