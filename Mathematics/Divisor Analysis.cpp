
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
#define int unsigned long long
 
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
int geo(int base ,int power){
    int numerator=(binaryexpo(base,power+1)-1+mod)%mod;
    int denominatorinv=(binaryexpo(base-1,mod-2));
    return(numerator*denominatorinv)%mod;
}
 
signed main(){
    int n;cin>>n;
    vector<int>primes(n);
    vector<int>exponents(n);
    for (int i = 0; i < n; i++)
        cin>>primes[i]>>exponents[i];
    int numberofdivisors=1;
    for (int i = 0; i < n; i++)
        numberofdivisors=(numberofdivisors*(exponents[i]+1))%mod;
    int sumofdivisors=1;
    for (int i = 0; i < n; i++)
    {
        sumofdivisors=(geo(primes[i],exponents[i])*sumofdivisors)%mod;
    }
    int productofdivisors=1;
    bool oddexponent=false;
    int position;
    for (int i = 0; i < n; i++)
    {
            if(exponents[i]&1)
            {oddexponent=true;
            position=i;}
    }
    ll outer=1;
    if(oddexponent){
        for (int i = 0; i < n; i++)
        {
            if(i==position){
                outer=(outer*(exponents[i]+1)/2)%(mod-1);
            }
            else
                outer=(outer*(exponents[i]+1))%(mod-1);
        }
          for (int i = 0; i < n; i++)
    {
        productofdivisors=(productofdivisors*binaryexpo(primes[i],((exponents[i]*outer)%(mod-1)))%mod);
    }
        
    }
    else{
        for (int i = 0; i < n; i++)
        {
            outer=(outer*(exponents[i]+1))%(mod-1);
        }
    for (int i = 0; i < n; i++)
    {
        productofdivisors=(productofdivisors*binaryexpo(primes[i],((exponents[i]/2)*outer)%(mod-1))%mod)%mod;
    }
    }
 
    cout<<numberofdivisors<<" "<<sumofdivisors<<" "<<productofdivisors;
    
    
}
