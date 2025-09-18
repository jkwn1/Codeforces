// Educational Codeforces Round 180 (Rated for Div. 2) D
// https://codeforces.com/contest/2112/problem/D
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int t1 = 0; t1 < t; t1++) {
        int n; cin >> n;
        vector<vector<int>> adj(n, vector<int>());
        vector<int> adjCount(n, 0);
        for (int i = 0; i < n-1; i++) {
            int u, v;
            cin >> u >> v;
            adj[u-1].push_back(v-1);
            adj[v-1].push_back(u-1);
        }
        if (n == 2) {
            cout << "NO" << "\n";
            continue;
        }

        int center = -1;
        for (int i = 0; i < n; i++) {
            if (adj[i].size() == 2) {
                center = i;
                break;
            }
        }
        if (center == -1) {
            cout << "NO" << "\n";
            continue;
        }
        cout << "YES" << "\n";
        cout << adj[center][0]+1 << " " << center+1 << "\n";
        cout << center+1 << " " << adj[center][1]+1 << "\n";
        vector<bool> visited(n, false);
        visited[center] = true;
        visited[adj[center][0]] = true;
        visited[adj[center][1]] = true;

        queue<pair<int, int>> q;
        q.push({adj[center][0], -1}); // -1 means next should go from node
        q.push({adj[center][1], 1}); // 1 means next should go to node
        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            int node = p.first;
            int dir = p.second;
            for (int k: adj[node]) {
                if (!visited[k]) {
                    visited[k] = true;
                    if (dir == -1) {
                        cout << node+1 << " " << k+1 << "\n";
                        q.push({k, 1});
                    }
                    else {
                        cout << k+1 << " " << node+1 << "\n";
                        q.push({k, -1});
                    }
                }
            }
        }
    }
}
