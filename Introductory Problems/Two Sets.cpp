
#include<iostream>
using namespace std;
 
void printResult(int n){
    if(n%4==3)
        {   cout<<2+((n-3)/4)*2<<endl;
            cout<<1<<" "<<2<<" ";
        for (int i = 4; i < n+1; i+=4)
        {
            cout<<i<<" "<<i+3<<" ";
    
        }
        cout<<endl;
 
        cout<<1+((n-3)/4)*2<<endl;
        cout<<3<<" ";
        for (int i = 5; i < n+1; i+=4)
        {
            cout<<i<<" "<<i+1<<" ";
        }}
    if(n%4==0)
        {cout<<2+((n-4)/4)*2<<endl;
        cout<<1<<" "<<4<<" ";
        for (int i = 5; i < n+1; i+=4)
        {
            cout<<i<<" "<<i+3<<" ";
        }
        cout<<endl;
        cout<<2+((n-4)/4)*2<<endl;
        cout<<3<<" "<<2<<" ";
        for (int i = 6; i < n+1; i+=4)
        {
            cout<<i<<" "<<i+1<<" ";
        }
       }
 
}
 
int main(){
int n;
cin>>n;
if (n%4==1 || n%4==2)
    cout<<"NO";
if (n%4==3 || n%4==0)
 {cout<<"YES"<<endl;
 printResult(n);}
return 0;
}
