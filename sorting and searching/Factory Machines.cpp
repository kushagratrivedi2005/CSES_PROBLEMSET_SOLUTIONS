
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
#define ll long long
 
int main(){
ll machines,products;
cin>>machines>>products;
vector<ll>v;
for (ll i = 0; i < machines; i++)
{
    int a;cin>>a;
    v.emplace_back(a);
}
ll low=0;
ll high=1e18;
ll ans=1e18;
while(low<=high){
    ll mid=(low+high)/2;
    ll prod=0;
    for (ll i = 0; i < machines; i++)
    {
        prod+=min(mid/v[i],(ll)1e9);
    }
    if(prod>=products){
        if(mid<ans){
            ans=mid;
        }
        high=mid-1;
    }
    else{
        low=mid+1;
    }
}
cout<<ans;
 
return 0;
}
