
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
 
 
 
 
// const int n=2e5+5;
// int power(int a,int b){
//     if(b==0)return 1;
//     if(a==0)return 0;
//     if(a==1)return 1;
//     int ans=1;
//     a=a%mod;
//     while(b>0){
//         if(b&1){
//             ans=ans*a%mod;
//         }
//         b>>=1;
//         a=(a*a)%mod;
//     }
//     return ans;
// }
// int fact[n]; int inv[n];
// void once(){
//     fact[0]=1;
//     REP(i,1,n){
//         fact[i]=fact[i-1]*i%mod;
//     }
//     inv[0]=1;
//     REP(i,1,n){
//         inv[i]=power(fact[i],mod-2)%mod;
//     }
// }
// int ncr(int n,int r){
//     int ans=fact[n]%mod;
//     ans*=inv[r]%mod;
//     ans%=mod;
//     ans*=inv[n-r]%mod;
//     ans%=mod;
//     return ans;
// }
// int addmod(int x,int y){
//     return (x+y)%mod;
// }
 
// int multmod(int x,int y){
//     return (x*y)%mod;
// }
/*
code BY-
 █ ▄▀  █  █  █▀▀▀█  █  █  █▀▀█  █▀▀█  █▀▀█  █▀▀█ 　 
 █▀▄   █  █  ▀▀▀▄▄  █▀▀█  █▄▄█  █ ▄▄  █▄▄▀  █▄▄█ 　 
 █  █  ▀▄▄▀  █▄▄▄█  █  █  █  █  █▄▄█  █  █  █  █ 　 
 
▀▀█▀▀ █▀▀█ ▀█▀  █   █  █▀▀▀ █▀▀▄ ▀█▀ 
  █   █▄▄▀  █    █ █   █▀▀▀ █  █  █
  █   █  █ ▄█▄   ▀▄▀   █▄▄▄ █▄▄▀ ▄█▄ 
*/
 
