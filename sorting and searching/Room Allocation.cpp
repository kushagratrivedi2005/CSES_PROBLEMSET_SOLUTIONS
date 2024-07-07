
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
 
int main(){
    int n;
    cin>>n;
    vector<pair<pair<int,int>,int>>v(n);
    for (int i = 0; i < n; i++)
    {
        int a,b;
        cin>>a>>b;
        v[i].first.first=a;
        v[i].first.second=b;
        v[i].second=i;
    }
    int ans[n];
    int lastroom=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    sort(v.begin(),v.end());
    for (int i = 0; i < n; i++)
    {
        if(pq.empty()){
            lastroom++;
            pq.push(make_pair(v[i].first.second,lastroom));
            ans[v[i].second]=lastroom;
        }
        else{
            pair<int,int>m=pq.top();
            if(m.first<v[i].first.first){
                pq.pop();
                pq.push(make_pair(v[i].first.second,m.second));
                ans[v[i].second]=m.second;
            }
            else{
                lastroom++;
                pq.push(make_pair(v[i].first.second,lastroom));
                ans[v[i].second]=lastroom;
            }
        }
    }
    
    cout<<lastroom<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<ans[i]<<" ";
    }
    
 
return 0;
}
