
#include<iostream>
using namespace std;
#define ll long long
 
ll number(ll n){
    ll sum=8;
    sum+=((n-4)*4)*4;
    sum+=24;
    sum+=16;
    sum+=(n-4)*24;
    sum+=((n-4)*(n-4)*8);
    ll s=n*n;
    ll answer=((s*(s-1))/2)-(sum/2);
    return answer;
}
 
void ans(ll n){
    if (n==1)
        cout<<0<<" "<<endl;
    if (n==2)
        cout<<6<<" "<<endl;
    if (n==3)
        cout<<28<<" "<<endl;
    if (n==4)
        cout<<96<<" "<<endl;
    if (n>4)
        cout<<number(n)<<" "<<endl;
}
 
int main(){
ll n;
cin>>n;
for (ll i = 1; i < n+1; i++)
{
    ans(i);
}
// ans(5);
 
 
return 0;
}
