
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
int mincut[505][505];
signed main(){
    int n,m; cin>>n>>m;
    REP(i,01,n+1) REP(j,1,m+1) mincut[i][j]=INT_MAX;
    REP(i,1,501) mincut[i][i]=0;
    REP(w,1,n+1){
        REP(h,1,m+1){
            REP(cut,1,w)
            mincut[w][h]=min(mincut[w][h],mincut[w-cut][h]+1+mincut[cut][h]);
            REP(cut,1,h)
               mincut[w][h]=min(mincut[w][h],mincut[w][h-cut]+1+mincut[w][cut]);
        }
    }
    cout<<mincut[n][m];
}
