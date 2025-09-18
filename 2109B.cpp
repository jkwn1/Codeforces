// Codeforces Round 1025 (Div. 2) B
// https://codeforces.com/contest/2109/problem/B
#include <bits/stdc++.h>
using namespace std;


int main() {

    vector<int> pows;
    pows.push_back(1);
    int curr = 1;
    while (curr <= 1000000000) {
        pows.push_back(curr *= 2);
    }

    int t;
    cin >> t;

    for (int t1 = 0; t1 < t; ++t1) {
        int n, m, a, b;
        cin >> n >> m >> a >> b;

        // possibilities are:
        // a, m ||| n, b ||| n-a+1, m ||| n, m-b+1

        int cutsA = distance(pows.begin(), lower_bound(pows.begin(), pows.end(), a));
        int cutsM = distance(pows.begin(), lower_bound(pows.begin(), pows.end(), m));
        int cutsB = distance(pows.begin(), lower_bound(pows.begin(), pows.end(), b));
        int cutsN = distance(pows.begin(), lower_bound(pows.begin(), pows.end(), n));
        int cutsNA1 = distance(pows.begin(), lower_bound(pows.begin(), pows.end(), n - a + 1));
        int cutsMB1 = distance(pows.begin(), lower_bound(pows.begin(), pows.end(), m - b + 1));

        int ans = min(cutsA + cutsM, cutsN + cutsB);
        ans = min(ans, cutsNA1 + cutsM);
        ans = min(ans, cutsN + cutsMB1);
        cout << (ans + 1) << "\n";
    }
}
