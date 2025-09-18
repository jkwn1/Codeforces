// Codeforces Round 1035 (Div. 2) A
// https://codeforces.com/contest/2119/problem/A
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int t1 = 0; t1 < t; t1++) {
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        if (a > b) {
            if (a == b+1) {
                if (a % 2 == 1) {
                    cout << y << "\n";
                }
                else {
                    cout << -1 << "\n";
                }
            }
            else {
                cout << -1 << "\n";
            }
        }
        else {
            if (x > y) {
                if (a % 2 == 1) {
                    if (b % 2 == 1) {
                        long long ans = ((b - a) / 2);
                        ans *= (x+y);
                        cout << ans << "\n";
                    }
                    else {
                        long long ans = (b - a - 1) / 2;
                        ans *= (x+y);
                        ans += x;
                        cout << ans << "\n";
                    }
                }
                else {
                    if (b % 2 == 0) {
                        long long ans = ((b - a) / 2);
                        ans *= (x+y);
                        cout << ans << "\n";
                    }
                    else {
                        long long ans = (b - a - 1) / 2;
                        ans *= (x+y);
                        ans += y;
                        cout << ans << "\n";
                    }
                }
            }
            else {
                long long ans = x;
                ans *= (b-a);
                cout << ans << "\n";
            }
        }
    }
}
