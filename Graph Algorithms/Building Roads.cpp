
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
int parent[1000000];
int siz[1000000];
void make(int n){
	parent[n]=n;
}
int find(int n){
	if(parent[n]==n)
	return n;
	else return parent[n]=find(parent[n]);
}
void Union(int a, int b){
	a=find(a);
	b=find(b);
	if(a!=b){
	if(siz[a]<siz[b])
	swap(a,b);
	parent[b]=a;
	siz[a]+=siz[b];}
}
 
signed main(){
	int n,k; cin>>n>>k;
	REP(i,1,n+1) make(i);
	vii roads;
	REP(i,0,k){
		int x,y; cin>>x>>y;
		roads.pb({x,y});
		if(find(x)==find(y)) continue;
		Union (x,y);
	}
	vii new_roads;
	int num_roads=0;
	for(int i=1;i<n;i++){
		{
			if(find(i)==find(i+1)) continue;
			new_roads.pb({i,i+1});
			num_roads++;
			Union(i,i+1);
		}
		
	}
	cout<<num_roads<<endl;
	vii :: iterator it;
	for(it=new_roads.begin(); it!= new_roads.end(); it++){
		cout<<(*(it)).first<<" "<<(*(it)).second<<endl;
	}
}
 
