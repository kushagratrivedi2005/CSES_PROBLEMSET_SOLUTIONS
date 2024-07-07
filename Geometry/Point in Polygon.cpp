
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
 
    bool onseg(ii a, ii b, ii c ){
    int x1=a.ff,y1=a.ss, x2=b.ff,y2=b.ss, x3=c.ff, y3=c.ss;
    return (x3>=min(x1,x2) and x3<=max(x1,x2) and y3>=min(y1,y2) and y3<=max(y1,y2));
  }
 
    bool intersect( ii a, ii b, ii c, ii d){
        int x1=a.ff,y1=a.ss, x2=b.ff,y2=b.ss, x3=c.ff, y3=c.ss, x4=d.ff, y4=d.ss;
    int ori1=ori(a,c,d);
    int ori2=ori(b,c,d);
    int ori3=ori(c,a,b);
    int ori4=ori(d,a,b);
    if(ori1!=ori2 and ori3!=ori4) return 1;
        // else if(ori1==0 and onseg(c,d,a)) return 1;
        // else if(ori2==0 and onseg(c,d,b)) return 1;
        // else if(ori3==0 and onseg(b,a,c)) return 1;
        // else if(ori4==0 and onseg(b,a,d)) return 1;
        else return 0;
 
    }
 
 
void solve(){
  int n,m; cin>>n>>m;
    vii vertices;
    for (int i = 0; i < n; i++)
    {
        int x,y; cin>>x>>y;
        vertices.pb(mp(x,y));
    }
    
    vii points;
    for (int i = 0; i < m; i++)
    {
        int x,y; cin>>x>>y;
        points.pb(mp(x,y));
    }
        
    for(ii cp :points){
        ii endp={(int)INT_MAX,(int)INT_MAX+45};
        int intersectioncount=0;
         bool boundary=false;
        for (int i = 0; i < n; i++)
        {
            ii a=vertices[i%n];
            ii b=vertices[(i+1)%n];
            if(ori(a,b,cp)==0 and onseg(a,b,cp)){
                boundary=true;
                break;
            }
            if(intersect(a,b,cp,endp))
            intersectioncount++;
        }
            if(boundary) cout<<"BOUNDARY"<<endl;
            else if(intersectioncount%2==0) cout<<"OUTSIDE"<<endl;
            else cout<<"INSIDE"<<endl;
    }
 
 
 
}
 
 
 
 
 
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
// int t; cin>>t;
// for (int i = 0; i < t; i++)
// {
        solve();
// }
}
 
 
 
 
 
 
 
