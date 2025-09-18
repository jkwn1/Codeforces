#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    for (int t1 = 0; t1 < t; t1++) {
        int n; cin >> n;
        int prev = -1;
        bool poss = true;
        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            if (a == -1) continue;
            if (prev < 0) prev = a;
            else if (prev != a) {
                poss = false;
            }
        }
        if (poss && prev == 0) poss = false;
        cout << (poss ? "YES" : "NO") << endl;
    }
}
