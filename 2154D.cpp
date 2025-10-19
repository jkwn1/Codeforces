// Codeforces Round 1060 (Div. 2) D
// https://codeforces.com/contest/2154/problem/D

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int t1 = 0; t1 < t; t1++) {
        int n;
        cin >> n;
        vector<vector<int>> adj(n, vector<int>());
        for (int i = 0; i < n-1; i++) {
            int u, v;
            cin >> u >> v;
            adj[u-1].push_back(v-1);
            adj[v-1].push_back(u-1);
        }
        queue<int> q;
        q.push(0);
        vector<int> parent(n, 0);
        vector<int> childCount(n, 0);
        vector<bool> visited(n, false);
        vector<int> dist(n, 0);
        visited[0] = true;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (!visited[v]) {
                    q.push(v);
                    dist[v] = dist[u] + 1;
                    parent[v] = u;
                    visited[v] = true;
                    childCount[u]++;
                }
            }
        }
        vector<bool> cantUse(n, false);
        vector<int> toUse;
        cantUse[0] = true;
        int currInd = n-1;
        while (currInd != 0) {
            toUse.push_back(currInd);
            cantUse[currInd] = true;
            currInd = parent[currInd];
        }
        toUse.push_back(0);

        for (int i = 1; i < n; i++) {
            if (childCount[i] == 0 && !cantUse[i]) {
                q.push(i);
            }
        }
        string ans = "";
        int totalCount = 0;
        int currCatMoves = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if ((currCatMoves+dist[u]) % 2 == 0) {
                currCatMoves++;
                ans += to_string(1) + "\n";
                totalCount++;
            }
            else {
                currCatMoves+=2;
                ans += to_string(1) + "\n";
                ans += to_string(1) + "\n";
                totalCount+=2;
            }
            ans += to_string(2) + " " + to_string(u+1) + "\n";
            totalCount++;
            childCount[parent[u]]--;
            if (childCount[parent[u]] == 0 && !cantUse[parent[u]]) {
                q.push(parent[u]);
            }
        }
        int tus = (int) toUse.size() - 1;
        for (int i = tus; i >= 1; i--) {
            if ((currCatMoves+dist[toUse[i]]) % 2 == 0) {
                currCatMoves++;
                ans += to_string(1) + "\n";
                totalCount++;
            }
            else {
                currCatMoves+=2;
                ans += to_string(1) + "\n";
                ans += to_string(1) + "\n";
                totalCount+=2;
            }
            ans += to_string(2) + " " + to_string(toUse[i]+1) + "\n";
            totalCount++;
        }
        cout << totalCount << "\n";
        cout << ans;
    }
}
