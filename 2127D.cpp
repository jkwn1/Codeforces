// Atto Round 1 (Codeforces Round 1041, Div. 1 + Div. 2) D
// https://codeforces.com/contest/2127/problem/D
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long fac[200001];
    long long MOD = 1000000007;
    fac[0] = 1;
    for (int i = 1; i <= 200000; i++) { fac[i] = fac[i - 1] * i % MOD; }

    int t; cin >> t;
    for (int t1 = 0; t1 < t; t1++) {
        int n; cin >> n;
        int m; cin >> m;

        vector<vector<int>> adj(n+1, vector<int>());
        for (int i = 0; i < m; i++) {
            int u, v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        if (n != m+1) {
            cout << 0 << "\n";
            continue;
        }
        if (n == 2) {
            cout << 2 << "\n";
            continue;
        }
        long long count = 2;

        int start = 1;
        for (int i = 1; i <= n; i++) {
            if (adj[i].size() > 1) {
                start = i;
                break;
            }
        }

        vector<bool> visited(n+1, false);
        visited[start] = true;
        queue<int> q;
        int nextToVisitCount = 0;
        for (int next : adj[start]) {
            if (!visited[next]) {
                if (adj[next].size() >= 2) {
                    nextToVisitCount++;
                    q.push(next);
                }
                visited[next] = true;
            }
        }
        if (nextToVisitCount > 2) {
            cout << 0 << "\n";
            continue;
        }
        count = (count * (fac[adj[start].size() - nextToVisitCount])) % MOD;
        if (nextToVisitCount > 0) {
            count = (count * 2) % MOD;
        }

        bool failed = false;
        while (!q.empty()) {
            int toVisit = q.front();
            q.pop();

            nextToVisitCount = 0;
            for (int next : adj[toVisit]) {
                if (!visited[next]) {
                    if (adj[next].size() >= 2) {
                        nextToVisitCount++;
                        q.push(next);
                    }
                    visited[next] = true;
                }
            }
            if (nextToVisitCount > 1) {
                cout << 0 << "\n";
                failed = true;
                break;
            }
            count = (count * (fac[adj[toVisit].size() - nextToVisitCount - 1])) % MOD;
        }
        if (!failed) cout << count << "\n";
    }
}
