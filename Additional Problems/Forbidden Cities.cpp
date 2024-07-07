
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
int addmod(int x,int y){
    return (x+y)%mod;
}
 
int multmod(int x,int y){
    return (x*y)%mod;
}
/*
code BY-
 █ ▄▀  █  █  █▀▀▀█  █  █  █▀▀█  █▀▀█  █▀▀█  █▀▀█ 　 
 █▀▄   █  █  ▀▀▀▄▄  █▀▀█  █▄▄█  █ ▄▄  █▄▄▀  █▄▄█ 　 
 █  █  ▀▄▄▀  █▄▄▄█  █  █  █  █  █▄▄█  █  █  █  █ 　 
 
▀▀█▀▀ █▀▀█ ▀█▀  █   █  █▀▀▀ █▀▀▄ ▀█▀ 
  █   █▄▄▀  █    █ █   █▀▀▀ █  █  █
  █   █  █ ▄█▄   ▀▄▀   █▄▄▄ █▄▄▀ ▄█▄ 
*/
vector<vector<int>>build_tree(vector<int>&id,int n,vector<int>&cutpoint,vector<vector<int>>&comps){
    vector<vector<int>>t;
    int node_id=0;
    REP(node,0,n){
        if(cutpoint[node]){id[node]=node_id++;t.push_back({});}
    }
    for(auto &comp:comps){
        int node=node_id++;
        t.push_back({});
        for(int u:comp){
            if(!cutpoint[u]){id[u]=node;}
            else{t[node].push_back(id[u]);t[id[u]].push_back(node);}
        }
    }
    return t;
}
int timer=0;
void dfs(int node,int parent,vector<vector<int>>&graph,vector<int>&low,vector<int>&num,vector<vector<int>>&comps,stack<int>&st,vector<int>&cutpoint){
    num[node]=low[node]=++timer;
    st.push(node);
    for(int child:graph[node]){
        if(child==parent)continue;
        if(num[child]){
            low[node]=min(low[node],num[child]);
        }
        else{
            dfs(child,node,graph,low,num,comps,st,cutpoint);
            low[node]=min(low[node],low[child]);
            if(low[child]>=num[node]){
                cutpoint[node]=(num[node]>1 || num[child]>2);   
                comps.push_back({node});
                while(comps.back().back()!=child){
                    comps.back().push_back(st.top());st.pop();
                }
            }
        }
    }
}
vector<vector<int>>biconnectedcomps(vector<vector<int>>&graph,vector<int>&cutpoint,vector<int>&id){
    int n=graph.size();
    vector<vector<int>>comps;
    stack<int>st;
    vector<int>num(n);vector<int>low(n);
    dfs(0,-1,graph,low,num,comps,st,cutpoint);
    return build_tree(id,n,cutpoint,comps);
}
void dfs1(int node,int parent,vector<int>&depth,vector<vector<int>>&up,vector<vector<int>>&blocktree,int maxjump){
    if(parent!=-1){
        depth[node]=depth[parent]+1;
        up[node][0]=parent; 
        REP(j,1,maxjump){  
                up[node][j] = up[up[node][j-1]][j-1];
        }
    }
    for(auto child:blocktree[node]){
        if(child==parent)continue;
        dfs1(child,node,depth,up,blocktree,maxjump);
    }
}
int lca(vector<vector<int>>&up,int x,int y,vector<int>&depth,int maxjump){
    if(depth[x]<depth[y])swap(x,y);
    int diff=depth[x]-depth[y];
    for(int i=maxjump;i>=0;i--){
        if ((1 << i) & diff) { x = up[x][i]; }
    }
    if(x==y)return x;
    for(int i=maxjump;i>=0;i--){
        if(up[x][i]!=up[y][i]){
            x=up[x][i];
            y=up[y][i];
        }
    }
    return up[x][0];
}
 
int path(int x,int y,int z,vector<vector<int>>&up,vector<int>&depth,int maxjump){
    int lca1=lca(up,x,y,depth,maxjump);
    int lca2=lca(up,y,z,depth,maxjump);
    int lca3=lca(up,z,x,depth,maxjump);
    if(lca1==z || (lca2==z && lca1==lca3) || (lca3==z && lca1==lca2))return true;
    return false;
}
void solve(int xyz)
{
    int n,m,q;cin>>n>>m>>q;const int maxjump=(int)ceil(log2(n));
    vector<vector<int>>graph;graph.resize(n);
    REP(i,0,m){int x,y;cin>>x>>y;x--;y--;graph[x].pb(y);graph[y].pb(x);}
    vector<int>id(3*n,0),depth(3*n,0);
    vector<int>cutpoint(n);
    vector<vector<int>>up(3*n,vector<int>(maxjump+1));
    vector<vector<int>>blocktree=biconnectedcomps(graph,cutpoint,id);
    dfs1(0,-1,depth,up,blocktree,maxjump);
    REP(i,0,q){
        int a,b,c;cin>>a>>b>>c;a--;b--;c--;
        if(a==c || b==c){cout<<"NO"<<endl;continue;}
        if(cutpoint[c] && path(id[a],id[b],id[c],up,depth,maxjump)){
            cout<<"NO"<<endl;
        }
        else{cout<<"YES"<<endl;}
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
