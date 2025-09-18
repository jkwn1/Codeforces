#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<long long> pow2;
    long long currPow = 2;
    while (currPow <= 2000000000000000000) {
        pow2.push_back(currPow);
        currPow *= 2;
    }

    int t;
    cin >> t;
    for (int t1 = 0; t1 < t; t1++) {
        long long n, l, r, k;
        cin >> n >> l >> r >> k;
        if (n % 2 == 1) {
            cout << l << "\n";
            continue;
        }
        if (n == 2) {
            cout << -1 << "\n";
            continue;
        }
        long long pow = *lower_bound(pow2.begin(), pow2.end(), l+1);
        if (pow > r) {
            cout << -1 << "\n";
            continue;
        }
        if (k == n || k == (n-1)) {
            cout << pow << "\n";
        }
        else {
            cout << l << "\n";
        }
    }
}
