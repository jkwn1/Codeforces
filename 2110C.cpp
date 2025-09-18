#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int t1 = 0; t1 < t; t1++) {
        int n;
        cin >> n;
        vector<int> d(n+1);
        for (int i = 1; i < n+1; i++) {
            cin >> d[i];
        }
        vector<pair<int, int>> obstacles(n+1);
        for (int i = 1; i < n+1; i++) {
            cin >> obstacles[i].first;
            cin >> obstacles[i].second;
        }
        vector<pair<int, int>> bounds(n+1);

        bounds[0] = {0, 0};

        if (d[1] == 0) {
            bounds[1] = {0, 0};
        }
        else if (d[1] == 1) {
            bounds[1] = {1, 1};
        }
        else {
            bounds[1] = {0, 1};
        }
        if (bounds[1].first > obstacles[1].second || bounds[1].second < obstacles[1].first) {
            cout << -1 << "\n";
            continue;
        }
        bounds[1] = {max(bounds[1].first, obstacles[1].first), min(bounds[1].second, obstacles[1].second)};


        bool poss = true;
        for (int i = 2; i < n+1; i++) {
            if (d[i] == 0) {
                bounds[i] = {bounds[i-1].first, bounds[i-1].second};
            }
            else if (d[i] == 1) {
                bounds[i] = {bounds[i-1].first+1, bounds[i-1].second+1};
            }
            else {
                bounds[i] = {bounds[i-1].first, bounds[i-1].second+1};
            }
            if (bounds[i].first > obstacles[i].second || bounds[i].second < obstacles[i].first) {
                poss = false;
                break;
            }

            bounds[i] = {max(bounds[i].first, obstacles[i].first), min(bounds[i].second, obstacles[i].second)};
        }
        if (!poss) {
            cout << -1 << "\n";
            continue;
        }
        vector<int> val(n+1);
        val[n] = bounds[n].second;
        for (int i = n-1; i >= 0; i--) {
            if (d[i+1] == 0) {
                val[i] = val[i+1];
            }
            else if (d[i+1] == 1) {
                val[i] = val[i+1] - 1;
            }
            else {
                val[i] = min(val[i+1], bounds[i].second);
            }
        }

        cout << val[1] << " ";
        for (int i = 2; i < n+1; i++) {
            int a = val[i] - val[i-1];
            cout << a << " ";
        }
        cout << "\n";
    }
}
