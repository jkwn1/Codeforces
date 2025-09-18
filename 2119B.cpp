#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int t1 = 0; t1 < t; t1++) {
        int n;
        cin >> n;
        int px, py, qx, qy;
        cin >> px >> py >> qx >> qy;
        vector<long long> a(n);
        long long aSum = 0;
        long long aMax = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            aSum += a[i];
            aMax = max(aMax, a[i]);
        }
        long long xDiff = abs(qx - px);
        long long yDiff = abs(qy - py);
        long long dist = xDiff * xDiff + yDiff * yDiff;
        if (n == 1) {
            if (dist == aSum * aSum) {
                cout << "YES" << "\n";
            }
            else {
                cout << "NO" << "\n";
            }
            continue;
        }

        if ((dist > aSum * aSum)) {
            cout << "NO\n";
        }
        else {
            if ((aMax * 2 > aSum)) {
                if (dist < (2 * aMax - aSum) * (2 * aMax - aSum)) {
                    cout << "NO" << "\n";
                    continue;
                }
            }
            cout << "YES\n";
        }
    }
}
