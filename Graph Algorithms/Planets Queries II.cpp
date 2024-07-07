
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define mod 1000000007 
// #define int long long
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
 
 
 
  int jump( int pos,  int dist,  int maxjump, vector<vector< int>> &ancestors) {
    for ( int i = 0; i <= maxjump; i++) {
        if ((dist & (1 << i)) != 0) {
            pos = ancestors[pos][i];
        }
    }
    return pos;
}
void solve(int xyz)
{
  int n,q;cin>>n>>q;vector<int>next(n);vector<vector<int>>one_back(n);
  REP(i,0,n){
    cin>>next[i];next[i]--;one_back[next[i]].pb(i);
  }
  vector<int>cycle_id(n,-2);
  vector<map<int,int>>cycles;
  REP(i,0,n){
    if(cycle_id[i]!=-2)continue;
    vector<int>path{i};
    int curr=i;
    while(cycle_id[next[curr]]==-2){
        cycle_id[curr]=-3;
        curr=next[curr];
        path.pb(curr);
    }
    map<int,int>cycle;
    bool in_cycle=false;
    for(int j:path){
        in_cycle=in_cycle || j==next[curr];
        if(in_cycle){cycle[j]=cycle.size();}
        cycle_id[j]=in_cycle?cycles.size():-1;
    }
    if(in_cycle){
        cycles.pb(cycle);   
    }
  }
  vector<int>cyc_dist(n);
  REP(i,0,n){
    if(cycle_id[i]!=-1 || cycle_id[next[i]]==-1)continue;
    cyc_dist[i]=1;
    vector<int>dfs(one_back[i]);
    while(!dfs.empty()){
        int curr=dfs.back();dfs.pop_back();
        cyc_dist[curr]=cyc_dist[next[curr]]+1;
        dfs.insert(dfs.end(),one_back[curr].begin(),one_back[curr].end());
    }
  }
 
  int maxjump=ceil(log2(n));
  vector<vector<int>>ancestors(n,vector<int>(maxjump+1));
  REP(i,0,n)ancestors[i][0]=next[i];
  REP(i,1,maxjump+1){
    REP(j,0,n){
        ancestors[j][i]=ancestors[ancestors[j][i-1]][i-1];
    }
  }
 
 
  REP(i,0,q){
    int u,v;cin>>u>>v;u--;v--;
    if(cycle_id[ancestors[u][maxjump]]!=cycle_id[ancestors[v][maxjump]]){cout<<-1<<endl;continue;}
    if(cycle_id[u]!=-1 || cycle_id[v]!=-1){
        if(cycle_id[u]!=-1 && cycle_id[v]==-1){
            cout<<-1<<endl;continue;
        }
        int dist=cyc_dist[u];
        int u_cyc=jump(u,dist,maxjump,ancestors);
        map<int,int>&cyc=cycles[cycle_id[v]];
        int u_ind=cyc[u_cyc];
        int v_ind=cyc[v];
        int diff=u_ind<=v_ind?v_ind-u_ind:cyc.size()-(u_ind-v_ind);
        cout<<diff+dist<<endl;
    }
    else{
        if(cyc_dist[v]>cyc_dist[u]){cout<<-1<<endl;continue;}
        int diff=cyc_dist[u]-cyc_dist[v];
        int l=jump(u,diff,maxjump,ancestors);
        if(l==v){cout<<diff<<endl;continue;}
        cout<<-1<<endl;
    }
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
