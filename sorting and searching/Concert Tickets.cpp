
#include<iostream>
#include<set>
#define ll long long
using namespace std;
 
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
ll t,c;
cin>>t>>c;
multiset<int>pirce_of_ticket;
for (ll i = 0; i < t; i++)
{
    int a=0;
    cin>>a;
    pirce_of_ticket.insert(a);
}
 
for(ll i=0; i<c; i++){
    ll price_paid_by_customer;
    cin>>price_paid_by_customer;
 
    auto it=pirce_of_ticket.upper_bound(price_paid_by_customer);
    if (it==pirce_of_ticket.begin()){
        cout<<-1<<endl;
        continue;
    }
    else{
        cout<<*(--it)<<endl;
        pirce_of_ticket.erase(it);
    }
}
 
 
 
return 0;
}
