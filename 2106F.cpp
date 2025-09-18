// Codeforces Round 1020 (Div. 3) F
// https://codeforces.com/contest/2106/problem/F
#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;

    for (int t1 = 0 ; t1 < t ; t1++) {
        int n;
        string s;
        cin >> n >> s;

        long long topMax = 0;
        long long bottomMax = 0;
        long long blockedMax = 0;

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                blockedMax = bottomMax+1;
                ans = max(max(ans, blockedMax), max(topMax, bottomMax));
                bottomMax = 0;
                topMax = 0;
            }
            else {
                topMax = max(topMax + i, blockedMax + i);
                bottomMax = bottomMax + (n - i - 1);
                ans = max(max(ans, blockedMax), max(topMax, bottomMax));
                blockedMax = 0;
            }
        }
        cout << ans << "\n";
    }

}
