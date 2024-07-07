
#include<iostream>
#include<vector>
#define ll long long 
#include<algorithm>
using namespace std;
 
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
ll n;
cin>>n;
vector<pair<int,int>>v1;
for (int i = 0; i < n; i++)
{
    int a=0,b=0;
    cin>>a>>b;
    v1.emplace_back(b,a);
}
ll curr_end=0; ll count=0;
sort(v1.begin(), v1.end());
for (auto ele:v1){
    if(ele.second>=curr_end){
        curr_end=ele.first;
        count++;
    }
}
cout<<count;
return 0;
}
