
#include<iostream>
using namespace std;
#define ll long long 
 
ll power(int base,int exponent){
    ll answer=1;
    while(exponent--)
        answer=base*answer;
    return answer;
}
 
int main(){
ll queries,k;
cin>>queries;
while(queries--){
    cin>>k;
    ll n=1,sum=0;
    do{
        sum+=9*power(10,n-1)*n;
        n++;
    }while(sum<=k);
    n--;
 
    ll away=(sum-k)/n;
    ll remainder=(sum-k)%n;
    ll number=power(10,n)-1-away;
    string result=to_string(number);
    cout<<result[result.length()-1-remainder]<<endl;
}
return 0;
}
