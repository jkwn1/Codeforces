#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int t1 = 0; t1 < t; t1++) {
        int n; cin >> n;

        vector<int> dp(n+1, 0);
        vector<vector<int>> pos(n+1, vector<int> ());
        for (int i = 1; i < n+1; i++) {
            int a;
            cin >> a;
            dp[i] = dp[i - 1];
            pos[a].push_back(i);
            if (pos[a].size() >= a) {
                int blockStartPos = pos[a][pos[a].size() - a];

                dp[i] = max(dp[i], dp[blockStartPos-1] + a);
            }
        }
        cout << dp[n] << "\n";
    }
}