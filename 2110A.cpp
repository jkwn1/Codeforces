#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int t1 = 0; t1 < t; t1++) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        int parFirst = v[0] % 2;
        int parSecond = v[n-1] % 2;
        if (parFirst == parSecond) {
            cout << 0 << "\n";
        }
        else {
            int forwardCount = 0;
            int backwardCount = 0;
            for (int i = 0; i < n-1; i++) {
                if ((v[i] % 2) == parFirst) {
                    forwardCount++;
                }
                else {
                    break;
                }
            }
            for (int i = n-1; i >= 0; i--) {
                if ((v[i] % 2) == parSecond) {
                    backwardCount++;
                }
                else {
                    break;
                }
            }
            cout << min(forwardCount, backwardCount) << "\n";
        }
    }
}
