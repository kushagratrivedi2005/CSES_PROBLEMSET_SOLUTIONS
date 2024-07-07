
  #include <bits/stdc++.h>
  #include <ext/pb_ds/assoc_container.hpp>
  #include <ext/pb_ds/tree_policy.hpp>
  #define mod 1000000007
  #define int long long
  #define REP(i, m, n) for (int i = m; i < n; i++)
  #define pb push_back
  #define ff first
  #define ss second
  #define vi vector<int>
  #define ii pair<int, int>
  #define mp make_pair
  #define vii vector<ii>
  using namespace std;
  using namespace __gnu_pbds;
  template <class T>
  using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key
 
  /*
  code BY-
  █ ▄▀  █  █  █▀▀▀█  █  █  █▀▀█  █▀▀█  █▀▀█  █▀▀█ 　
  █▀▄   █  █  ▀▀▀▄▄  █▀▀█  █▄▄█  █ ▄▄  █▄▄▀  █▄▄█ 　
  █  █  ▀▄▄▀  █▄▄▄█  █  █  █  █  █▄▄█  █  █  █  █ 　
 
  ▀▀█▀▀ █▀▀█ ▀█▀  █   █  █▀▀▀ █▀▀▄ ▀█▀
    █   █▄▄▀  █    █ █   █▀▀▀ █  █  █
    █   █  █ ▄█▄   ▀▄▀   █▄▄▄ █▄▄▀ ▄█▄
  */
 void dfs(int n,vector<vector<int>>&graph,vector<int>&visited,stack<int>&st){
    visited[n]=1;
    for(int i:graph[n]){
        if(!visited[i])
        dfs(i,graph,visited,st);
    }
    st.push(n);
 }
  void dfs2(int n,vector<vector<int>>&graph,vector<int>&visited){
    visited[n]=1;
    for(int i:graph[n]){
        if(!visited[i])
        dfs2(i,graph,visited);
    }
 }
  void solve(int xyz)
  {
    int n,k;cin>>n>>k; vector<vector<int>>graph(n+1);
    vector<vector<int>>reverse(n+1);
    REP(i,0,k){
        int x,y;cin>>x>>y;
        graph[x].pb(y);
        reverse[y].pb(x);
    }
    stack<int>st;
    vector<int>visited(n+1,0);
    REP(i,1,n+1){
        if(!visited[i]){
            dfs(i,graph,visited,st);
        }
    }
    int second=0;int counter=0;int first=0;
    vector<int>visited2(n+1,0);
    while(!st.empty()){
        int x=st.top(); st.pop();
        if(!visited2[x]){
            if(second==0)second=x;else{first=x;}counter++;
            dfs2(x,reverse,visited2);
        }
    }
    if(counter==1){cout<<"YES"<<endl;}
    else{
        cout<<"NO"<<endl<<first<<" "<<second    <<endl; return;
    }
 
  }
 
  signed main()
  {
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //   int t;cin>>t;
    REP(xyz, 0, 1)
    {
      solve(xyz);
    }
  }
