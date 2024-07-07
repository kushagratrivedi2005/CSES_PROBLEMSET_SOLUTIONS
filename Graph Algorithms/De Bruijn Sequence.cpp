
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
int counter=1;
int total;
int n;
int dp[16];
void dfs(string &node,string &ans,map<string,int>&visited){
    // cout<<total<<endl;
    for(int i=0;i<2;i++){
        char a=i+'0';
        string next=node.substr(1);
        next+=a;
        // cout<<next<<" "<<ans<<' '<<counter<<endl;
        if(visited.find(next)!=visited.end())continue;
        visited[next]=1;
        ans+=next;counter++;
        if(counter==total)return;
        dfs(next,ans,visited);
        if(counter==total)return;
        visited.erase(visited.find(next));counter--;ans.erase(ans.length()-n,n);
    }
}
 
void solve(int xyz) {
    cin>>n;
    int counter=0;map<string,int>visited;
    total=dp[n];
    // cout<<total<<endl;
    string ans="";
    string node="";
    string final="";
    REP(i,0,n)node+='0';
    ans+=node;
    visited[node]=1;
    dfs(node,ans,visited);
    REP(i,0,n-1){final+=ans[i];}
   
    // cout<<ans<<endl;
    //  cout<<final.size()<<endl;
    //  cout<<ans.size()<<endl;
     int appender=-1;
    while(1){
        // cout<<1<<endl;
        appender+=n;
        // cout<<ans[appender]<<endl;
        final+=ans[appender];
        if(appender>=ans.size()-1)break;
        // cout<<final<<" "<<appender<<endl;
    }
    // cout<<appender<<" "<<ans.size()<<" "<<n<<endl;
    cout<<final<<endl;return;   
}
 
signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
  dp[0]=1;
  REP(i,1,16){dp[i]=dp[i-1]*2;}
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // int t; cin >> t;
    REP(xyz,0,1) {
        solve(xyz);
    }
}
