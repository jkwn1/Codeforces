// Codeforces Round 1020 (Div. 3) A
// https://codeforces.com/contest/2106/problem/A
#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;

    for (int t1 = 0 ; t1 < t ; t1++) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        int count1 = 0;
        int count0 = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                count1++;
            }
            else {
                count0++;
            }
        }
        cout << (count1 * (n-1) + count0) << "\n";
    }

}
