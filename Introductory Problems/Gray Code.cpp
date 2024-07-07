
#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> decimalToBinary(int decimalNumber, int length)
{
    vector<int> binaryNumber;
    for (int i = length - 1; i >= 0; i--)
    {
        int shift = decimalNumber >> i;
        (shift & 1) ? binaryNumber.push_back(1) : binaryNumber.push_back(0);
    }
    return binaryNumber;
}
 
vector<int> getgraycode(vector<int> v)
{
    vector<int> g;
    g.push_back(v[0]);
 
    for (int i = 0; i < v.size() - 1; i++)
    {
        g.push_back(v[i] ^ v[i + 1]);
    }
    return g;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n = 0;
    cin >> n;
 
    vector<int> binaryNumber;
    vector<int> grayCode;
 
    for (int i = 0; i < pow(2, n); i++)
    {
        binaryNumber = decimalToBinary(i, n);
        grayCode = getgraycode(binaryNumber);
        for (int i = 0; i < grayCode.size(); i++)
            cout << grayCode[i];
        cout << "\n";
        binaryNumber.clear();
        grayCode.clear();
    }
}
