#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    for (int t1 = 0; t1 < t; t1++) {
        int n; cin >> n;
        int prev; cin >> prev;
        int count = 1;
        vector<int> maxConsecutive(n+1, 0);
        for (int i = 1; i < n; i++) {
            int next; cin >> next;
            if (prev == next) {
                count++;
            }
            else {
                maxConsecutive[prev] = max(maxConsecutive[prev], count);
                prev = next;
                count = 1;
            }
        }
        maxConsecutive[prev] = max(maxConsecutive[prev], count);
        long long ans = 250000000001;
        for (long long i = 1; i <= n; i++) {
            if (maxConsecutive[i] == 0) continue;
            ans = min(ans, i * (n - maxConsecutive[i]));
        }
        cout << ans << "\n";
    }
}
