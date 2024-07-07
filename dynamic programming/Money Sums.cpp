
#include<bits/stdc++.h>
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
 
 
/*
code BY-
 █ ▄▀  █  █  █▀▀▀█  █  █  █▀▀█  █▀▀█  █▀▀█  █▀▀█ 　 
 █▀▄   █  █  ▀▀▀▄▄  █▀▀█  █▄▄█  █ ▄▄  █▄▄▀  █▄▄█ 　 
 █  █  ▀▄▄▀  █▄▄▄█  █  █  █  █  █▄▄█  █  █  █  █ 　 
 
▀▀█▀▀ █▀▀█ ▀█▀  █   █  █▀▀▀ █▀▀▄ ▀█▀ 
  █   █▄▄▀  █    █ █   █▀▀▀ █  █  █
  █   █  █ ▄█▄   ▀▄▀   █▄▄▄ █▄▄▀ ▄█▄ 
*/
 
signed main(){
    int n;cin>>n;
    vector<int>values(n);
    REP(i,0,n) cin>>values[i];
    int sum=0;
    REP(j,0,n) sum+=values[j];
    vector<int>reachable(sum+1,0);
    reachable[0]=1;
    for(int j=0; j<n; j++){
    for (int i = sum; i >=values[j]; i--)
    {
        reachable[i] =reachable[i] || reachable[i-values[j]];
    }}
    // REP(k,0,sum+1) cout<<reachable[k]<<" ";
    int sum1=0;
    REP(i,1,sum+1) sum1+=reachable[i];
    cout<<sum1<<endl;
    REP(i,1,sum+1) if(reachable[i]!=0) cout<<i<<" "; 
}
