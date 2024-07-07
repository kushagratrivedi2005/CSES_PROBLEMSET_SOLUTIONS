
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
 
signed main(){
    int n; cin>>n;
    int answer=0;
    for (int i = 1,j; i <= n; i=j)
    {
        int q=n/i;
        j=n/q+1;
        int sumtojminus1=((((j%mod)*((j-1)%mod))%mod)*binaryexpo(2,mod-2)%mod)%mod;
        int sumtoiminus1=((((i%mod)*((i-1)%mod))%mod)*binaryexpo(2,mod-2)%mod)%mod;
        int sumuptoq=((sumtojminus1)-(sumtoiminus1)+mod)%mod;
        answer=(answer+(q%mod)*(sumuptoq)%mod)%mod;
    }
    cout<<answer;
}
