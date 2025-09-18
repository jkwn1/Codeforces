#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;

    for (int t1 = 0 ; t1 < t ; t1++) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);

        int largest = -1;
        int smallest = k+1;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            largest = max(largest, a[i]);
            smallest = min(smallest, a[i]);
        }

        bool poss = true;
        int x = -1;
        int countNeg1 = 0;
        for (int i = 0; i < n; i++) {
            int b;
            cin >> b;
            if (b == -1) {
                countNeg1++;
            }
            else {
                if (x == -1) {
                    x = a[i] + b;
                    if (x < largest || x > k + smallest) {
                        poss = false;
                    }
                }
                else {
                    if (a[i] + b != x) {
                        poss = false;
                    }
                }
            }
        }

        if (poss) {
            if (countNeg1 == n) {
                cout << k - largest + smallest + 1 << "\n";
            }
            else {
                cout << 1 << "\n";
            }
        }
        else {
            cout << 0 << "\n";
        }
    }

}