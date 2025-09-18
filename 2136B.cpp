// Codeforces Round 1046 (Div. 2) B
// https://codeforces.com/contest/2136/problem/B
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int t1 = 0; t1 < t; t1++) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int count1 = 0;
        int consecutive1 = 0;
        bool poss = true;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                count1++;
                consecutive1++;
                if (consecutive1 >= k) {
                    poss = false;
                    break;
                }
            }
            else {
                consecutive1 = 0;
            }
        }
        if (poss) {
            cout << "YES\n";
            int curr1 = 0;
            int curr0 = 0;
            for (int i = 0; i < n; i++) {
                if (s[i] == '1') {
                    curr1++;
                    cout << curr1 << " ";
                }
                else {
                    curr0++;
                    cout << (curr0 + count1) << " ";
                }
            }
            cout << "\n";
        }
        else {
            cout << "NO\n";
        }
    }
}
