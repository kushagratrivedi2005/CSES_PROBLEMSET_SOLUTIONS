
#include<iostream>
using namespace std;
int noOfMoves(int k){
int moves=0;
if (k==1)
    moves=1;
if(k>1)
    moves=2*noOfMoves(k-1)+1;
return moves;
}
 
void kushagra(int a, int b, int c, int d){
    if (d==1)
        cout<<a<<" "<<b<<endl;
    if (d>1)
       { kushagra(a,c,b,d-1);
        cout<<a<<" "<<b<<endl;
        kushagra(c,b,a,d-1);}
 
}
 
void steps(int k){
 
        
}
 
int main(){
// ios_base::sync_with_stdio(false);
// cin.tie(NULL);
int n;
cin>>n;
cout<<noOfMoves(n)<<endl;
kushagra(1,3,2,n);
return 0;
}
