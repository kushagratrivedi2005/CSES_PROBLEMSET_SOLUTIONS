
#include<iostream>
using namespace std;
#define ll long long
 
int main(){
int n;
cin>>n;
int nx=0;
ll ans=0;
for (int i = 0; i < n; i++)
{
    int x;
    cin>>x;
    nx=max(x,nx);
    ans+=nx-x;
}
cout<<ans;
return 0;
}
