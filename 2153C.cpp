// Codeforces Round 1057 (Div. 2) C
// https://codeforces.com/contest/2153/problem/C

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int t1 = 0; t1 < t; t1++) {
        int n; cin >> n;
        vector<long long> lengths(n);
        for (int i = 0; i < n; i++) {
            cin >> lengths[i];
        }
        sort(lengths.begin(), lengths.end());
        long long prev = -1;
        int count = 0;
        vector<long long> unUsed;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            if (prev == -1) prev = lengths[i];
            else {
                if (prev == lengths[i]) {
                    sum += lengths[i];
                    count++;
                    prev = -1;
                }
                else {
                    unUsed.push_back(prev);
                    prev = lengths[i];
                }
            }
        }
        if (prev != -1) unUsed.push_back(prev);
        int unUsedCount = (int) unUsed.size();
        if (count == 0) {
            cout << 0 << "\n";
        }
        else if (count == 1){
            if (unUsedCount == 0) {
                cout << 0 << "\n";
                continue;
            }
            if (unUsedCount == 1) {
                if (unUsed[0] < sum * 2) {
                    cout << unUsed[0] + sum * 2 << "\n";
                }
                else {
                    cout << 0 << "\n";
                }
                continue;
            }
            long long ans = 0;
            if (unUsed[0] < sum * 2) {
                ans = sum * 2 + unUsed[0];
            }
            for (int k = unUsedCount-2; k >= 0; k--) {
                if (unUsed[k+1] < sum * 2 + unUsed[k]) {
                    ans = sum * 2 + unUsed[k] + unUsed[k+1];
                    break;
                }
            }
            cout << ans << "\n";
        }
        else {
            if (unUsedCount == 0) {
                cout << 2 * sum << "\n";
                continue;
            }
            if (unUsedCount == 1) {
                if (unUsed[0] < sum * 2) {
                    cout << unUsed[0] + sum * 2 << "\n";
                }
                else {
                    cout << sum * 2 << "\n";
                }
                continue;
            }
            long long ans = sum * 2;
            if (unUsed[0] < sum * 2) {
                ans = sum * 2 + unUsed[0];
            }
            for (int k = unUsedCount-2; k >= 0; k--) {
                if (unUsed[k+1] < sum * 2 + unUsed[k]) {
                    ans = sum * 2 + unUsed[k] + unUsed[k+1];
                    break;
                }
            }
            cout << ans << "\n";
        }
    }
}
