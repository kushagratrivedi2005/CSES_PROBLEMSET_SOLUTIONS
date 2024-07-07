
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
 
pair<int,int> seg[800005];
vi values(200005);
void createseg(int index,int low,int high){
    if(low==high){
    seg[index]={values[low],low};
    return;}
    int mid=(low+high)/2;
    createseg(2*index+1,low,mid);
    createseg(2*index+2,mid+1,high);
    seg[index]=max(seg[2*index+1],seg[2*index+2]);
}
 
pair<int,int> query(int index, int low, int high, int l, int r) {
    if (high < l || low > r)
        return {INT_MIN,INT_MAX};
    if (low >= l && high <= r)
        return seg[index];
    int mid = (high + low) / 2;
    ii q1 = query(2 * index + 1, low, mid, l, r);
    ii q2 = query(2 * index + 2, mid + 1, high, l, r);
    {return max(q1,q2);}
}
 
 
int32_t main(){
    int n,k; cin>>n>>k;
    REP(i,0,n) cin>>values[i];
    createseg(0,0,n-1);
    int arr_sum[n];
    arr_sum[0]=values[0];
    REP(i,1,n){arr_sum[i]=values[i]+arr_sum[i-1];}
    stack<int>st;
    int suffix[n];
    for(int i=n-1;i>=0;i--){
      while(!st.empty() && values[st.top()]<=values[i])st.pop();
      if(st.empty()){suffix[i]=values[i]*(n-i);}
      else{suffix[i]=suffix[st.top()]+values[i]*(st.top()-i);}
      st.push(i); 
    }
    while(k--){
        int a,b;cin>>a>>b;a--;b--;
        ii m=query(0,0,n-1,a,b);
        int index=m.second;
        // cout<<index<<" "<<suffix[a]<<" "<<values[index]<<" "<<(b-index+1)<<" "<<suffix[index]<<endl;
        cout<<suffix[a]-suffix[index]+values[index]*(b-index+1)-arr_sum[b]+(a==0?0:arr_sum[a-1])<<endl;
    }
    }
 
