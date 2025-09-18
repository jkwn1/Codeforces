// Codeforces Round 1045 (Div. 2) C
// https://codeforces.com/contest/2134/problem/C
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    for (int t1 = 0; t1 < t; t1++) {
        int n; cin >> n;
        vector<int> A(n);
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        long long sum = 0;
        int prevLimit = -1;
        if (A[1] < A[0]) {
            sum += A[0] - A[1];
            prevLimit = 0;
        }
        else {
            prevLimit = A[1] - A[0];
        }
        for (int i = 2; i < n; i+=2) {
            if (i+1 == n) {
                if (A[i] > prevLimit) {
                    sum += A[i] - prevLimit;
                }
            }
            else {
                int currLimit = min(prevLimit, A[i+1]);
                if (A[i] < currLimit) {
                    currLimit = A[i];
                }
                sum += A[i] - currLimit;
                prevLimit = A[i+1] - currLimit;
            }
        }
        cout << sum << "\n";
    }
}
