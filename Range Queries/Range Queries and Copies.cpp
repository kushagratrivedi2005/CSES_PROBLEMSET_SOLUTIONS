
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
typedef struct node{
    int sum;
    stack<int>st;
}node;
node segtree[600010];
 
void build(int ind,int low,int high,vector<int>&values){
    if(low==high){segtree[ind].sum=values[low];segtree[ind].st.push(values[low]);return;}
    int mid=(low+high)/2;
    build(2*ind+1,low,mid,values);
    build(2*ind+2,mid+1,high,values);
    segtree[ind].sum=segtree[2*ind+1].sum+segtree[2*ind+2].sum;
}
 
void update(int ind,int low,int high,int i,int val){
    if(low==high){segtree[ind].sum=val;segtree[ind].st.push(val);return;}
    int mid=(low+high)/2;
    if(i<=mid){update(2*ind+1,low,mid,i,val);}
    else{update(2*ind+2,mid+1,high,i,val);}
    segtree[ind].sum=segtree[2*ind+1].sum+segtree[2*ind+2].sum;
}
 
int query(int ind,int low,int high,int l,int r){
    if(l>high || r<low)return 0;
    if(l<=low && high<=r){return segtree[ind].sum;}
    int mid=(low+high)/2;
    return query(2*ind+1,low,mid,l,r)+query(2*ind+2,mid+1,high,l,r);
}
 
void rollback(int ind,int low,int high,int i){
    if(low==high){segtree[ind].st.pop(); segtree[ind].sum=segtree[ind].st.top();return;}
    int mid=(low+high)/2;
    if(i<=mid){rollback(2*ind+1,low,mid,i);}
    else{rollback(2*ind+2,mid+1,high,i);}
    segtree[ind].sum=segtree[2*ind+1].sum+segtree[2*ind+2].sum;
}
typedef struct timeline tml;
struct timeline{
    int a,b,i;
    int type=-1;
    tml* next;
    tml* alt;
};
tml* root=new struct timeline;
vector<tml*>nxt={root};
vii ans;
 
void add_update(int k,int a,int b){
    nxt[k]->a=a;
    nxt[k]->b=b;
    nxt[k]->type=0;
    nxt[k]->next=new struct timeline;
    nxt[k]=nxt[k]->next;
}
 
void add_query(int k,int a,int b,int i){
    nxt[k]->a=a;
    nxt[k]->b=b;
    nxt[k]->type=1;
    nxt[k]->i=i;
    nxt[k]->next=new struct timeline;
    nxt[k]=nxt[k]->next;
}
 
void add_copy(int k){
    nxt[k]->type=2;
    nxt[k]->alt=new struct timeline;
    nxt.push_back(nxt[k]->alt);
    nxt[k]->next=new struct timeline;
    nxt[k]=nxt[k]->next;
}
int n;
int i=0;
void explore(tml* root){
    if(root->type==0){
        update(0,0,n-1,root->a,root->b);
        if(root->next)
        explore(root->next);
        rollback(0,0,n-1,root->a);
        return;
    }
    if(root->type==1){
        ans.push_back({root->i,query(0,0,n-1,root->a,root->b)});
        if(root->next)
        explore(root->next);
        return;
    }
    if(root->type==2){
        explore(root->alt);
        if(root->next){
            explore(root->next);
        }
    }
}
 
void solve(int xyz) {
   int q;cin>>n>>q;vector<int>values(n);REP(i,0,n){cin>>values[i];}
   build(0,0,n-1,values);
   REP(j,0,q){
    int x;cin>>x;if(x==1){int k,a,b;cin>>k>>a>>b;k--;a--;add_update(k,a,b);}
    if(x==2){
        int k,a,b;cin>>k>>a>>b;k--;a--;b--;add_query(k,a,b,i++);
    }
    if(x==3){
        int k;cin>>k;k--;add_copy(k);
    }
   }        
   explore(root);
   sort(ans.begin(),ans.end());
   REP(l,0,i){
    cout<<ans[l].second<<endl;
   }
}
 
signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //   int t;cin>>t;
    REP(xyz, 0, 1) {
        solve(xyz);
    }
}
