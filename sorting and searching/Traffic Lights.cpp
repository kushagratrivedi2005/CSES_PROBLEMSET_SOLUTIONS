
#include<bits/stdc++.h>
using namespace std;
#define ll long long
// Time complexity : O(N^2(logN))
// void solve(){
//     int x , n;
//     cin>>x>>n;
//     vector<int> a = {0 , x};
//     for(int i = 0; i<n; i++){
//         int no;
//         cin>>no;
//         a.push_back(no);
//         int ans = 0;
//         sort(a.begin() , a.end());
//         for(int i = 0;i<a.size(); i++){
//             ans = max(ans , a[i] - a[i-1]);
//         }
//         cout<<ans<<" ";
 
//     }
 
// }
 
//solution in O(n(logn))
void solve(){
    int x , n;
    cin>>x>>n;
    set<int> position;
    multiset<int> length;
    //now putting the initial lengths in the position set
    position.insert(0);
    position.insert(x);
    //and now substitutinh the lengths difference into the length array
    length.insert(x - 0); 
    //scanning each value
    for(int i = 0; i<n; i++){
        int no;
        cin>>no;
        position.insert(no);
        //finding the iterator of the current element added
        auto it = position.find(no);
        //now using prev to fing the previous iterator
        //also finding the next value
        int previousVal = *prev(it);
        int nextVal = *next(it);
        //erasing the previous length by finding it
        length.erase(length.find(nextVal - previousVal));
        //inserting the new length we got
        length.insert(no - previousVal);
        length.insert(nextVal - no);
        //now printing out the biggest element of the set
        cout<<*length.rbegin()<<" ";
        
    }
}
int main()
{
    solve();
    return 0;
}
