
#include<bits/stdc++.h>
#define mod 1000000007 
#define ll long long
#define REP(i,m,n) for(int i=m;i<n;i++)
#define pb push_back
#define ff first
#define ss second
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>
using namespace std;
#define int unsigned long long
 
int32_t main(){
    int n,k; cin>>n>>k;
    vector<int>v(n);
    REP(i,0,n) cin>>v[i];
    int prefixsums[n];
    prefixsums[0]=v[0];
 
    for (int i = 1; i < n; i++)
    {
        prefixsums[i]=prefixsums[i-1]+v[i];
    }
    // REP(i,0,n) cout<<prefixsums[i]<<" ";
    // cout<<endl;
    while(k--){
        int a,b; cin>>a>>b;
        if(a==1)
        cout<<prefixsums[b-1]<<endl;
        else
        cout<<prefixsums[b-1]-prefixsums[a-2]<<endl;
 
    }
 
}
