
#include<iostream>
using namespace std;
 
int main(){
int n;
cin>>n;
if (n==1)
    cout<<1;
else if (n==2 || n==3)
    cout<<"NO SOLUTION ";
else    
    {
        int even=2;
        for (int i = even; i <= n; i+=2)
        {
            cout<<i<<" ";
        }
 
        int odd=1;
        for (int i = odd; i <= n; i+=2)
        {
            cout<<i<<" ";
        }
        
    }
    
return 0;
}
