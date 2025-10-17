// Codeforces Round 1057 (Div. 2) D
// https://codeforces.com/contest/2153/problem/D

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int t1 = 0; t1 < t; t1++) {
        int n;
        cin >> n;
        long long ans = 2e15;
        vector<long long> vec(n+1);
        for (int i = 1; i < n+1; i++) cin >> vec[i];
        vector<long long> dp1(n+1, 2e15);
        dp1[0] = 0;
        dp1[2] = abs(vec[2]-vec[1]);
        for (int i = 3; i < n+1; i++) {
            dp1[i] = min(dp1[i-2] + abs(vec[i]-vec[i-1]), dp1[i-3] + max(vec[i],max(vec[i-1], vec[i-2])) - min(vec[i],min(vec[i-1], vec[i-2])));
        }
        ans = min(ans, dp1[n]);
        vector<long long> dp2(n+1, 2e15);
        dp2[1] = abs(vec[1]-vec[n]);
        dp2[2] = max(vec[1],max(vec[2], vec[n])) - min(vec[1],min(vec[2], vec[n]));
        for (int i = 3; i < n; i++) {
            dp2[i] = min(dp2[i-2] + abs(vec[i]-vec[i-1]), dp2[i-3] + max(vec[i],max(vec[i-1], vec[i-2])) - min(vec[i],min(vec[i-1], vec[i-2])));
        }
        ans = min(ans, dp2[n-1]);
        vector<long long> dp3(n+1, 2e15);
        dp3[1] = max(vec[1],max(vec[n-1], vec[n])) - min(vec[1],min(vec[n-1], vec[n]));
        for (int i = 3; i < n-1; i++) {
            dp3[i] = min(dp3[i-2] + abs(vec[i]-vec[i-1]), dp3[i-3] + max(vec[i],max(vec[i-1], vec[i-2])) - min(vec[i],min(vec[i-1], vec[i-2])));
        }
        ans = min(ans, dp3[n-2]);
        cout << ans << endl;
    }
}
