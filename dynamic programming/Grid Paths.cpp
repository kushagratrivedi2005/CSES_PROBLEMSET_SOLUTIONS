
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
char grid[1000][1000];
int dp[1000][1000];
 
bool ispossible(int i,int j,int n,const char grid[][1000]){
    if(grid[i][j]=='*')
    return false;
    else if(i>n-1 or i<0)
    return false;
    else if(j>n-1 or j<0)
    return false;
    else
    return true;
}
 
int moves(int x,int y,int n,const char grid[][1000], int dp[][1000]){
    if(x==n-1 and y==n-1){
    return 1;
    }
    if(dp[x][y]!=-1){
        return dp[x][y]%mod;
    }
    int paths=0;
    if(ispossible(x+1,y,n,grid))
    paths+=moves(x+1,y,n,grid,dp)%mod;
    if (ispossible(x,y+1,n,grid))
    paths+=moves(x,y+1,n,grid,dp)%mod;
    dp[x][y]=paths%mod;
    return paths%mod;
}
 
signed main(){
    int n;cin>>n;
    REP(i,0,n){
        REP(j,0,n){
            char x;cin>>grid[i][j];
            dp[i][j]=-1;
        }
    }
    if(grid[0][0]=='*'){
    cout<<0;
    return 0;}
    int mov=moves(0,0,n,grid,dp);
    cout<<mov%mod;
    return 0;
}
