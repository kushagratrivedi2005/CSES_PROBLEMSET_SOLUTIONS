
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
 
int seg[800005];
vi values(200005);
void createseg(int index,int low,int high){
    if(low==high){
    seg[index]=values[low];
    return;}
    int mid=(low+high)/2;
    createseg(2*index+1,low,mid);
    createseg(2*index+2,mid+1,high);
    seg[index]=min(seg[2*index+1],seg[2*index+2]);
}
 
int query(int index, int low, int high, int l, int r) {
    if (high < l || low > r)
        return INT_MAX;
    if (low >= l && high <= r)
        return seg[index];
    int mid = (high + low) / 2;
    int q1 = query(2 * index + 1, low, mid, l, r);
    int q2 = query(2 * index + 2, mid + 1, high, l, r);
    return min(q1, q2);
}
 
 
int32_t main(){
    int n,k; cin>>n>>k;
    REP(i,0,n) cin>>values[i];
    createseg(0,0,n-1);
    while(k--){
        int a,b; cin>>a>>b;
        cout<<query(0,0,n-1,a-1,b-1)<<endl;
    }
    }
 
