
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#define ll long long
using namespace std;
 
int main(){
ll app,apa,diff;
cin>>app>>apa>>diff;
vector<ll>apart;
vector<ll>appli;
for (ll i = 0; i < app; i++)
{
    int a=0;
    cin>>a;
    appli.emplace_back(a);
}
 
for (ll i = 0; i < apa; i++)
{    
    int b=0;
    cin>>b;
    apart.emplace_back(b);
}
int count=0;
sort(appli.begin(),appli.end());
sort(apart.begin(),apart.end());
int first=0, second=0;
while(first<apa && second<app){
    if(abs(apart[first]-appli[second])<=diff){
        first++;
        count++;
        second++;
    }
    else if(appli[second]>apart[first]){
        first++;
    }
    else if(appli[second]<apart[first]){
        second++;
    }
}
cout<<count<<endl;
return 0;
}
