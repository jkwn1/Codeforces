// Squarepoint Challenge (Codeforces Round 1055, Div. 1 + Div. 2) A
// https://codeforces.com/contest/2152/problem/A

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for(int t1 = 0; t1 < t; t1++) {
        int n;
        cin >> n;
        set<int> distinct;
        int maxA = 0;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            distinct.insert(a);
        }
        cout << 1 + 2 * (distinct.size() - 1) << "\n";
    }
}
