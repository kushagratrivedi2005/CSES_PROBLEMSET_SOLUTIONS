
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
int dp[5000][5000];
int solve(string &a,string &b,int i,int j){
    if(i==a.length())
    return b.length()-j;
    if(j==b.length())
    return a.length()-i;
    int ans=0;
    if(dp[i][j]!=0){
    return dp[i][j];}
    if(a[i]==b[j])
    return solve(a,b,i+1,j+1);
    else{
        int insertans=solve(a,b,i,j+1)+1;
        int deleteans=solve(a,b,i+1,j)+1;
        int replaceans=solve(a,b,i+1,j+1)+1;
        ans=min(insertans,min(replaceans,deleteans));
        return dp[i][j]=ans;
    }
}
 
signed main(){
    string a,b; cin>>a>>b;
    cout<<solve(a,b,0,0);
}
