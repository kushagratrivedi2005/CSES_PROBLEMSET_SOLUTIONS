
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
 
 int ori(int x1,int y1,int x2,int y2,int x3,int y3 ){
    int val=((x2-x1)*(y3-y2)-(y2-y1)*(x3-x2));
    if(val>0)
    return 1;
    if(val<0)
    return -1;
    if(val==0)
    return 0;
  }
 
  int areafromorigin(int x1, int y1, int x2, int y2){
    return abs((x1*y2-x2*y1));
  }
 
 
void solve(){
    int n;cin>>n;
    int totarea=0;
        int x1,y1,x2,y2; cin>>x1>>y1>>x2>>y2;
        int xspec=x1; int yspec=y1;
        totarea+=areafromorigin(x1,y1,x2,y2)*ori(0,0,x1,y1,x2,y2);
    for (int i = 0; i < n-2; i++)
    {
        int x3,y3; cin>>x3>>y3;
        x1=x2; y1=y2; x2=x3; y2=y3;
        totarea+=areafromorigin(x1,y1,x2,y2)*ori(0,0,x1,y1,x2,y2);
    }
        totarea+=areafromorigin(x2,y2,xspec,yspec)*ori(0,0,x2,y2,xspec,yspec);
 
    cout<<abs(totarea);
 
}
 
 
 
 
 
signed main(){
// int t; cin>>t;
// for (int i = 0; i < t; i++)
// {
        solve();
// }
}
 
