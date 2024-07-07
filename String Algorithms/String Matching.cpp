
#include <iostream>
#include <vector>
using namespace std;
 
int main() {
    string s, m;
    cin >> s >> m;
    int s_len = s.length(), m_len = m.length();
    string concat = m + "%" + s;
    int n = 1 + m_len + s_len;
    int len = 0, i = 1;
    int piarray[s_len + m_len + 1];
    piarray[0] = 0;
    // piarray[1]=1;
    // cout<<piarray[0]<<" ";
    // cout<<concat;
    // cout<<n;
 
    // Build the prefix array (piarray)
    while (i < n) {
        if (concat[i] == concat[len]) {
            len++;
            piarray[i] = len;
            i++;
            // cout<<i<<len;
        } else {
            if (len == 0) {
                piarray[i] = 0;
                // cout<<"("<<piarray[1]<<")";
                i++;
                // cout<<i;
            } else {
                len = piarray[len - 1];
                // cout<<endl<<len<<"   ";
            }
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout<<piarray[17]<<" ";
    // }
    
 
    // Count the occurrences of m in s
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (piarray[i] == m_len) {
            count++;
        }
    }
 
    cout << count << endl;
 
    return 0;
}
