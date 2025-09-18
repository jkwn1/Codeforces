// Codeforces Round 1020 (Div. 3) D
// https://codeforces.com/contest/2106/problem/D
#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;

    for (int t1 = 0 ; t1 < t ; t1++) {
        int n, m;
        cin >> n >> m;

        vector<int> a(n);
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }
        vector<int> forward(m, -1);
        vector<int> backward(m, -1);
        int aIndex = 0;
        int bIndex = 0;
        while (aIndex < n && bIndex < m) {
            if (a[aIndex] >= b[bIndex]) {
                forward[bIndex] = aIndex;
                bIndex++;
            }
            aIndex++;
        }

        if (bIndex == m) {
            cout << 0 << "\n";
            continue;
        }
        
        aIndex = n-1;
        bIndex = m-1;
        while (aIndex >= 0 && bIndex >= 0) {
            if (a[aIndex] >= b[bIndex]) {
                backward[bIndex] = aIndex;
                bIndex--;
            }
            aIndex--;
        }
        int ans = 1000000001;
        if (backward[1] != -1) {
            ans = min(ans, b[0]);
        }
        if (forward[m-2] != -1) {
            ans = min(ans, b[m-1]);
        }
        for (int i = 1; i <= m-2; i++) {
            if (forward[i-1] != -1 && backward[i+1] != -1) {
                if (forward[i-1] < backward[i+1]) {
                    ans = min(ans, b[i]);
                }
            }
        }
        if (ans == 1000000001) {
            cout << -1 << "\n";
        }
        else cout << ans << "\n";
    }

}
