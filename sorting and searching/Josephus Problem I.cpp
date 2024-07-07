
#include<iostream>
#include<vector>
using namespace std;
 
int main(){
int n;
cin>>n;
vector<int>v(n);
for (int i = 0; i < n; i++)
{
    v[i]=i+1;
}
while(v.size()>1){
    vector<int>v1;
    for (int i = 0; i < v.size(); i++)
    {
        if(i%2==1){
            cout<<v[i]<<" ";
        }
        if (i%2==0)
        {
            v1.emplace_back(v[i]);
        }
    }
    if (v.size()%2==0)
    {
        v=v1;
    }
    else{
        int start=v1.back();
        v1.pop_back();
        v.clear();
        v.emplace_back(start);
        for (int i = 0; i < v1.size(); i++)
        {
            v.emplace_back(v1[i]);
        }
        
    }
}
cout<<v[0];
return 0;
}
