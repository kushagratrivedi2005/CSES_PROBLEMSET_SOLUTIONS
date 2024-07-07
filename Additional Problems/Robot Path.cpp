
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define mod 1000000007 
#define int long long
#define REP(i,m,n) for(int i=m;i<n;i++)
#define pb push_back
#define ff first
#define ss second
#define vi vector<int>
#define ii pair<int,int>
#define mp make_pair
#define vii vector<ii>
using namespace std;
using namespace __gnu_pbds;
template<class T> using oset= tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key
 
 
 
 
// const int n=2e5+5;
// int power(int a,int b){
//     if(b==0)return 1;
//     if(a==0)return 0;
//     if(a==1)return 1;
//     int ans=1;
//     a=a%mod;
//     while(b>0){
//         if(b&1){
//             ans=ans*a%mod;
//         }
//         b>>=1;
//         a=(a*a)%mod;
//     }
//     return ans;
// }
// int fact[n]; int inv[n];
// void once(){
//     fact[0]=1;
//     REP(i,1,n){
//         fact[i]=fact[i-1]*i%mod;
//     }
//     inv[0]=1;
//     REP(i,1,n){
//         inv[i]=power(fact[i],mod-2)%mod;
//     }
// }
// int ncr(int n,int r){
//     int ans=fact[n]%mod;
//     ans*=inv[r]%mod;
//     ans%=mod;
//     ans*=inv[n-r]%mod;
//     ans%=mod;
//     return ans;
// }
// int addmod(int x,int y){
//     return (x+y)%mod;
// }
 
// int multmod(int x,int y){
//     return (x*y)%mod;
// }
/*
code BY-
 █ ▄▀  █  █  █▀▀▀█  █  █  █▀▀█  █▀▀█  █▀▀█  █▀▀█  
 █▀▄   █  █  ▀▀▀▄▄  █▀▀█  █▄▄█  █ ▄▄  █▄▄▀  █▄▄█ 
 █  █  ▀▄▄▀  █▄▄▄█  █  █  █  █  █▄▄█  █  █  █  █ 　 
 
▀▀█▀▀ █▀▀█ ▀█▀  █   █  █▀▀▀ █▀▀▄ ▀█▀ 
  █   █▄▄▀  █    █ █   █▀▀▀ █  █  █
  █   █  █ ▄█▄   ▀▄▀   █▄▄▄ █▄▄▀ ▄█▄ 
*/
struct line {
    int x1, x2, y1, y2;
};
 // update ,query and binarysearch from online resource
int maxpoints = 200010;
vector<char> directions(100010);
vector<int> seg(4*maxpoints), lazy(4*maxpoints), distance1(100010);
vii xcoordinates[200010], ycoordinates[200010];
vector<int> pointscompress;
vector<line> lines, sortedlines;
map<int, int> compressedmapping;
 
int cmp(line one, line two) {
    if (one.x2 == two.x2) {return abs(one.x1)>abs(two.x1);}
    return one.x2 < two.x2;
}
 
void update(int l, int r, int value) {
    int leftchildupdates = 0, rightchildupdates = 0;
    l += maxpoints - 1, r += maxpoints + 1;
    int n=1;
    while((l ^ r) > 1) {
        seg[l] += leftchildupdates * value, seg[r] += rightchildupdates * value;
        if (~l & 1) lazy[l ^ 1] += value, seg[l ^ 1] += n * value, leftchildupdates += n;
        if (r & 1) lazy[r ^ 1] += value, seg[r ^ 1] += n * value, rightchildupdates += n;
        l >>= 1, r >>= 1, n <<= 1;
    }
    while(l>0) seg[l] += leftchildupdates * value, seg[r] += rightchildupdates * value , l >>= 1, r >>= 1;
}
 
int query(int l, int r) {
    int sum = 0, leftchildupdates = 0, rightchildupdates = 0;
    l += maxpoints - 1, r += maxpoints + 1;
    int n=1;
    while((l ^ r) >1) {
        sum += lazy[l] * leftchildupdates + lazy[r] * rightchildupdates;
        if (~l & 1) sum += seg[l ^ 1], leftchildupdates += n;
        if (r & 1) sum += seg[r ^ 1], rightchildupdates += n;
        l >>= 1, r >>= 1, n <<= 1;
    }
    while (r>0) sum += leftchildupdates * lazy[l] + rightchildupdates * lazy[r],r >>= 1;
    return sum;
}
 
void pointcompression(vector<int> &points, vector<line> &lines) {
    int count1 = 0;
    map<int, int> map;
    for (int x : points) map[x] = 0;
    for (auto &x : map) x.second = ++count1, compressedmapping[count1] = x.first;
    for (auto &w : lines) {
        w.x1 = map[w.x1], w.x2 = map[w.x2];
        w.y1 = map[w.y1], w.y2 = map[w.y2];
    }
}
 
