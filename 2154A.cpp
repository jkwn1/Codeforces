// Codeforces Round 1060 (Div. 2) A
// https://codeforces.com/contest/2154/problem/A

#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
 
    for (int t1 = 0; t1 < t; t1++) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int prevInd = -k-1;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                if (prevInd + k-1 < i) {
                    count++;
                }
                prevInd = i;
            }
        }
        cout << count << endl;
    }
}
