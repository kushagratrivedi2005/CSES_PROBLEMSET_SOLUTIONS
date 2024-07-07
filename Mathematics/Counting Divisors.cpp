
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
 
int main(){
   int n;cin>>n;
   vector<int>v(n);
   for (int i = 0; i < n; i++)
   {
      cin>>v[i];
   }
   for (int i = 0; i < n; i++)
   {
      int count=0;
      int check=0;
      for (int j = 1; j <= sqrt(v[i]); j++)
      {
         if(v[i]%j==0)
         count++;
         if((int)sqrt(v[i])*(int)sqrt(v[i])==v[i])
         check=1;
 
      }
      cout<<count*2-check<<endl;
   
   
}
}
