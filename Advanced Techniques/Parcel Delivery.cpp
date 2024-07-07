
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
 
 
// int ancestor[200001][20];
// int depth[200001];
// void preprocess(int src,int par,vector<vector<int>>&graph){
//     ancestor[src][0]=par;
//     for(int i=1;i<20;i++){
//         if(ancestor[src][i-1]!=-1){
//             ancestor[src][i]=ancestor[ancestor[src][i-1]][i-1];
//         }
//         else{
//             ancestor[src][i]=-1;
//         }
//     }
//     for(auto child:graph[src]){
//             if(child!=par)
//         preprocess(child,src,graph);
//     }
// }
 
// void dept(int src,int par,int d,vector<vector<int>>&graph){
//     depth[src]=d;
//     for(auto child:graph[src]){
//         if(child!=par)
//         dept(child,src,d+1,graph);
//     }
// }
 
// int lca(int a,int b,vector<vector<int>>&graph){
//     if(depth[a]<depth[b]){swap(a,b);}
//     int d=depth[a]-depth[b];
//     for(int i=0;i<20;i++){
//         if(d&(1<<i)){
//             a=ancestor[a][i];
//         }
//     }
//     if(a==b){return a;}
//     for(int i=19;i>=0;i--){
//         if(ancestor[a][i]!=ancestor[b][i]){
//             a=ancestor[a][i];
//             b=ancestor[b][i];
//         }
//     }
//     return ancestor[a][0];
// }
 
// int n;
// int segtree[800010];
// int size1[200001];
// int parent[200001];
// int depth[200001];
// int node_id[200001];
// int head_node[200001];
// int query(int l,int r,int ind,int left,int right){
//     if(l>r)return 0;
//     if(left>=l && right<=r){return segtree[ind];}
//     int mid=left+(right-left)/2;
//     int left1=query(l,min(r,mid),2*ind,left,mid);
//     int right1=query(max(l,mid+1),r,2*ind+1,mid+1,right);
//     return max(left1,right1);
// }
// void update(int x,int val,int ind,int left,int right){
//     if(left==right){segtree[ind]=val;return;}
//     int mid=left+(right-left)/2;
//     if(x<=mid){update(x,val,2*ind,left,mid);}
//     else{update(x,val,2*ind+1,mid+1,right);}
//     segtree[ind]=max(segtree[2*ind],segtree[2*ind+1]);
// }
// vector<int>values(200001);
// void update2(int index,int value){
//     segtree[index+=n]=value;
//     for(int ind=index/2;ind>0;ind/=2){
//         segtree[ind]=max(segtree[2*ind],segtree[2*ind+1]);
//     }
// }
// int query2(int a,int b){
//     a+=n;b+=n;
//     int result=0;
//     while(a<=b){
//         if(a&1){
//             result=max(result,segtree[a]);
//             a++;
//         }
//         if(~b&1){
//             result=max(result,segtree[b]);
//             b--;
//         }
//         a/=2;b/=2;
//     }
//     return result;
// }
// vector<vector<int>>adj(200001);
 
// int dfs(int node,int parent1){
//     size1[node]=1;
//     parent[node]=parent1;
//     for(int child:adj[node] ){
//         if(child==parent1)continue;
//         depth[child]=depth[node]+1;
//         parent[child]=node;
//         size1[node]+=dfs(child,node);
//     }
//     return size1[node];
// }
 
// int counter=1;
// void head(int node,int parent,int top){
//     node_id[node]=counter++;
//     head_node[node]=top;
//     update2(node_id[node],values[node]);
//     int heavy_child=-1; int heavy_size=-1;
//     for(int child:adj[node]){
//         if(child==parent)continue;
//         if(size1[child]>heavy_size){
//             heavy_size=size1[child];
//             heavy_child=child;
//         }
//     }
//     if(heavy_child==-1)return;
//     head(heavy_child,node,top);
//     for(int child:adj[node]){
//         if(child==parent || child==heavy_child)continue;
//         head(child,node,child);
//     }
// }
 