int iscrashed(int n) {
    int ans = 0;
    sortedlines.clear();
    REP(i,0,n) {
        int x1 = lines[i].x1, x2 = lines[i].x2, y1 = lines[i].y1, y2 = lines[i].y2;
        if (x1 == x2) {
            if (y1 > y2) swap(y1, y2);
            sortedlines.pb({0, x1, y1, y2});
            xcoordinates[x2].pb({y1, y2});
        } else {
            if (x1 > x2) swap(x1, x2);
            sortedlines.pb({1, x1, y1, 0});
            sortedlines.pb({-1, x2 + 1, y2, 0});
            ycoordinates[y1].pb({x1, x2});
        }
    }
    sort(sortedlines.begin(), sortedlines.end(), cmp);
    for (auto q : sortedlines) {
        int x1 = q.x1, x2 = q.x2, y1 = q.y1, y2 = q.y2;
        if (x1) update(y1, y1, x1);
        else if(query(y1,y2))ans=1;
    }
 
    REP(i,1,200010) {
        for (auto p : xcoordinates[i]) {
            int firstpoint = p.first, secondpoint = p.second;
            if(query(firstpoint, secondpoint))ans=1;
            update(firstpoint, secondpoint, 1);
        }
        for (auto p : xcoordinates[i]) {
            int firstpoint = p.first, secondpoint = p.second;
            update(firstpoint, secondpoint, -1);
        }
        for (auto p : ycoordinates[i]) {
            int firstpoint = p.first, secondpoint = p.second;
            if(query(firstpoint,secondpoint))ans=1;
            update(firstpoint, secondpoint, 1);
        }
        for (auto p : ycoordinates[i]) {
            int firstpoint = p.first, secondpoint = p.second;
            update(firstpoint, secondpoint, -1);
        }
        xcoordinates[i].clear(), ycoordinates[i].clear();
    }
    return ans;
}
 
int binarysearch(int n){
    int steps = 0;
    for(int i = 1 << 16; i>0; i >>= 1){
        if(steps + i <= n && !iscrashed(steps + i)) steps += i;
    }
    return steps;
}
 
int crashdistance(int n) {
    if (directions[n] == 'U' && directions[n - 1] == 'D' || directions[n] == 'D' && directions[n - 1] == 'U') return 0;
    if (directions[n] == 'L' && directions[n - 1] == 'R' || directions[n] == 'R' && directions[n - 1] == 'L') return 0;
    int startx = lines[n].x1, endx = lines[n].x2, starty = lines[n].y1, endy = lines[n].y2;
    REP(i,0,n) {
        int x1 = lines[i].x1, x2 = lines[i].x2, y1 = lines[i].y1, y2 = lines[i].y2;
        if (y1 > y2) swap(y1, y2);
        if (x1 > x2) swap(x1, x2);
        if (starty == endy) {
            if (y1 <= starty && y2 >= endy) update(x1, x2, 1);
        } else {
            if (x1 <= startx && x2 >= endx) update(y1, y2, 1);
        }
    }
    if ((starty == endy && startx <= endx) || (startx == endx && starty <= endy)) {
        for (int i = (startx == endx ? starty : startx); i <= (startx == endx ? endy : endx); i++) {
            if (query(i, i)) return compressedmapping[i] - compressedmapping[(startx == endx ? starty : startx)] + 1;
        }
    } else {
        for (int i = (startx == endx ? starty : startx); i >= (startx == endx ? endy : endx); i--) {
            if (query(i, i)) return compressedmapping[(startx == endx ? starty : startx)] - compressedmapping[i] + 1;
        }
    }
    if(startx==endx && starty==endy)return 1;
}
 
void solve(int xyz)
{
pointscompress.pb(0);
    int n, dist, x = 0, y = 0, prevx, prevy, allpoints;
    char d;
    cin >> n;
    REP(i,1,n+1) {
        cin >> d >> dist;
        distance1[i] = distance1[i - 1] + dist;
        if (d == 'U' || d == 'D') {
            if (i == 1){prevy=0;y += (d == 'U' ? dist : -dist);}
            else{prevy = y + (d == 'U' ? 1 : -1), y += (d == 'U' ? dist : -dist);}
            lines.pb({x, x, prevy, y});
            pointscompress.pb(prevy), pointscompress.pb(y);
        } else {
            if (i == 1){ prevx=0;x += (d == 'R' ? dist : -dist);}
            else{prevx = x + (d == 'R' ? 1 : -1), x += (d == 'R' ? dist : -dist);}
            lines.pb({prevx, x, y, y});
            pointscompress.pb(prevx), pointscompress.pb(x);
        }
        directions[i - 1] = d;
    }
    pointcompression(pointscompress, lines);
    allpoints = binarysearch(n);
    if (allpoints == n) cout << distance1[n] << endl;
    else cout << distance1[allpoints] + crashdistance(allpoints) << endl;
    return ;
}
 
signed main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif
  
ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//   int t;cin>>t;
  REP(xyz,0,1){
    solve(xyz);
  }
}
