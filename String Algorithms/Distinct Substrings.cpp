
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
#define MAX_N 100010
 
char T[MAX_N];
int n;
int RA[MAX_N], tempRA[MAX_N];
int SA[MAX_N], tempSA[MAX_N];
int c[MAX_N];
int LCP[MAX_N];
int PLCP[MAX_N], Phi[MAX_N];
 
void countingSort(int k) {
    int i, sum, maxi = max(300ll, n);
    memset(c, 0, sizeof c);
    for (i = 0; i < n; i++)
        c[i + k < n ? RA[i + k] : 0]++;
    for (i = sum = 0; i < maxi; i++) {
        int t = c[i]; c[i] = sum; sum += t;
    }
    for (i = 0; i < n; i++)
        tempSA[c[SA[i] + k < n ? RA[SA[i] + k] : 0]++] = SA[i];
    for (i = 0; i < n; i++)
        SA[i] = tempSA[i];
}
 
void constructSA() {
    int i, k, r;
    for (i = 0; i < n; i++) RA[i] = T[i];
    for (i = 0; i < n; i++) SA[i] = i;
    for (k = 1; k < n; k <<= 1) {
        countingSort(k);
        countingSort(0);
        tempRA[SA[0]] = r = 0;
        for (i = 1; i < n; i++)
            tempRA[SA[i]] = (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i] + k] == RA[SA[i-1] + k]) ? r : ++r;
        for (i = 0; i < n; i++)
            RA[i] = tempRA[i];
        if (RA[SA[n-1]] == n-1) break;
    }
}
 
void constructLCP() {
    int i, L;
    Phi[SA[0]] = -1;
    for (i = 1; i < n; i++)
        Phi[SA[i]] = SA[i-1];
    for (i = L = 0; i < n; i++) {
        if (Phi[i] == -1) {
            PLCP[i] = 0;
            continue;
        }
        while (T[i + L] == T[Phi[i] + L]) L++;
        PLCP[i] = L;
        L = max(L - 1, 0ll);
    }
    for (i = 0; i < n; i++)
        LCP[i] = PLCP[SA[i]];
}
 
void solve(int xyz) {
    string input;
    getline(cin, input);
    strcpy(T, input.c_str());
    n = (int)strlen(T);
    T[n++] = '$';
    constructSA();
    constructLCP();
    int sum=0;
    for (int i = 0; i < n; i++)
        {sum+=LCP[i];}
    cout<<(n*(n-1))/2-sum;
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
