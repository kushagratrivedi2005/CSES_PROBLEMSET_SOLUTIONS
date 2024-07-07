
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
 
 
 
 
const int n=2e5+5;
int power(int a,int b){
    if(b==0)return 1;
    if(a==0)return 0;
    if(a==1)return 1;
    int ans=1;
    a=a%mod;
    while(b>0){
        if(b&1){
            ans=ans*a%mod;
        }
        b>>=1;
        a=(a*a)%mod;
    }
    return ans;
}
int fact[n]; int inv[n];
void once(){
    fact[0]=1;
    REP(i,1,n){
        fact[i]=fact[i-1]*i%mod;
    }
    inv[0]=1;
    REP(i,1,n){
        inv[i]=power(fact[i],mod-2)%mod;
    }
}
int ncr(int n,int r){
    int ans=fact[n]%mod;
    ans*=inv[r]%mod;
    ans%=mod;
    ans*=inv[n-r]%mod;
    ans%=mod;
    return ans;
}
int addmod(int x,int y){
    return (x+y)%mod;
}
 
int multmod(int x,int y){
    return (x*y)%mod;
}
/*
code BY-
 █ ▄▀  █  █  █▀▀▀█  █  █  █▀▀█  █▀▀█  █▀▀█  █▀▀█
 █▀▄   █  █  ▀▀▀▄▄  █▀▀█  █▄▄█  █ ▄▄  █▄▄▀  █▄▄█
 █  █  ▀▄▄▀  █▄▄▄█  █  █  █  █  █▄▄█  █  █  █  █ 　 
 
▀▀█▀▀ █▀▀█ ▀█▀  █   █  █▀▀▀ █▀▀▄ ▀█▀ 
  █   █▄▄▀  █    █ █   █▀▀▀ █  █  █
  █   █  █ ▄█▄   ▀▄▀   █▄▄▄ █▄▄▀ ▄█▄ 
*/
 
 
void solve(int xyz)
{
    int n;cin>>n;vector<vector<int>>grid(n+1,vector<int>(n+1));
    vector<int>p(n+1);vector<int>q(n+1);
        set<int>p1;set<int>q1;
    REP(i,1,n+1){
        string s;cin>>s;
        REP(j,1,n+1){
            if(s[j-1]=='A'){p[i]=j;p1.insert(j);}
            if(s[j-1]=='B'){q[i]=j;q1.insert(j);}
        }
    }
    // REP(i,1,n+1){cout<<p[i]<<" "<<q[i]<<endl;}
    int c1=0,c2=0,c3=0,c4=0,c5=0,c6=0;
    REP(i,1,n+1){
        if(p[i]==0 && q[i]==0)c1++;
        if(p1.find(i)==p1.end() && q1.find(i)==q1.end())c4++;
        if(p[i]==0)c5++;if(q[i]==0)c6++;
        if(p[i]==0 && q[i]!=0 && p1.find(q[i])==p1.end())c2++;
        if(q[i]==0 && p[i]!=0 && q1.find(p[i])==q1.end())c3++;
    }
    int ans=0;
    // cout<<c1<<" "<<c2<<" "<<c3<<" "<<c4<<" "<<c5<<" "<<c6<<endl;
    REP(i,0,min(c1,c4)+1){
        REP(j,0,c2+1){
            REP(k,0,c3+1){
                int temp=0;
                temp=multmod(ncr(c1,i),multmod(ncr(c4,i),multmod(ncr(c2,j),ncr(c3,k))));
                temp=multmod(temp,multmod(fact[i],multmod(fact[c5-i-j],fact[c6-i-k])));
                if((i+j+k)&1){
                    ans=addmod(ans,(mod-temp));
                }
                else{
                    ans=addmod(ans,temp);
                }
            }
        }
    }
    cout<<ans;
}
 
signed main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif
  
ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
once();
//   int t;cin>>t;
  REP(xyz,0,1){
    solve(xyz);
  }
}
