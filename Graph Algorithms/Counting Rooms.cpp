
#include<iostream>
using namespace std;
bool visit[1000][1000];
 int cnt=0;
 int n,m;
    int h[4]={1,-1,0,0};
    int v[4]={0,0,1,-1};
 
 
    void dfs(int x,int y){
        visit[x][y]=true;
        for (int i = 0; i < 4; i++)
        {
            int dx=x+h[i], dy=y+v[i];
            if(!visit[dx][dy] and dx<n and dx>=0 and dy>=0 and dy<m)
            dfs(dx,dy);
        }
        
    }
 
 
int main(){
    cin>>n>>m;
    int grid[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c;
            cin>>c;
            visit[i][j]=(c=='#');
        }}
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < m; j++)
        //     {
        //         cout<<visit[i][j];
        //     }
        //     cout<<endl;
        // }
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if(!visit[i][j]){
                dfs(i,j);
                cnt++;}
            }
            
        }
        cout<<cnt;
    }
    
   
    
