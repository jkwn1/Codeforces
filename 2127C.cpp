#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    for (int t1 = 0; t1 < t; t1++) {
        int n; cin >> n;
        int k; cin >> k;
        long long sum = 0;
        vector<pair<int, int>> pairs(n);
        for (int i = 0; i < n; i++) {
            cin>> pairs[i].first;
        }
        for (int i = 0; i < n; i++) {
            cin >> pairs[i].second;
            if (pairs[i].first > pairs[i].second) {
                int temp = pairs[i].first;
                pairs[i].first = pairs[i].second;
                pairs[i].second = temp;
            }
            sum += pairs[i].second - pairs[i].first;
        }
        sort(pairs.begin(), pairs.end());
        int secondMax = pairs[0].second;
        bool poss = false;
        int minMinus = 1000000000;
        for (int i = 1; i < n; i++) {
            if (pairs[i].first < secondMax) {
                poss = true;
            }
            minMinus = min(minMinus, pairs[i].first - secondMax);
            secondMax = max(secondMax, pairs[i].second);
        }
        if (poss) {
            cout << sum << "\n";
        }
        else {
            cout << sum + minMinus * 2 << "\n";
        }
    }
}
