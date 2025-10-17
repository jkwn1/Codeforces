// Codeforces Round 1057 (Div. 2) A
// https://codeforces.com/contest/2153/problem/A

#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int t1 = 0; t1 < t; t1++) {
        int n; cin >> n;
        vector<int> vec(n+1, 0);
        for (int i = 0; i < n; i++) {
            int b; cin >> b;
            vec[b]++;
        }
        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (vec[i] >= 1) {
                count++;
            }
        }
        cout << count << "\n";
    }
}
