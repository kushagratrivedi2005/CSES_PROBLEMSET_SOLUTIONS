
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
vector<vector<int>>mul(vector<vector<int>>&a,vector<vector<int>>&b){
    int n=a.size(); int m=b[0].size();
    vector<vector<int>>ans(n,vector<int>(m,0));
    REP(i,0,a.size()){
        REP(j,0,b[0].size()){
            REP(k,0,a[0].size()){
                ans[i][j]=(ans[i][j]+(a[i][k]*b[k][j])%mod)%mod;
            }
        }
    }
    return ans;
}
 
vector<vector<int>>p(vector<vector<int>>&a,int n){
    vector<vector<int>>ans(a.size(),vector<int>(a.size(),0));
    REP(i,0,a.size()){ans[i][i]=1;}
    while(n){
        if(n&1){ans=mul(ans,a);}
        a=mul(a,a);
        n=n>>1;
    }
    return ans;
}
 
void solve(int xyz)
{
    int n,m,k;cin>>n>>m>>k;
    vector<vector<int>>values(n,vector<int>(n,0));
    REP(i,0,m){
        int x,y;cin>>x>>y;
        x--;y--;
        values[x][y]++;
    }
    vector<vector<int>>ans(n,vector<int>(n,0));
    ans=p(values,k);
    cout<<ans[0][n-1]<<endl;
 
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
