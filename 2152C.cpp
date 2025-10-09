// Squarepoint Challenge (Codeforces Round 1055, Div. 1 + Div. 2) C
// https://codeforces.com/contest/2152/problem/C

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for(int t1 = 0; t1 < t; t1++) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n+1);
        for (int i = 1; i <= n; i++) cin >> a[i];

        vector<int> pref0(n+1, 0);
        for (int i = 1; i <= n; i++) {
            pref0[i] = pref0[i-1] + (a[i] == 0 ? 1 : 0);
        }

        vector<int> prefEq(n+1, 0);
        for (int i = 1; i <= n-1; i++) {
            prefEq[i] = prefEq[i-1] + (a[i] == a[i+1] ? 1 : 0);
        }
        prefEq[n] = prefEq[n-1];

        for (int q1 = 0; q1 < q; q1++) {
            int l, r;
            cin >> l >> r;
            int L = r - l + 1;

            int zeros = pref0[r] - pref0[l-1];
            int ones  = L - zeros;

            if (zeros % 3 != 0 || ones % 3 != 0) {
                cout << -1 << '\n';
                continue;
            }

            int eqPairs = 0;
            if (r - 1 >= l) eqPairs = prefEq[r-1] - prefEq[l-1];
            bool alternating = (eqPairs == 0);

            long long ans = L / 3 + (alternating ? 1 : 0);
            cout << ans << '\n';
        }
    }
}
