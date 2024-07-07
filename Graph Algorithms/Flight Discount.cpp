
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
        void dijkstra(vector<vector<pair<int,int>>>&graph,int n,vector<int>&dist,int start){
            vector<int>visited(n+1,0);
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>check;
            dist[start]=0;
            check.push({0,start});
            while(!check.empty()){
                ii curr=check.top(); check.pop();
                if(visited[curr.second])continue;
                visited[curr.second]=1;
                int vertex=curr.second;int distance=curr.first;
                for(auto i:graph[vertex]){
                    if(!visited[i.first]){
                        if(dist[i.first]>i.second+distance){
                            dist[i.first]=i.second+distance;
                            check.push({dist[i.first],i.first});
                        }
                    }
                }
            }
        }
        const int INF=100000000000004;
        void solve(int xyz)
        {
            int n,m;cin>>n>>m;
           vector<vector<pair<int,int>>>graph(n+1);
           vector<vector<pair<int,int>>>reverse(n+1);
           vector<int>dist1(n+1,INF);
           vector<int>dist2(n+1,INF);
           vector<array<int,3>>values;
           REP(i,0,m){
            int x,y,z;cin>>x>>y>>z;
            values.pb({x,y,z});
            graph[x].pb({y,z});
            reverse[y].pb({x,z});
           }
           dijkstra(graph,n,dist1,1);
           dijkstra(reverse,n,dist2,n);
           int mini=1000000000000000;
            REP(i,0,m){
                // cout<<values[i][0]<<" "<<values[i][1]<<" "<<values[i][2]<<endl;
                if(values[i][0]==1){
                    mini=min(mini,dist2[values[i][0]]+values[i][2]/2);
                }
                if(values[i][1]==n){
                    mini=min(mini,dist1[values[i][0]]+values[i][2]/2);
                }
                else{
                    mini=min(mini,dist1[values[i][0]]+dist2[values[i][1]]+values[i][2]/2);
                }
            }
            cout<<mini<<endl;
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
