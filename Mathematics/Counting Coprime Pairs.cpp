
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
/*
code BY-
 █ ▄▀  █  █  █▀▀▀█  █  █  █▀▀█  █▀▀█  █▀▀█  █▀▀█ 　 
 █▀▄   █  █  ▀▀▀▄▄  █▀▀█  █▄▄█  █ ▄▄  █▄▄▀  █▄▄█ 　 
 █  █  ▀▄▄▀  █▄▄▄█  █  █  █  █  █▄▄█  █  █  █  █ 　 
 
▀▀█▀▀ █▀▀█ ▀█▀  █   █  █▀▀▀ █▀▀▄ ▀█▀ 
  █   █▄▄▀  █    █ █   █▀▀▀ █  █  █
  █   █  █ ▄█▄   ▀▄▀   █▄▄▄ █▄▄▀ ▄█▄ 
*/
const int maxvalue=1000001;
void solve(int xyz)
{
int n;cin>>n;vector<int>values(n);REP(i,0,n)cin>>values[i];
  vector<vector<int>>divisorsof(maxvalue);
  for(int i=2;i<maxvalue;i++){
    if(divisorsof[i].size()==0){
        for(int j=i;j<maxvalue;j+=i){
            divisorsof[j].pb(i);
        }
    }
  }
  vector<int>primedivisorsof(maxvalue);
    vector<int>numbersdivisbleby(maxvalue);
    for(int i=0;i<n;i++){
        for(int j=1;j<(1<<divisorsof[values[i]].size());j++){
            int prod=1;
            int divisors=0;
            for(int k=0;k<divisorsof[values[i]].size();k++){
                if(j&(1<<k)){
                    divisors++;
                    prod*=divisorsof[values[i]][k];
                }
            }
            primedivisorsof[prod]=divisors;
            numbersdivisbleby[prod]++;
        }
    }
    int total=n*(n-1)/2;
    int notcoprime=0;
    for(int i=0;i<maxvalue;i++){
        if(primedivisorsof[i]&1)notcoprime+=numbersdivisbleby[i]*(numbersdivisbleby[i]-1)/2;
        else{notcoprime-=numbersdivisbleby[i]*(numbersdivisbleby[i]-1)/2;}
    }
    cout<<total-notcoprime<<endl;
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
