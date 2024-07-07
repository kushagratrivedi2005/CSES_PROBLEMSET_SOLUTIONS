
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
int largestRectangleArea(vector<int>& heights) {
    int heightsSize = heights.size();
    vector<int> prefix(heightsSize);
    vector<int> suffix(heightsSize);
    stack<int> st1;
 
    for (int i = 0; i < heightsSize; ++i) {
        while (!st1.empty() && heights[st1.top()] >= heights[i]) {
            st1.pop();
        }
        prefix[i] = st1.empty() ? -1 : st1.top();
        st1.push(i);
    }
 
    while (!st1.empty()) {
        st1.pop();
    }
 
    for (int i = heightsSize - 1; i >= 0; --i) {
        while (!st1.empty() && heights[st1.top()] >= heights[i]) {
            st1.pop();
        }
        suffix[i] = st1.empty() ? heightsSize : st1.top();
        st1.push(i);
    }
 
    int maxArea = 0;
    for (int i = 0; i < heightsSize; ++i) {
        int currArea = (suffix[i] - prefix[i] - 1) * heights[i];
        if (currArea > maxArea) maxArea = currArea;
    }
    return maxArea;
}
 
void solve(int xyz)
{
     int n, m;
    cin >> n >> m;
 
    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }
 
    vector<int> array(m);
    for (int i = 0; i < m; ++i) {
        array[i] = (grid[0][i] == '.') ? 1 : 0;
    }
 
    int maxArea = largestRectangleArea(array);
 
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '*') {
                array[j] = 0;
            } else {
                array[j] += 1;
            }
        }
        int currArea = largestRectangleArea(array);
        if (currArea > maxArea) maxArea = currArea;
    }
 
    cout << maxArea << endl;
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
