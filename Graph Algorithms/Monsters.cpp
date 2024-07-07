
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
const int INF=1000000;
 
void printpath(vector<vector<char>>&path,int x,int y){
    char x1=path[x][y];
    // cout<<path[x][y-1]<<endl;
    stack<char>st;
    while(x1!='E'){
        st.push(path[x][y]);
        // cout<<path[x][y]<<" "<<x<<" "<<y<<endl;
        if(path[x][y]=='L'){y++;}
        else if(path[x][y]=='R'){y--;}
        else if(path[x][y]=='U'){x++;}
        else if(path[x][y]=='D'){x--;}
        x1=path[x][y];
    }
    while(!st.empty()){
        cout<<st.top();
        st.pop();
    }
}
bool issafe(int x,int y,vector<vector<char>>&grid,int row,int col){
    return (x<row && x>=0 && y<col && y>=0 && grid[x][y]!='#');
}
vector<pair<int,int>>moves={{1,0},{-1,0},{0,1},{0,-1}};
void solve(int xyz)
{
  int n,m;cin>>n>>m;
  ii start;
  vector<vector<char>>grid(n,vector<char>(m));
  vii monsters;
  REP(i,0,n){
    REP(j,0,m){
        cin>>grid[i][j];
        if(grid[i][j]=='M')monsters.pb({i,j});
        if(grid[i][j]=='A')start={i,j};
    }
  }
  vector<vector<int>>time(n,vector<int>(m,INF));
  vector<vector<int>>visited(n,vector<int>(m,0));
    queue<pair<int,int>>q;
    REP(i,0,monsters.size()){time[monsters[i].first][monsters[i].second]=0; q.push({monsters[i].first,monsters[i].second});visited[monsters[i].first][monsters[i].second]=1;}
    while(!q.empty()){
        ii curr=q.front(); q.pop();
        REP(i,0,moves.size()){
            if(issafe(curr.first+moves[i].first,curr.second+moves[i].second,grid,n,m) && !visited[curr.first+moves[i].first][curr.second+moves[i].second]){
                time[curr.first+moves[i].first][curr.second+moves[i].second]=time[curr.first][curr.second]+1;
                q.push({curr.first+moves[i].first,curr.second+moves[i].second});
                visited[curr.first+moves[i].first][curr.second+moves[i].second]=1;
            }
        }
    }
    vector<vector<char>>path(n,vector<char>(m));
    path[start.first][start.second]='E';
    vector<vector<int>>visited2(n,vector<int>(m,0));
    vector<vector<int>>time2(n,vector<int>(m,INF));
    queue<pair<int,int>>q1;
    time2[start.first][start.second]=0;
    q1.push({start.first,start.second});
    visited2[start.first][start.second]=1;
    while(!q1.empty()){
        ii curr=q1.front(); q1.pop();
        if(curr.first==0 || curr.first==n-1 || curr.second==0 || curr.second==m-1){cout<<"YES"<<endl<<time2[curr.first][curr.second]<<endl;
        printpath(path,curr.first,curr.second);
        // cout<<path[curr.first][curr.second]<<endl;
        // REP(i,0,n){
        //     REP(j,0,m){
        //         cout<<path[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return;}
        REP(i,0,moves.size()){
            if(issafe(curr.first+moves[i].first,curr.second+moves[i].second,grid,n,m) && !visited2[curr.first+moves[i].first][curr.second+moves[i].second] &&time[curr.first+moves[i].first][curr.second+moves[i].second]>1+time2[curr.first][curr.second]){
                 time2[curr.first+moves[i].first][curr.second+moves[i].second]=time2[curr.first][curr.second]+1;
                q1.push({curr.first+moves[i].first,curr.second+moves[i].second});
                visited2[curr.first+moves[i].first][curr.second+moves[i].second]=1;
                if(i==0){path[curr.first+moves[i].first][curr.second+moves[i].second]='D';}
                else if(i==1){path[curr.first+moves[i].first][curr.second+moves[i].second]='U';}
                else if(i==2){path[curr.first+moves[i].first][curr.second+moves[i].second]='R';}
                else if(i==3){path[curr.first+moves[i].first][curr.second+moves[i].second]='L';}
            }
        }
    }
    cout<<"NO"<<endl; return;
 
 
 
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
