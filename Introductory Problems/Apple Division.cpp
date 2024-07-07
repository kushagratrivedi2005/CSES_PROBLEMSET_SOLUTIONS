
#include<iostream>
#include<vector>
#define ll long long 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, p[20];
    cin>>n;
    ll s=0,ans=0;
    for (int i = 0; i < n; i++)
    {
        cin>>p[i];
        s+=p[i];
    }
    for (int j = 0; j < 1<<n; j++)
    {       ll cs=0;
            for (int k = 0; k < n; k++)
            {
                if (j&1<<k) 
                    cs+=p[k];
 
            }
            if (cs<=s/2)
                ans=max(cs, ans);
            
    }
    cout<<s-2*ans;
 
return 0;
}
