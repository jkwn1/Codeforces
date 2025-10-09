// Squarepoint Challenge (Codeforces Round 1055, Div. 1 + Div. 2) D
// https://codeforces.com/contest/2152/problem/D

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
        vector<long long> a(n+1);
        vector<long long> sum(n+1);
        vector<long long> count1(n+1);
        long long currSum = 0;
        long long count = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            if (a[i] == 2) {
                currSum += 1;
                sum[i] = currSum;
                count1[i] = count;
            }
            else {
                currSum += ceil(log2(a[i]-1));
                sum[i] = currSum;
                count += (((a[i]-1) & (a[i] - 2)) == 0) ? 1 : 0;
                count1[i] = count;
            }
        }
        for (int q1 = 0; q1 < q; q1++) {
            int l, r;
            cin >> l >> r;
            long long ans = sum[r] - sum[l-1];
            ans += (count1[r] - count1[l-1]) / 2;
            cout << ans << "\n";
        }
    }
}
