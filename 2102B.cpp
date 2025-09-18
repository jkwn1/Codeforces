#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int t1 = 0; t1 < t; ++t1) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            v[i] = abs(a);
        }
        int med = v[0];
        sort(v.begin(), v.end());

        int ind = distance(v.begin(), lower_bound(v.begin(), v.end(), med));
        if (ind <= n / 2) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}
