#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    for (int t1 = 0; t1 < t; t1++) {
        int n; cin >> n;
        vector<pair<int, int>> counts(n);
        set<int> left;
        for (int i = 1; i < n+1; i++) {
            left.insert(i);
            string query = "? " + to_string(i) + " " + to_string(n) + " ";
            for (int j = 1; j < n+1; j++) {
                query += to_string(j) + " ";
            }
            cout << query << endl;
            cout.flush();
            int q; cin >> q;
            counts[i-1] = make_pair(q, i);
        }
        sort(counts.begin(), counts.end());
        vector<int> path(counts[n-1].first);
        path[0] = counts[n-1].second;
        int size = counts[n-1].first;
        int currIndex = size-1;
        for (int i = 0; i < n-1; i++) {
            left.erase(counts[i].second);
            string query = "? " + to_string(path[0]) + " " + to_string(left.size()) + " ";
            for (int j: left) {
                query += to_string(j) + " ";
            }
            cout << query << endl;
            cout.flush();
            int q; cin >> q;
            if (q < size) {
                left.insert(counts[i].second);
                path[currIndex] = counts[i].second;
                currIndex--;
            }
        }
        string ans = "! " + to_string(counts[n-1].first) + " ";
        for (int i = 0; i < counts[n-1].first; i++) {
            ans += to_string(path[i]) + " ";
        }
        cout << ans << endl;
        cout.flush();
    }
}