// Codeforces Round 1048 (Div. 2) A
// https://codeforces.com/contest/2139/problem/A
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int t1 = 0; t1 < t; t1++) {
        int a, b;
        cin >> a >> b;
        if (a % b == 0 && b % a == 0) cout << 0 << "\n";
        else if (a % b == 0 || b % a == 0) cout << 1 << "\n";
        else cout << 2 << "\n";
    }
}
