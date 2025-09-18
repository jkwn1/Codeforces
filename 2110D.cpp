#include <bits/stdc++.h>
using namespace std;

struct path
{
    int s, t, w;

    path(int a, int b, int c) : s(a), t(b), w(c) {}

    bool operator < (const path& other) const
    {
        return (w < other.w);
    }
};

int main() {
    int t;
    cin >> t;

    for (int t1 = 0; t1 < t; t1++) {
        int n, m;
        cin >> n >> m;
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        vector<path> paths;
        for (int i = 0; i < m; i++) {
            int s1, t2, w1;
            cin >> s1 >> t2 >> w1;
            paths.push_back(path(s1-1, t2-1, w1));
        }
        sort(paths.begin(), paths.end());

        int lo = 0;
        int hi = m;
        while (lo < hi) {
            int mid = (hi + lo) / 2;
            bool poss = true;
            vector<vector<pair<int, int>>> back(n, vector<pair<int, int>>());
            for (int i = 0; i <= mid; i++) {
                int s = paths[i].s;
                int end = paths[i].t;
                int w = paths[i].w;
                back[end].push_back({s, w});
            }
            vector<long long> maxAt(n);
            maxAt[0] = b[0];
            for (int i = 1; i < n; i++) {
                for (pair<int, int> k: back[i]) {
                    if (k.second <= maxAt[k.first]) {
                        maxAt[i] = max(maxAt[i], maxAt[k.first] + b[i]);
                    }
                }
            }

            if (maxAt[n-1] != 0) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        if (lo == m) {
            cout << -1 << "\n";
        }
        else {
            cout << paths[lo].w << "\n";
        }
    }
}
