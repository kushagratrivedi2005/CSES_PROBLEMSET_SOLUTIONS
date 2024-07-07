
#include<iostream>
using namespace std;
int numberOfWays=0;
const int n=8;
string chessboard[n];
bool rightdiagonal[2*(n-1)], leftdiagonal[2*(n-1)],column[n];
 
void putnext(int r){
 
    if(r==n){
        numberOfWays++;
        return;
    }
 
    for (int c = 0; c < n; c++)
    {
        if(column[c]==0 && rightdiagonal[r-c+n-1]==0 && leftdiagonal[r+c]==0 && chessboard[r][c]=='.'){
            column[c]=1, rightdiagonal[r-c+n-1]=1 , leftdiagonal[r+c]=1;
            putnext(r+1);
            column[c]=0 , rightdiagonal[r-c+n-1]=0 , leftdiagonal[r+c]=0;
        }
 
 
    }
    
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
for (int i = 0; i < n; i++)
{
    cin>>chessboard[i];
}
 
putnext(0);
cout<<numberOfWays;
return 0;
}