// const int n=2e5+5;
// int power(int a,int b){
//     if(b==0)return 1;
//     if(a==0)return 0;
//     if(a==1)return 1;
//     int ans=1;
//     a=a%mod;
//     while(b>0){
//         if(b&1){
//             ans=ans*a%mod;
//         }
//         b>>=1;
//         a=(a*a)%mod;
//     }
//     return ans;
// }
// int fact[n]; int inv[n];
// void once(){
//     fact[0]=1;
//     REP(i,1,n){
//         fact[i]=fact[i-1]*i%mod;
//     }
//     inv[0]=1;
//     REP(i,1,n){
//         inv[i]=power(fact[i],mod-2)%mod;
//     }
// }
// int ncr(int n,int r){
//     int ans=fact[n]%mod;
//     ans*=inv[r]%mod;
//     ans%=mod;
//     ans*=inv[n-r]%mod;
//     ans%=mod;
//     return ans;
// }
// int addmod(int x,int y){
//     return (x+y)%mod;
// }
 
// int multmod(int x,int y){
//     return (x*y)%mod;
// }
/*
code BY-
 █ ▄▀  █  █  █▀▀▀█  █  █  █▀▀█  █▀▀█  █▀▀█  █▀▀█ 　 
 █▀▄   █  █  ▀▀▀▄▄  █▀▀█  █▄▄█  █ ▄▄  █▄▄▀  █▄▄█ 　 
 █  █  ▀▄▄▀  █▄▄▄█  █  █  █  █  █▄▄█  █  █  █  █ 　 
 
▀▀█▀▀ █▀▀█ ▀█▀  █   █  █▀▀▀ █▀▀▄ ▀█▀ 
  █   █▄▄▀  █    █ █   █▀▀▀ █  █  █
  █   █  █ ▄█▄   ▀▄▀   █▄▄▄ █▄▄▀ ▄█▄ 
*/
//from cp algo
struct Edge
{
    int from, to, capacity, cost;
};
 
 
const int INF = 1e9;
vector<Edge> edges(1001);
vector<int>adj[1001];
vector<Edge>Revedges(1001);
 
void shortest_paths(int n, int v0, vector<int>& d, vector<int>& p) {
    d.assign(n+1, INF);
    d[v0] = 0;
    vector<bool> inq(n+1, false);
    queue<int> q;
    q.push(v0);
    p.assign(n+1, -1);
 
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = false;
        for (int v : adj[u]) {
            Edge e=(v<0?Revedges[-v]:edges[v]);
            if (e.capacity> 0 && d[e.to] > d[u] + e.cost) {
                d[e.to] = d[u] + e.cost;
                p[e.to] = v;
                if (!inq[e.to]) {
                    inq[e.to] = true;
                    q.push(e.to);
                }
            }
        }
    }
}
int min_cost_flow(int N, int K, int s, int t) {
    int flow = 0;
    int cost = 0;
    vector<int> d, p;
    while (flow < K) {
        shortest_paths(N, s, d, p);
        if (d[t] == INF)
            break;
 
        // find max flow on that path
        int f = K - flow;   
        int cur = t;
        while (cur != s) {
            Edge e =(p[cur]<0?Revedges[-p[cur]]:edges[p[cur]]);
            f = min(f, e.capacity);
            cur = e.from;
        }
            // apply flow
        flow += f;
        cost += f * d[t];
        cur = t;
        while (cur != s) {
           if(p[cur]<0){
            Revedges[-p[cur]].capacity-=f;
            edges[-p[cur]].capacity+=f;
           }
           else{
             Revedges[p[cur]].capacity+=f;
            edges[p[cur]].capacity-=f;
           }
           cur=(p[cur]<0?Revedges[-p[cur]].from:edges[p[cur]].from);
        }
    }
 
    if (flow < K)
        return -1;
    else
        return cost;
}
 
 
void solve(int xyz)
{
    int n,m,k;cin>>n>>m>>k;
    REP(i,1,m+1){
        int u,v,capacity,cost;cin>>u>>v>>capacity>>cost;
        adj[u].pb(i);
        adj[v].pb(-i);
        edges[i]={u,v,capacity,cost};
        Revedges[i]={v,u,0,-cost};
    }
    int x=min_cost_flow(n,k,1,n);
    if(x==-1){cout<<-1<<endl;return;}
    cout<<x<<endl;
    
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
