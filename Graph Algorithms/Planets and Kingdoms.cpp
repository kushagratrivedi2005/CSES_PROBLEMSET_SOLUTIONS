
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
       void dfs(vector<int>&visited,vector<vector<int>>&graph,int n,stack<int>&st){
        visited[n]=1;
        for(auto i:graph[n]){
            if(!visited[i]){
                dfs(visited,graph,i,st);
            }
        }
            st.push(n);
       }
       void dfs2(vector<int>&visited,vector<vector<int>>&graph,int n,vector<int>&labels,int counter){
        visited[n]=1;
        for(auto i:graph[n]){
            if(!visited[i]){
                dfs2(visited,graph,i,labels,counter);
            }
        }
            labels[n]=counter;
       }
        void solve(int xyz)
        {
            int n,m;cin>>n>>m;
            vector<vector<int>>graph(n+1);
            vector<vector<int>>reverse(n+1);
            REP(i,0,m){
                int x,y;cin>>x>>y;
                graph[x].pb(y);
                reverse[y].pb(x);
            }
            vector<int>visited(n+1,0);
            stack<int>st;
            for(int i=1;i<n+1;i++){
                if(!visited[i])dfs(visited,graph,i,st);
            }
            int counter=0;
            vector<int>visited2(n+1,0);
            vector<int>labels(n+1);
            while(!st.empty()){
                int i=st.top(); st.pop();
                if(!visited2[i]){
                    counter++;
                dfs2(visited2,reverse,i,labels,counter);}
                // cout<<i<<endl;
            }
            cout<<counter<<endl;
            REP(i,1,n+1){cout<<labels[i]<<" ";}
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
