
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
        void solve(int xyz)
        {
        int n,m,k;cin>>n>>m>>k;
        vector<vector<int>>dist(n+1,vector<int>(n+1,INF));
        REP(i,0,n+1){dist[i][i]=0;}
        REP(i,0,m){
            int x,y,z;cin>>x>>y>>z;dist[x][y]=min(dist[x][y],z);dist[y][x]=min(dist[x][y],z);
        }
        REP(i,0,n+1){
            REP(j,0,n+1){
                REP(k,0,n+1){
                    dist[j][k]=min(dist[j][k],dist[j][i]+dist[i][k]);
                }
            }
        }
        while(k--){
            int x,y;cin>>x>>y;
            if(dist[x][y]==INF){cout<<-1<<endl;}
            else{cout<<dist[x][y]<<endl;}
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
