
#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n;int k;cin>>n>>k;
    vector<pair<int,int>>values(n);
    for (int i = 0; i < n; i++)
    {
        int x;cin>>x;
        values[i]=make_pair(x,i);
    }
    set<pair<int,int>>left_set;
    set<pair<int,int>>right_set;
    if(k==1){
        for (int i = 0; i < n; i++)
        {
            cout<<values[i].first<<" ";
        }
            return 0;
 
    }
    if(k==2){
        for (int i = 0; i < n-1; i++)
        {
            cout<<min(values[i].first,values[i+1].first)<<" ";
        }
        return 0;
    }
    vector<pair<int,int>>values1(n);
    values1=values;
    sort(values1.begin(),values1.begin()+k);
    for (int i = 0; i < k/2+(k%2); i++)
    {
        left_set.insert(values1[i]);
    }
    for (int i = k/2+(k%2); i < k; i++)
    {
        right_set.insert(values1[i]);
    }
    auto it=left_set.rbegin();
    cout<<it->first<<" ";
    for (int j = 1; j < n-k+1; j++)
    {
        
        if(left_set.count(values[j-1]))
        left_set.erase(values[j-1]);
        else
        right_set.erase(values[j-1]);
        if(*(left_set).rbegin()<values[k-1+j])
        right_set.insert(values[k-1+j]);
        else
        left_set.insert(values[k-1+j]);
        while(left_set.size()<k/2+(k%2)){
        pair<int,int>z=(*right_set.begin());
        right_set.erase(z);
        left_set.insert(z);
        }
        while(left_set.size()>k/2+(k%2)){
            pair<int,int>z=(*left_set.rbegin());
            left_set.erase(z);
            right_set.insert(z);
        }
        cout<<left_set.rbegin()->first<<" ";
        // for (auto it = left_set.begin(); it !=
        //                   left_set.end(); ++it)
        //     cout<<it->first;
        //     cout<<endl;
        // for (auto it = right_set.begin(); it !=
        //                   right_set.end(); ++it)
        //     cout<<it->first;
        // cout<<endl;
        
 
    }
    // cout<<endl;
    // for (int i = 0; i < n; i++)
    // {
    //     cout<<values1[i].first;
    // }
    
    
}
