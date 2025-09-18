#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int l1, b1, l2, b2, l3, b3;
        cin >> l1 >> b1;
        cin >> l2 >> b2;
        cin >> l3 >> b3;
        if ((l2 + l3 == l1) && (b3 == b2) && (b1 + b2 == l1)) {
            cout << "YES" << "\n";
        }
        else if ((b2 + b3 == b1) && (l3 == l2) && (l1 + l2 == b1)) {
            cout << "YES" << "\n";
        }
        else if ((b1 == b2) && (b1 == b3) && (l1 + l2 + l3 == b1)) {
            cout << "YES" << "\n";
        }
        else if ((l1 == l2) && (l1 == l3) && (b1 + b2 + b3 == l1)) {
            cout << "YES" << "\n";
        }
        else {
            cout << "NO" << "\n";
        }
    }
}
