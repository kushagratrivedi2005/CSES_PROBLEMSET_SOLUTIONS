
#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long
#define REP(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define ff first
#define ss second
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>
using namespace std;
 
bool vis[1001][1001];
char ar[1001][1001];
char pr[1001][1001];
vector<char>path;
int n; int m;
 
bool isvalid(int x,int y){
    if(x<1 || x>n || y<1 || y>m) return false;
    if(ar[x][y]=='#' || vis[x][y]==true) return false;
 
    return true;
 
}
 
bool bfs(int x,int y){
 
    queue<pair<int,int>>q;
    q.push({x,y});
    vis[x][y]=true;
    while(!q.empty()){
        int a=q.front().first;
        int b=q.front().second;
        q.pop();
 
        if(ar[a][b]=='B'){
            while(1){
                path.pb(pr[a][b]);
                if(path.back()=='L')b++;
                if(path.back()=='R')b--;
                if(path.back()=='U')a++;
                if(path.back()=='D')a--;
 
                if(a==x and b==y)
                break;
            }
            return true;
        }
        if(isvalid(a-1,b)) vis[a-1][b]=true, q.push({a-1,b}), pr[a-1][b]='U';
 
        if(isvalid(a,b-1)) vis[a][b-1]=true, q.push({a,b-1}), pr[a][b-1]='L';
 
 
        if(isvalid(a,b+1)) vis[a][b+1]=true, q.push({a,b+1}), pr[a][b+1]='R';
 
 
        if(isvalid(a+1,b)) vis[a+1][b]=true, q.push({a+1,b}), pr[a+1][b]='D';
 
 
    }
 
 
    return false;
 
 
}
 
int main(){
    cin>>n>>m;
    int x, y;
    REP(i,n) REP(j,m){
        cin>>ar[i][j];
        if(ar[i][j]=='A') x=i,y=j;
    }
    
 
    if (bfs(x,y))
    {cout<<"YES"<<endl<<path.size()<<endl;
    while(path.size()>0) cout<<path.back(),path.pop_back();}
    else
    cout<<"NO";
    
 
}
