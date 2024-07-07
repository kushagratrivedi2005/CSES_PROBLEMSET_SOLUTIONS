
#include<bits/stdc++.h>
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
 
 
/*
code BY-
 █ ▄▀  █  █  █▀▀▀█  █  █  █▀▀█  █▀▀█  █▀▀█  █▀▀█ 　 
 █▀▄   █  █  ▀▀▀▄▄  █▀▀█  █▄▄█  █ ▄▄  █▄▄▀  █▄▄█ 　 
 █  █  ▀▄▄▀  █▄▄▄█  █  █  █  █  █▄▄█  █  █  █  █ 　 
 
▀▀█▀▀ █▀▀█ ▀█▀  █   █  █▀▀▀ █▀▀▄ ▀█▀ 
  █   █▄▄▀  █    █ █   █▀▀▀ █  █  █
  █   █  █ ▄█▄   ▀▄▀   █▄▄▄ █▄▄▀ ▄█▄ 
*/
 
ii zero={0,0};
    int n;
 int ori(ii a, ii b, ii c ){
    int x1=a.ff,y1=a.ss, x2=b.ff,y2=b.ss, x3=c.ff, y3=c.ss;
    int val=((x2-x1)*(y3-y2)-(y2-y1)*(x3-x2));
    if(val>0)
    return 1;
    if(val<0)
    return -1;
    if(val==0)
    return 0;
  }
 
//   int area(ii a , ii b){
//     return (((a.ff*b.ss)-(b.ff*a.ss))/2);
// }
 
int areaofpolygon(ii verti[]){
int ans=0.0;
for (int i = 0; i < n; i++)
{
    int x1=verti[i].ff ,x2=verti[(i+1)%n].ff, y1=verti[i].ss, y2=verti[(i+1)%n].ss;
    ans+=((x1*y2)-(y1*x2));
}
return abs(ans);
 
}
 
int pointsbetweenseg(ii a, ii b){
    return __gcd(abs(b.ff-a.ff),abs(b.ss-a.ss));
}
 
 
 
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    ii points[n];
    REP(i,0,n) cin>>points[i].ff>>points[i].ss;
    // int totarea=0;
    // REP(i,0,n) totarea+=area( points[i%n], points[(i+1)%n]);
    int boundarypts=0;
    REP(i,0,n) boundarypts+=pointsbetweenseg( points[i%n],points[(i+1)%n]);
    // cout<<totarea;
    int area=areaofpolygon(points)/2;
    int interiorpts=abs(area)-(boundarypts/2)+1;
    cout<<interiorpts<<" "<<boundarypts;
 
    
}
