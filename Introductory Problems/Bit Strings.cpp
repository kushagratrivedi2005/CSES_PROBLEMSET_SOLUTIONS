
#include<iostream>
using namespace std;
 
int main(){
long long n;
cin>>n;
long long s=1;
for (int i = 0; i < n; i++)
{
    
    s=2*s%((int)1e9+7);
}
cout<<s;
 
return 0;
}
