
#include<iostream>
#include<vector>
#define ll long long
#include<algorithm>
using namespace std;
 
int main(){
int n;
cin>>n;
vector<ll>v;
for (int i = 0; i < n; i++)
{
    int a;
    cin>>a;
    v.emplace_back(a);
}
sort(v.begin(), v.end());
int median=0;
if(n%2==0)
median=((v[(n)/2-1]+v[(n)/2])/2);
else
median=(v[(n+1)/2-1]);
// cout<<median;
ll cost=0;
for (int i = 0; i < n; i++)
{
    cost+=abs(median-v[i]);
}
cout<<cost;
 
return 0;
}
