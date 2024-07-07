
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
int n,x;
cin>>n>>x;
vector<pair<int,int>>arr;
for (int i = 1; i <= n; i++)
{
    int a;
    cin>>a;
    pair<int,int>p;
    p=make_pair(a,i);
    arr.emplace_back(p);
}
sort(begin(arr),end(arr));
for (int i = 0; i < n; i++)
{
    int l,r;
    l=0;
    r=n-1;
    while (l!=r){
        int target;
        target=x-arr.at(i).first;
        if(l!=i && r!=i && arr.at(l).first+arr.at(r).first==target){
            cout<<arr[l].second<<" "<<arr[r].second<<" "<<arr[i].second;
            return 0;}
        if(arr.at(l).first+arr.at(r).first<target)
            l++;
        else
            r--;
    }
}
    cout<<"IMPOSSIBLE";
return 0;
}
