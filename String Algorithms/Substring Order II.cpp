
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
#define MAX_N 100010
int seg[4*MAX_N];
int lazy[4*MAX_N];
char T[MAX_N];
int n;
int RA[MAX_N], tempRA[MAX_N];
int SA[MAX_N], tempSA[MAX_N];
int c[MAX_N];
void push(int index,int l,int r){
    int mid=(l+r)/2;
    seg[2*index+1]+=(mid-l+1)*lazy[index];
    seg[2*index+2]+=(r-mid)*lazy[index];
    lazy[2*index+1]+=lazy[index];
    lazy[2*index+2]+=lazy[index];
    lazy[index]=0;
}
void update(int index,int low,int high,int value,int l,int r){
    if(low>r || high<l)return;
    if(low<=l && high>=r){seg[index]+=(r-l+1)*value;lazy[index]+=value;return;}
    push(index,l,r);
    int mid=(l+r)/2;
    update(2*index+1,low,high,value,l,mid);
    update(2*index+2,low,high,value,mid+1,r);
    seg[index]=seg[2*index+1]+seg[2*index+2];
}
int query(int index,int low,int high,int l,int r){
    if(low>r || high<l )return 0;
    if(low<=l && high>=r)return seg[index];
    push(index,l,r);
    int mid=(l+r)/2;
    return query(2*index+1,low,high,l,mid)+query(2*index+2,low,high,mid+1,r);
} 
void countingSort(int k) {
    int i, sum, maxi = max(300ll, n);
    memset(c, 0, sizeof c);
    for (i = 0; i < n; i++)
        c[i + k < n ? RA[i + k] : 0]++;
    for (i = sum = 0; i < maxi; i++) {
        int t = c[i]; c[i] = sum; sum += t;
    }
    for (i = 0; i < n; i++)
        tempSA[c[SA[i] + k < n ? RA[SA[i] + k] : 0]++] = SA[i];
    for (i = 0; i < n; i++)
        SA[i] = tempSA[i];
}
 
void constructSA() {
    int i, k, r;
    for (i = 0; i < n; i++) RA[i] = T[i];
    for (i = 0; i < n; i++) SA[i] = i;
    for (k = 1; k < n; k <<= 1) {
        countingSort(k);
        countingSort(0);
        tempRA[SA[0]] = r = 0;
        for (i = 1; i < n; i++)
            tempRA[SA[i]] = (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i] + k] == RA[SA[i-1] + k]) ? r : ++r;
        for (i = 0; i < n; i++)
            RA[i] = tempRA[i];
        if (RA[SA[n-1]] == n-1) break;
    }
    n--;
    for(int i = 1; i < n+1; i++){
      SA[i-1]=SA[i];
    }
     for(int i = 0; i < n; i++){
        update(0, i, i, n - SA[i], 0, n-1);
    }
}
 
int lastindex(string &s, int place, int l, int r, char c) {
    int low = l, high = r;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (s[SA[mid] + place] <= c) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low-1;
}
int currentchar(string &s,int place,int k,int l,int r){
    int n=s.size();
    char low='a',high='z';
    while(low<high){
        char mid=(low+high)/2;
        int x=lastindex(s,place,l,r,mid);
        if(query(0,l,x,0,n-1)<k){
            low=mid+1;
        }
        else{high=mid;}
    }
    return low;
}
void solve(int xyz)
{
   string input;
    getline(cin, input);
    strcpy(T, input.c_str());
    n = (int)strlen(T);
    T[n++] = '$';
    constructSA();
    int k;cin>>k;
    int left=0;int right=n-1;int place=0;int prevleft;
    char curr;string ans;
    while(k>0){
        curr=currentchar(input,place,k,left,right);
        prevleft=left;
        left=lastindex(input,place,left,right,curr-1)+1;
        k-=query(0,prevleft,left-1,0,n-1);
        right=lastindex(input,place,left,right,curr);
        k-=(right-left+1);
        ans+=curr;place++;
        update(0,left,right,-1,0,n-1);
    }
    cout<<ans;
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
