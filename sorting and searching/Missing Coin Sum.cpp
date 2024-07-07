
#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long
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
// cout<<v[0]<<endl;
ll target=1;
for (int i = 0; i < n; i++)
{
    if (v[i]>target)
        break;
    target+=v[i];
}
cout<<target<<endl;
return 0;
}
