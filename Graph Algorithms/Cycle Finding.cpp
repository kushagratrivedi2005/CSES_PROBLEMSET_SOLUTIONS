
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
const int INF=100000000000000;
void solve(int xyz){
    int n,m;cin>>n>>m;vector<vector<pair<int,int>>>graph(n+1);
    vector<int>parent(n+1,0); 
    REP(i,0,m){
        int x,y,z;cin>>x>>y>>z;
        graph[x].pb({y,z});
    }
    vector<int>dist(n+1,INF);
    dist[1]=0;
    REP(i,0,n-1){
    REP(j,1,n+1){
        for(auto ed:graph[j]){
            if(dist[j]+ed.second<dist[ed.first]){
                dist[ed.first]=ed.second+dist[j];
                // parent[ed.first]=j;
            }
        }
    }
    // REP(i,1,n+1){cout<<dist[i]<<" ";}cout<<endl;
    }
    int start;
    int flag=0;
    REP(i,0,2){
    REP(j,1,n+1){
        for(auto ed:graph[j]){
            if(dist[j]+ed.second<dist[ed.first]){
                dist[ed.first]=dist[j]+ed.second;
                start=ed.first;flag=1;
                parent[ed.first]=j;
            }
        }
    }}
    if(flag)
    cout<<"YES"<<endl;
    else{cout<<"NO"<<endl; return;}
    // REP(i,1,n+1){cout<<parent[i]<<" ";}
    REP(i,0,n){start=parent[start];}
    vector<int>ans;
    for(int curr=start;(curr!=start)||(ans.size()==0);curr=parent[curr]){
        ans.push_back(curr);
    }
    // cout<<start<<endl;
    // cout<<'*'<<endl;
    ans.push_back(start);
    reverse(ans.begin(),ans.end());
    REP(i,0,ans.size()){
        cout<<ans[i]<<" ";
    }
    cout<<endl;return;
 
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
