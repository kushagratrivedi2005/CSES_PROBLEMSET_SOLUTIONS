
#include<iostream>
using namespace std;
#define ll long long
 
void printNumber(ll x,ll y){
if(x>=y)
    {
        if(x%2)
        cout<<((x-1)*(x-1)+y)<<" "<<endl;
        else
        cout<<((x*x)-y+1)<<" "<<endl;
    }
else    
    if(y%2)
        cout<<(y*y-x+1)<<" "<<endl;
    else
        cout<<(y-1)*(y-1)+x<<" "<<endl;
}
 
int main(){
    ll t;
cin>>t;
    ll x,y;
    ll arr_x[t];
    ll arr_y[t];
for (ll i = 0; i <t; i++)
{
    cin>>x>>y;
    arr_x[i]=x;
    arr_y[i]=y;
 
}
for (ll j = 0; j < t; j++)
{
    printNumber(arr_x[j],arr_y[j]);
}
 
return 0;
}
