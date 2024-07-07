
#include<iostream>
using namespace std;
#define ll long long
 
int main(){
ll n;
cin>>n;
    ll sum=0;
for (int i = 0; i < n-1; i++){
    int num;
    cin>>num;
    sum+=num;
}
cout<<(n+1)*n/2-sum;
 
return 0;
}
