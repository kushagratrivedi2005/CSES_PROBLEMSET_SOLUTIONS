
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
 
void updateseg(int index,int low,int high, int i, int val){
    if(low==high){
    seg[index]=val;
    return;}
    int mid=(low+high)>>1;
    if(i<=mid) updateseg(2*index+1,low,mid,i,val);
    else updateseg(2*index+2,mid+1,high,i,val);
    seg[index]= min(seg[2*index+1],seg[2*index+2]);
 
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
    REP(i,1,n+1) cin>>values[i];
    createseg(0,1,n);
    while(k--){
        int a,b,c; cin>>a>>b>>c;
        if(a==2)
        cout<<query(0,1,n,b,c)<<endl;
        if(a==1)
        updateseg(0,1,n,b,c);
    }
    }
 
