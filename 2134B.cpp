// Codeforces Round 1045 (Div. 2) B
// https://codeforces.com/contest/2134/problem/B
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    for (int t1 = 0; t1 < t; t1++) {
        int n; cin >> n;
        long long k; cin >> k;
        for (int i = 0; i < n; i++) {
            long long a1; cin >> a1;
            long long mult = (a1 % (k+1));
            cout << a1 + k * mult << " ";
        }
        cout << "\n";
    }
}
