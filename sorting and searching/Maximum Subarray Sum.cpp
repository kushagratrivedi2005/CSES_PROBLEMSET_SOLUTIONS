
#include<iostream>
#include<vector>
#include<climits>
#define ll long long
using namespace std;
 
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n;
cin>>n;
vector<int>v1;
for (int i = 0; i < n; i++)
{
    ll a;
    cin>>a;
    v1.emplace_back(a);
}
ll temp_sum=0, max_sum=INT_MIN;
for (int i = 0; i < n; i++)
{
    temp_sum+=v1[i];
    if (temp_sum>max_sum)
        {max_sum=temp_sum;}
    if(temp_sum<0)
        temp_sum=0;
}
cout<<max_sum;
return 0;
}
