// Educational Codeforces Round 183 (Rated for Div. 2) C
// https://codeforces.com/contest/2145/problem/C

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int t1 = 0; t1 < t; t1++) {
        int n;
        string s;
        cin >> n >> s;
        int sum = 0;
        vector<int> pref(n+1);

        vector<int> mostRecent(2*n+1, -1); // sum + n
        mostRecent[n] = 0;
        for (int i = 1; i < n+1; i++) {
            if (s[i-1] == 'a') {
                sum++;
            }
            else {
                sum--;
            }
            pref[i] = sum;
        }
        if (sum == 0) {
            cout << 0 << "\n";
            continue;
        }

        int ans = n;
        for (int i = 1; i < n+1; i++) {
            if (mostRecent[pref[i]-sum+n] != -1) {
                ans = min(ans, i - mostRecent[pref[i]-sum+n]);
            }
            mostRecent[pref[i]+n] = i;
        }
        if (ans == n) {
            cout << "-1" << "\n";
        }
        else {
            cout << ans << "\n";
        }
    }
}
