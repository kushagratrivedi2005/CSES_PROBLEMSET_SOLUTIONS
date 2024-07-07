
#include<iostream>
#include<vector>
using namespace std;
 
int main(){
vector<string> v1;
int n;
cin>>n;
for (int i = 0; i < n; i++)
{
    int x,y;
    cin>>x>>y;
    if(x/2<=y && y<=x*2 && (x+y)%3==0)
        v1.emplace_back("YES");
    else
        v1.emplace_back("NO");
}
 
for (int j = 0; j < n; j++)
{
    cout<<v1[j]<<endl;
}
 
return 0;
}
