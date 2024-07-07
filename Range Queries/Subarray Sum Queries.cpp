
#include<bits/stdc++.h>
#define mod 1000000007 
#define int long long
#define REP(i,m,n) for(int i=m;i<n;i++)
#define pb push_back
#define ff first
#define ss second
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>
using namespace std;
 
array<int,4> seg[800005];
vi values(200005);
void createseg(int index,int low,int high){
    if(low==high){
    {seg[index][0]=max(0ll,values[low]); seg[index][1]=max(0ll,values[low]);seg[index][2]=max(0ll,values[low]);seg[index][3]=values[low];}
    return;}
    int mid=(low+high)/2;
    createseg(2*index+1,low,mid);
    createseg(2*index+2,mid+1,high);
  seg[index][3]=seg[2*index+1][3]+seg[2*index+2][3];
    seg[index][0]=max({seg[2*index+1][0],seg[2*index+2][0],seg[2*index+1][2]+seg[2*index+2][1]});
    seg[index][1]=max({seg[2*index+1][1],seg[2*index+1][3]+seg[2*index+2][1]});
    seg[index][2]=max({seg[2*index+2][2],seg[2*index+2][3]+seg[2*index+1][2]});
}
 
void updateseg(int index,int low,int high, int i, int val){
    if(low==high){
    {values[i]=val;seg[index][0]=max(0ll,values[low]); seg[index][1]=max(0ll,values[low]);seg[index][2]=max(0ll,values[low]);seg[index][3]=values[low];}
    return;}
    int mid = (low + high) / 2;
    if (i <= mid) updateseg(2 * index + 1, low, mid, i, val);
    else updateseg(2 * index + 2, mid + 1, high, i, val);
      seg[index][3] = seg[2 * index + 1][3] + seg[2 * index + 2][3];
    seg[index][0] = max({seg[2 * index + 1][0], seg[2 * index + 2][0], seg[2 * index + 1][2] + seg[2 * index + 2][1]});
    seg[index][1] = max(seg[2 * index + 1][1], seg[2 * index + 1][3] + seg[2 * index + 2][1]);
    seg[index][2] = max(seg[2 * index + 2][2], seg[2 * index + 2][3] + seg[2 * index + 1][2]);
 
}
 
array<int,4> query(int index, int low, int high, int l, int r) {
    if (high < l || low > r)
        return {0,0,0,0};
    if (low >= l && high <= r)
        return seg[index];
    int mid = (high + low) / 2;
   auto left = query(2 * index + 1, low, mid, l, r);
    auto right = query(2 * index + 2, mid + 1, high, l, r);
    
    array<int, 4> result;
    result[3] = left[3] + right[3];
    result[0] = max({left[0], right[0], left[2] + right[1]});
    result[1] = max(left[1], left[3] + right[1]);
    result[2] = max(right[2], right[3] + left[2]);
    
    return result;
}
 
 
int32_t main(){
    int n,k; cin>>n>>k;
    REP(i,0,n) cin>>values[i];
    createseg(0,0,n-1);
    while(k--){
        int x,y;cin>>x>>y;
        updateseg(0,0,n-1,x-1,y);
        cout<<query(0,0,n-1,0,n-1)[0]<<endl;
    }
    }
 
