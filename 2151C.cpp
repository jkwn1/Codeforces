// Codeforces Round 1053 (Div. 2) C
// https://codeforces.com/contest/2151/problem/C
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    for (int t1 = 0; t1 < t; t1++) {
        int n; cin >> n;
        vector<long long> arr(2 * n);
        long long sum = 0;
        for (int i = 0; i < 2 * n; i++) {
            cin >> arr[i];
        }
        for (int i = 0; i < n; i++) {
            sum -= arr[i];
        }
        for (int i = n; i < 2 * n; i++) {
            sum += arr[i];
        }
        vector<long long> ans(n+1);
        ans[n] = sum;
        long long prev1 = sum;
        long long prev2 = sum;
        for (int i = n-1; i >= 1; i--) {
            if ((n - i) % 2 == 0) {
                prev1 += 2 * (arr[i]-arr[2*n-1-i]);
                ans[i] = prev1;
            }
            else {
                prev2 += 2 * (arr[i]-arr[2*n-1-i]);
                ans[i] = prev2;
            }
        }
        for (int i = 1; i <= n; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}
