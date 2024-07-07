
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
        int n,m; cin>>n>>m;vector<array<int,3>>values(m);
            vector<vector<pair<int,int>>>graph(n);
        REP(i,0,m){int x,y,z;cin>>x>>y>>z;values[i][0]=--x; values[i][1]=--y; values[i][2]=z;}
        // sort(values.begin(),values.end());
        // for(auto it=values.begin(); it!=values.end(); it++){
        //     auto next=it+1;
        //     if(next!=values.end()){
        //     if((*it)[0]==(*next)[0] && (*it)[1]==(*next)[1]){
        //         values.erase(next);
        //     }}
        // }
        for(auto it=values.begin(); it!=values.end();it++){
            graph[(*it)[0]].pb({(*it)[1],(*it)[2]});
        }
        vector<int>visited(n,0);
        vector<int>dist(n,INF);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>check;
        // visited[0]=1;
        dist[0]=0;
        check.push({0,0});
        while(!check.empty()){
            ii curr=check.top();
            int vertex=curr.second; int distance=curr.first;
            check.pop();
            if(visited[vertex])continue;
                visited[vertex]=1;
            for(auto i:graph[vertex]){
                if(!visited[i.first]){
                    if(dist[i.first]>distance+i.second){
                        dist[i.first]=distance+i.second;
                        check.push({dist[i.first],i.first});}
                    }
            }
        }
        REP(i,0,n){cout<<dist[i]<<" ";}
        cout<<endl;
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
