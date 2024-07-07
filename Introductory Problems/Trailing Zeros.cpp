
#include<iostream>
using namespace std;
 
int main(){
long long n;
cin>>n;
int ans=0;
for (int i = 5; i < n+1; i*=5)
{
    ans+=n/i;
}
cout<<ans;
return 0;
}
