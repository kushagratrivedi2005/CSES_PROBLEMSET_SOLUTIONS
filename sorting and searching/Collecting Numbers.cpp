
#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;
 
int main(){
ll n;
cin>>n;
vector<pair<ll , ll>>v;
for (ll i = 0; i < n; i++)
{
    ll a;
    cin>>a;
    v.emplace_back(a,i);
}
sort(v.begin(),v.end());
// for (int i = 0; i < n; i++)
// {
//     cout<<v[i].first<<" "<<v[i].second<<endl;
// }
 
ll rounds=1;
for (ll i = 0; i <n-1; i++)
{
    if(v[i].second>v[i+1].second)
    rounds++;
}
cout<<rounds;
return 0;
}
