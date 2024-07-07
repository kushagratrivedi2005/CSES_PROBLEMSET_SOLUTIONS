
#include<iostream>
using namespace std;
 
int main(){
long long n;
cin>>n;
while(n>1){
    if(n%2==1)
        {printf("%lld ",n);
        n=n*3+1;}
    else
       { printf("%lld ",n);
        n/=2;}
}
cout<<1;
return 0;
}
