// Codeforces Round 1046 (Div. 2) A
// https://codeforces.com/contest/2136/problem/A
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int t1 = 0; t1 < t; t1++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        bool poss= true;
        if (a > b) {
            if ((a - 2) > b * 2) {
                poss = false;
            }
        }
        else if (a < b){
            if ((b - 2) > a * 2) {
                poss = false;
            }
        }
        c -= a;
        d -= b;
        if (c > d) {
            if ((c - 2) > d * 2) {
                poss = false;
            }
        }
        else if (c < d){
            if ((d - 2) > c * 2) {
                poss = false;
            }
        }
        if (poss) {
            cout << "YES" << "\n";
        }
        else {
            cout << "NO" << "\n";
        }
    }
}
