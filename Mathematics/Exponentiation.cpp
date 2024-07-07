
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
 
int binaryexpo(int a,int b){
   if(b==0)
   return 1;
   if(b==1)
   return a;
   int result=binaryexpo(a,b/2);
   if(b&1)
   return (((result*result)%mod)*a)%mod;
   else
   return (result*result)%mod;
}
 
 
int32_t main(){
   int n;cin>>n;
   vii values(n);
   for (int i = 0; i < n; i++)
   {
         cin>>values[i].first;
         cin>>values[i].second;
   }
   
   for (int i = 0; i < n; i++)
   {
      cout<<binaryexpo(values[i].first, values[i].second)<<endl;
   }
   
   
   
 
}