void print321(vector<vector<int>>&grid,int n,int m,int x,int y){
    grid[n][m]='A'+x+y;grid[n][m+1]='A'+x+y;grid[n+1][m]='A'+x+y;
    grid[n+1][m+1]='B'+x+y;grid[n+2][m]='B'+x+y;grid[n+2][m+1]='B'+x+y;
}
void print231(vector<vector<int>>&grid,int n,int m,int x,int y){
    grid[n][m]='A'+x+y;grid[n][m+1]='A'+x+y;grid[n][m+2]='B'+x+y;grid[n+1][m]='A'+x+y;grid[n+1][m+1]='B'+x+y;grid[n+1][m+2]='B'+x+y;
}
void printcase1(vector<vector<int>>&grid,int startrow,int startcolumn,int rows,int columns,int offset){
    int alternate1=0;
    int alternate2=0;
    int z1=rows/3;int z2=columns/2;
    REP(j,0,z2){
        REP(i,0,z1){
            if(alternate1==0 &&alternate2==0){
                print321(grid,i*3+startrow,j*2+startcolumn,0,offset);
            }
            else if(alternate1==1 &&alternate2==0){
                print321(grid,i*3+startrow,j*2+startcolumn,2,offset);
            }
            else if(alternate1==0 &&alternate2==1){
                print321(grid,i*3+startrow,j*2+startcolumn,4,offset);
            }
            else if(alternate1==1 &&alternate2==1){
                print321(grid,i*3+startrow,j*2+startcolumn,6,offset);
            }
            alternate1^=1;
        }
        alternate2^=1;
    }
}
void printcase2(vector<vector<int>>&grid,int startrow,int startcolumn,int rows,int columns,int offset){
    int z2=(columns-3)/2;int z1=(rows/3);
    int alternate1=0;
    int alternate2=0;
    REP(j,0,z2){
        REP(i,0,z1){
            if(alternate1==0 &&alternate2==0){
                print321(grid,i*3+startrow,j*2+startcolumn,0,offset);
            }
            else if(alternate1==1 &&alternate2==0){
                print321(grid,i*3+startrow,j*2+startcolumn,2,offset);
            }
            else if(alternate1==0 &&alternate2==1){
                print321(grid,i*3+startrow,j*2+startcolumn,4,offset);
            }
            else if(alternate1==1 &&alternate2==1){
                print321(grid,i*3+startrow,j*2+startcolumn,6,offset);
            }
            alternate1^=1;
        }
        alternate2^=1;
    }
    REP(i,0,z1*3/2){
        if(alternate1)
        print231(grid,i*2+startrow,z2*2+startcolumn,8,offset);
        else{
            print231(grid,i*2+startrow,z2*2+startcolumn,10,offset);
        }
        alternate1^=1;
    }
}
void printcase3(vector<vector<int>>&grid,int startrow,int startcolumn,int rows,int columns){
    grid[startrow][startcolumn]='A';
    grid[startrow+1][startcolumn]='A';
    grid[startrow+2][startcolumn]='G';
    grid[startrow+3][startcolumn]='G';
    grid[startrow+4][startcolumn]='D';
    grid[startrow+5][startcolumn]='D';
    grid[startrow+6][startcolumn]='A';
    grid[startrow+7][startcolumn]='A';
    grid[startrow+8][startcolumn]='D';
    grid[startrow][startcolumn+1]='A';
    grid[startrow+1][startcolumn+1]='E';
    grid[startrow+2][startcolumn+1]='E';
    grid[startrow+3][startcolumn+1]='G';
    grid[startrow+4][startcolumn+1]='B';
    grid[startrow+5][startcolumn+1]='D';
    grid[startrow+6][startcolumn+1]='A';
    grid[startrow+7][startcolumn+1]='D';
    grid[startrow+8][startcolumn+1]='D';
    grid[startrow][startcolumn+2]='C';
    grid[startrow+1][startcolumn+2]='C';
    grid[startrow+2][startcolumn+2]='E';
    grid[startrow+3][startcolumn+2]='B';
    grid[startrow+4][startcolumn+2]='B';
    grid[startrow+5][startcolumn+2]='I';
    grid[startrow+6][startcolumn+2]='I';
    grid[startrow+7][startcolumn+2]='F';
    grid[startrow+8][startcolumn+2]='F';
    grid[startrow][startcolumn+3]='A';
    grid[startrow+1][startcolumn+3]='C';
    grid[startrow+2][startcolumn+3]='G';
    grid[startrow+3][startcolumn+3]='A';
    grid[startrow+4][startcolumn+3]='A';
    grid[startrow+5][startcolumn+3]='I';
    grid[startrow+6][startcolumn+3]='G';
    grid[startrow+7][startcolumn+3]='F';
    grid[startrow+8][startcolumn+3]='D';
    grid[startrow][startcolumn+4]='A';
    grid[startrow+1][startcolumn+4]='A';
    grid[startrow+2][startcolumn+4]='G';
    grid[startrow+3][startcolumn+4]='G';
    grid[startrow+4][startcolumn+4]='A';
    grid[startrow+5][startcolumn+4]='G';
    grid[startrow+6][startcolumn+4]='G';
    grid[startrow+7][startcolumn+4]='D';
    grid[startrow+8][startcolumn+4]='D';
    int startr1=9;int startr2=0;
    int startc1=0;int startc2=5;
    printcase2(grid,startr1,startc1,rows-9,columns,10);
    printcase1(grid,startr2,startc2,9,columns-5,18);
}
void solve(int xyz)
{
    int swap1=0;
int n,m;cin>>n>>m;if(n%3!=0 && m%3!=0)
{cout<<"NO"<<endl;return;}
if(n==1 || m==1){cout<<"NO"<<endl;return;}
if(n%3!=0){swap(n,m);swap1=1;}
vector<vector<int>>grid(n,vector<int>(m));
if(m%2==0){
    printcase1(grid,0,0,n,m,0);
}
else if(!(n&1)){
   printcase2(grid,0,0,n,m,0);
}
else{
    if(n==3 || m==3){cout<<"NO"<<endl;return;}
    printcase3(grid,0,0,n,m);
}
cout<<"YES"<<endl;
  if(swap1==0)
    REP(i,0,n){
        REP(j,0,m){
            cout<<(char)grid[i][j];
        }
        cout<<endl;
    }
    else{
         REP(i,0,m){
        REP(j,0,n){
            cout<<(char)grid[j][i];
        }
        cout<<endl;
    }
    }
}
 
signed main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif
  
ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int t;cin>>t;
  REP(xyz,0,t){
    solve(xyz);
  }
}
