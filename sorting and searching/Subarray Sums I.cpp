
#include<iostream>
#define ll long long
using namespace std;
 
int main(){
    int n,x;
    cin>>n>>x;
    int values[n];
    for (int i = 0; i < n; i++)
    {
        cin>>values[i];
    }
    int i=0;
    int j=0;
    int count=0;
    int sum=0;
    while(i<n){
        sum+=values[i];
        while(sum>=x){
            if(sum==x)
            count++;
            sum-=values[j];
            j++;
        }
        i++;
    }
    cout<<count;
}
