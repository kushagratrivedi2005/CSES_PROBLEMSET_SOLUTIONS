
#include<iostream>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;
 
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
ll n;
ll x;
cin>>n>>x;
vector<ll>v1;
ll first=0;
ll last=n-1;
ll count=0;
 
for (ll i = 0; i < n; i++)
    {
        int a=0;
        cin>>a;
        v1.emplace_back(a);
    }
sort(v1.begin(),v1.end());
while(last>=first){
    if((v1[first]+v1[last])<=x){
        first++;
        last--;
        count++;
    }
    if((v1[first]+v1[last])>x){
        last--;
        count++;
    }
}
cout<<count<<endl;
 
return 0;
}
