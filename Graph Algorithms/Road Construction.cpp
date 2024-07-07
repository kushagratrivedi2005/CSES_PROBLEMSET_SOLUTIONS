
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
        int comp=0; int maxi=1;
       const int INF=1000000;
        vector<int>parent(100001,0);
        vector<int>size(100001,INF);
        void make(int i){
            parent[i]=i;
            size[i]=1;
        }
        int find(int x){
            if(x==parent[x])return x;
            else{
                return parent[x]=find(parent[x]);
            }
        }
        int Union(int x,int y){
            x=find(x); y=find(y);
            if(x==y)return size[x];
            else{
                if(size[x]<size[y])swap(x,y);
                parent[y]=x;
                size[x]+=size[y];
            }
            comp--;
            return size[x];
        }
        void solve(int xyz)
        {
            int n,m;cin>>n>>m;
            REP(i,1,n+1){make(i);comp++;}
            while(m--){
                int x,y;cin>>x>>y;
                maxi=max(maxi,Union(x,y));
                cout<<comp<<" "<<maxi<<endl;
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
