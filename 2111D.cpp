// Educational Codeforces Round 179 (Rated for Div. 2) D
// https://codeforces.com/contest/2111/problem/D
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    for (int t1 = 0; t1 < t; t1++) {
        int n, m; cin >> n >> m;
        vector<int> classes(m);
        for (int i = 0; i < m; i++) {
            cin >> classes[i];
        }
        sort(classes.begin(), classes.end());
        for (int i = 0; i < (n/2); i++) {
            cout << to_string(classes[i]) << " " << to_string(classes[m-1-i]) << " " << to_string(classes[i]) << " " << to_string(classes[m-1-i]) << " " << to_string(classes[i]) << " " << to_string(classes[m-1-i]);
            cout << "\n";
        }
        for (int i = (n/2); i < n; i++) {
            int index = i - (n/2);
            cout << to_string(classes[m-1-index]) << " " << to_string(classes[index]) << " " << to_string(classes[m-1-index]) << " " << to_string(classes[index]) << " " << to_string(classes[m-1-index]) << " " << to_string(classes[index]);
            cout << "\n";
        }
    }
}
