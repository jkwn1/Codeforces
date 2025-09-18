// Codeforces Round 1044 (Div. 2) B
// https://codeforces.com/contest/2133/problem/B
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    for (int t1 = 0; t1 < t; t1++) {
        int n; cin >> n;
        vector<int> g(n);
        for (int i = 0; i < n; i++) {
            cin >> g[i];
        }
        long long ans = 0;
        sort(g.begin(), g.end());
        for (int i = n-1; i >= 0; i-=2) {
            ans += g[i];
        }
        cout << ans << "\n";
    }
}
