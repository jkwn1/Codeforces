// Educational Codeforces Round 183 (Rated for Div. 2) D
// https://codeforces.com/contest/2145/problem/D

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int t1 = 0; t1 < t; t1++) {
        int n, k;
        cin >> n >> k;
        int goal = n * (n-1) / 2 - k;
        vector<int> minCount(goal+1, -1);
        vector<vector<int>> vecForMin(goal+1, vector<int>());
        minCount[0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 2; j <= n; j++) {
                for (int g = 0; g <= goal; g++) {
                    if (g + j * (j-1) / 2 <= goal) {
                        if (minCount[g + j * (j-1) / 2] == -1 || minCount[g + j * (j-1) / 2] > minCount[g] + j) {
                            minCount[g + j * (j-1) / 2] = minCount[g] + j;
                            vecForMin[g + j * (j-1) / 2] = vecForMin[g];
                            vecForMin[g + j * (j-1) / 2].push_back(j);
                        }
                    }
                }
            }
        }
        if (minCount[goal] != -1 && minCount[goal] <= n) {
            int curr = 1;
            string ans;
            for (int i : vecForMin[goal]) {
                string toAdd;
                for (int j = 0; j < i; j++) {
                    toAdd += to_string(curr) + " ";
                    curr++;
                }
                ans = toAdd + ans;
            }
            string toAdd;
            while (curr <= n) {
                toAdd = to_string(curr) + " " + toAdd;
                curr++;
            }
            ans = toAdd + ans;
            cout << ans << "\n";
        }
        else {
            cout << "0\n";
        }
    }
}
