#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    for (int t1 = 0; t1 < t; t1++) {
        int x; cin >> x;
        int start = 1;
        int count = 3;
        while (true) {
            if (start >= x) {
                break;
            }
            else {
                start = 2 * start + 1;
                count += 2;
            }
        }
        cout << count << "\n";
    }
}
