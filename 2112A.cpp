#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int t1 = 0; t1 < t; t1++) {
        int a, x, y;
        cin >> a >> x >> y;
        if (a < min(x, y)) {
            cout << "YES" << "\n";
        }
        else if (a > max(x, y)) {
            cout << "YES" << "\n";
        }
        else {
            cout << "NO" << "\n";
        }
    }
}