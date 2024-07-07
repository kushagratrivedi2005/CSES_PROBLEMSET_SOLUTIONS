
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
#define int long long
 
int binaryexpo(int a,int b,int module){
   if(b==0)
   return 1;
   if(b==1)
   return a;
   int result=binaryexpo(a,b/2,module);
   if(b&1)
   return (((result*result)%module)*a)%module;
   else
   return (result*result)%module;}
 
 
signed main(){
    int n;
    cin>>n;
    while(n--){
    int a,b,c; cin>>a>>b>>c;
    int res1=binaryexpo(b,c,mod-1);
    cout<<binaryexpo(a,(res1),mod)<<endl;}
    return 0;
}
 
   
   
