// Codeforces Round 1030 (Div. 2) C
// https://codeforces.com/contest/2118/problem/C
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    for (int t1 = 0; t1 < t; t1++) {
        int n;
        long long k;
        cin >> n >> k;
        vector<int> open(60, 0);
        for (int i = 30; i < 60; i++) {
            open[i] = n;
        }
        long long beauty = 0;
        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            for (int j = 0; j <= 29; j++) {
                if (a & (1 << j)) {
                    beauty++;
                }
                else {
                    open[j]++;
                }
            }
        }
        long long mult = 1;
        for (int i = 0; i < 60; i++) {
            if (k >= open[i] * mult) {
                beauty += open[i];
                k -= open[i] * mult;
            }
            else {
                long long poss = k / mult;
                k -= poss * mult;
                beauty += poss;
                break;
            }
            mult *= 2;
        }
        cout << beauty << "\n";
    }
}
