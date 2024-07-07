
#include<bits/stdc++.h>
#define mod 1000000007 
#define ll long long
#define REP(i,m,n) for(int i=m;i<n;i++)
#define pb push_back
#define ff first
#define ss second
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>
using namespace std;
#define int long long
 
signed main(){
    vector<int>range(1e6,0);
    int n;cin>>n;
    for (int i = 0; i < n; i++)
    {
        int x;cin>>x;
        range[x]++;
    }
    for (int i = 1e6; i >=1; i--)
    {
        int count=0;
        for (int j = i; j <= 1e6; j+=i)
        {
            count+=range[j];
            if(count>1)
            {
                cout<<i;
                return 0;
            }
        }
        
    }
    
}
   
   
