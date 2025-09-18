// Codeforces Round 1025 (Div. 2) D
// https://codeforces.com/contest/2109/problem/D
#include <bits/stdc++.h>
using namespace std;


int main() {
    int t;
    cin >> t;

    for (int t1 = 0; t1 < t; ++t1) {
        int n, m, l;
        cin >> n >> m >> l;
        int sum = 0;
        int smallestOdd = INT_MAX;
        for (int i = 0; i < l; i++) {
            int a;
            cin >> a;
            sum += a;
            if (a % 2 != 0) {
                smallestOdd = min(smallestOdd, a);
            }
        }

        vector<vector<int>> adj(n, vector<int>());

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> oddDist(n, INT_MAX);
        vector<int> evenDist(n, INT_MAX);
        vector<bool> oddVisited(n, false);
        vector<bool> evenVisited(n, false);
        evenDist[0] = 0;
        evenVisited[0] = true;

        queue<pair<int, int>> odds;
        queue<pair<int, int>> evens;

        evens.push({0, 0});

        while (true) {
            while (!evens.empty()) {
                int node = evens.front().first, d = evens.front().second;
                evens.pop();

                for (int next : adj[node]) {
                    if (oddVisited[next]) continue;

                    odds.push({next, d+1});
                    oddDist[next] = d+1;
                    oddVisited[next] = true;
                }
            }

            while (!odds.empty()) {
                int node = odds.front().first, d = odds.front().second;
                odds.pop();

                for (int next : adj[node]) {
                    if (evenVisited[next]) continue;

                    evens.push({next, d+1});
                    evenDist[next] = d+1;
                    evenVisited[next] = true;
                }
            }
            if (evens.empty()) break;
        }

        int evenMax = 0;
        int oddMax = 0;
        if (sum % 2 == 0) {
            evenMax = sum;
            if (smallestOdd != INT_MAX) oddMax = sum - smallestOdd;
        }
        else {
            oddMax = sum;
            if (smallestOdd != INT_MAX) evenMax = sum - smallestOdd;
        }
        for (int i = 0; i < n; i++) {
            if (evenDist[i] <= evenMax || oddDist[i] <= oddMax) {
                cout << 1;
            }
            else {
                cout << 0;
            }
        }

        cout << "\n";
    }
}
