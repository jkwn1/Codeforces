#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    for (int t1 = 0; t1 < t; t1++) {
        int n; cin >> n;
        vector<bool> a(101, false);
        bool poss = false;
        for (int i = 0; i < n; i++) {
            int a1; cin >> a1;
            if (a[a1]) {
                poss = true;
            }
            a[a1] = true;
        }
        if (poss) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}