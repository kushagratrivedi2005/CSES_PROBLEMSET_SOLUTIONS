
#include<iostream>
#include<vector>
#include<map>
#define ll long long
using namespace std;
 
int main(){
    ll n,x;
    cin>>n>>x;
    vector<int>values(n);
    for (int i = 0; i < n; i++)
    {
        cin>>values[i];
    }
    
    ll count=0;
    map<ll,int>seen;
    seen[0]=1;
    ll sum=0;
    for (int i = 0; i < n; i++)
    {
        sum+=values[i];
        count+=seen[sum-x];
        seen[sum]++;
    }
    cout<<count;
 
}
