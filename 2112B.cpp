// Educational Codeforces Round 180 (Rated for Div. 2) B
// https://codeforces.com/contest/2112/problem/B
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int t1 = 0; t1 < t; t1++) {
        int n; cin >> n;
        if (n == 2) {
            int a, b; cin >> a >> b;
            if (abs(a-b) > 1) cout << -1 << "\n";
            else cout << 0 << "\n";
            continue;
        }

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int minDiff = 2;
        for (int i = 1; i < n-1; i++) {
            if (arr[i-1] <= arr[i] && arr[i+1] <= arr[i]) {
                minDiff = min(minDiff, 1);
            }
            if (arr[i-1] >= arr[i] && arr[i+1] >= arr[i]) {
                minDiff = min(minDiff, 1);
            }
            if (abs(arr[i-1] - arr[i]) <= 1) {
                minDiff = 0;
            }
        }
        if (abs(arr[n-2] - arr[n-1]) <= 1) {
            minDiff = 0;
        }

        if (minDiff == 2) {
            cout << -1 << "\n";
        }
        else {
            cout << minDiff << "\n";
        }
    }
}
