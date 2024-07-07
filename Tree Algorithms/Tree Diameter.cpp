
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
int n; 
int depth[200006]={0};
vector<int>v[200006];
void dfs(int vertex,int par=0){
	for(int child:v[vertex]){
		if(child==par) continue;
		depth[child]=depth[vertex]+1;
		dfs(child,vertex);
	}
}
 
signed main(){
	cin>>n;
    if(n==1){
    cout<<0;
    return 0;}
	REP(i,0,n){
		int x,y; cin>>x>>y;
		v[x].pb(y);
		v[y].pb(x);
	}
	dfs(1);
	int max_node=0;
	int max_value=-1;
	REP(i,1,n+1){
		if(depth[i]>max_value){
			max_node=i;
			max_value=depth[i];
		}
        depth[i]=0;
	}
	dfs(max_node);
	REP(i,1,n+1){
		if(depth[i]>max_value){
			max_value=depth[i];
		}
	}
	cout<<max_value;
}
