// Order Capital Round 1 (Codeforces Round 1038, Div. 1 + Div. 2) C
// https://codeforces.com/contest/2122/problem/C
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    for (int t0 = 0; t0 < t; t0++) {
        int n; cin >> n;
        vector<pair<int, int>> x(n);
        vector<pair<int, int>> y(n);
        vector<pair<int, int>> pairs(n);
        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            pairs[i] = {a, b};
            x[i] = {a, i};
            y[i] = {b, i};
        }
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());

        vector<int> pairs00;
        vector<int> pairs01;
        vector<int> pairs10;
        vector<int> pairs11;
        vector<int> pairsOrdered(n, 0);
        
        for (int i = n/2; i < n; i++) {
            pairsOrdered[x[i].second] += 1;
            pairsOrdered[y[i].second] += 10;
        }
        for (int i = 0; i < n; i++) {
            if (pairsOrdered[i] % 10 == 0) {
                if (pairsOrdered[i] < 10) {
                    pairs00.push_back(i+1);
                }
                else {
                    pairs01.push_back(i+1);
                }
            }
            else {
                if (pairsOrdered[i] < 10) {
                    pairs10.push_back(i+1);
                }
                else {
                    pairs11.push_back(i+1);
                }
            }
        }

        int pairs00Ind = 0;
        int pairs01Ind = 0;
        int pairs10Ind = 0;
        int pairs11Ind = 0;
        while (pairs00Ind < pairs00.size() && pairs11Ind < pairs11.size()) {
            cout << pairs00[pairs00Ind] << " " << pairs11[pairs11Ind] << "\n";
            pairs00Ind ++;
            pairs11Ind ++;
        }
        while (pairs01Ind < pairs01.size() && pairs10Ind < pairs10.size()) {
            cout << pairs01[pairs01Ind] << " " << pairs10[pairs10Ind] << "\n";
            pairs01Ind ++;
            pairs10Ind ++;
        }
    }
}
