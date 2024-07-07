
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#define ll long long
using namespace std;
 
int main(){
ll n;
cin>>n;
vector<pair<ll,bool>>arr;
for (ll i = 0; i < n; i++)
{
    ll x,y;
    cin>>x>>y;
    arr.emplace_back(x, true);
    arr.emplace_back(y, false);
}
sort(arr.begin(),arr.end());
int ans=0, result=0;
for (int i = 0; i < arr.size(); i++)
{
    if(arr[i].second==true){
        ans++;
        result=max(ans,result);
    }
    else{
        ans--;
    }
}
cout<<result;
 
return 0;
}
