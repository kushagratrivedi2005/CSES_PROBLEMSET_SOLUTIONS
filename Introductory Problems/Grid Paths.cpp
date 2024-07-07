
#include<iostream>
using namespace std;
const int totalSteps =48;
const int n=7;
string path;
bool visited[n][n];
 
void move(int row,int col, int &ans, int &steps){
    if (row==n-1 && col==0){
    if (steps==totalSteps)
        ans++;
        return;
    }
    if ((row==n-1 || row==0 || visited[row+1][col] && visited[row-1][col])  && !visited[row][col-1] && !visited[row][col+1]&& col - 1 >= 0 && col + 1 < n  )
        return;
    if ((col==0 || col==n-1 || visited[row][col+1] && visited[row][col-1]) && !visited[row+1][col] && !visited[row-1][col]&& row - 1 >= 0 && row + 1 < n   )
        return;
 
 
    visited[row][col]=true;
    
        if(path[steps]!='?')
        {
            if(path[steps]=='U'){
                if(row>0){
                if(!visited[row-1][col]){
                    steps++;
                    move(row-1,col,ans,steps);
                    steps--;
                }
                }
            }
            else if(path[steps]=='R'){
                if(col<n-1){
                if(!visited[row][col+1]){
                    steps++;
                    move(row,col+1,ans,steps);
                    steps--;
                }
            }
        }
            else if(path[steps]=='L'){
                if(col>0){
                if(!visited[row][col-1]){
                    steps++;
                    move(row,col-1,ans,steps);
                    steps--;
                }
            }
        }
            else if(path[steps]=='D'){
                if(row<n-1){
                if(!visited[row+1][col]){
                    steps++;
                    move(row+1,col,ans,steps);
                    steps--;
                }
            }
        }
    }
    else{
                if(row>0){
                if(!visited[row-1][col]){
                    steps++;
                    move(row-1,col,ans,steps);
                    steps--;
                }
                }
                if(col<n-1){
                if(!visited[row][col+1]){
                    steps++;
                    move(row,col+1,ans,steps);
                    steps--;
                }
            }
                if(col>0){
                if(!visited[row][col-1]){
                    steps++;
                    move(row,col-1,ans,steps);
                    steps--;
                }
            }
                if(row<n-1){
                if(!visited[row+1][col]){
                    steps++;
                    move(row+1,col,ans,steps);
                    steps--;
                }
            }
        }
    visited[row][col]=false;
    }
    
 
int main(){
    cin>>path;
    int ans=0,steps=0;
    move(0,0,ans,steps);
    cout<<ans<<endl;
 
return 0;
}
