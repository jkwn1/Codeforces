#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    for (int t1 = 0; t1 < t; t1++) {
        int n, q; cin >> n >> q;
        string s; cin >> s;

        vector<int> queries(5); // (c, a), (c, b) + (b, a), (b, c) + (c, a), (c, b), (b, a)
        int openCB = 0;
        int openBC = 0;
        for (int i = 0; i < q; i++) {
            string xS, yS; cin >> xS >> yS;
            int x = xS[0] - 'a';
            int y = yS[0] - 'a';
            if (x == 1) {
                if (y == 0) {
                    if (openCB != 0) {
                        openCB--;
                        queries[1]++;
                    }
                    else {
                        queries[4]++;
                    }
                }
                else if (y == 2) {
                    openBC++;
                }
            }
            else if (x == 2){
                if (y == 0) {
                    if (openBC != 0) {
                        openBC--;
                        queries[2]++;
                    }
                    else {
                        queries[0]++;
                    }
                }
                else if (y == 1) {
                    openCB++;
                }
            }
        }
        queries[3] = openCB;

        string ans = "";
        for (int i = 0; i < n; i++) {
            int currChar = s[i]-'a';
            if (currChar == 0) {
                ans += "a";
            }
            // (c, a), (c, b) + (b, a), (b, c) + (c, a), (c, b), (b, a)
            else if (currChar == 1) {
                if (queries[4] != 0) {
                    ans += "a";
                    queries[4]--;
                }
                else if (queries[1] != 0) {
                    ans += "a";
                    queries[1]--;
                    queries[3]++;
                }
                else if (queries[2] != 0) {
                    ans += "a";
                    queries[2]--;
                }
                else {
                    ans += "b";
                }
            }
            else {
                if (queries[0] != 0) {
                    ans += "a";
                    queries[0]--;
                }
                else if (queries[2] != 0) {
                    ans += "a";
                    queries[2]--;
                }
                else if (queries[1] != 0) {
                    ans += "a";
                    queries[1]--;
                }
                else if (queries[3] != 0) {
                    ans += "b";
                    queries[3]--;
                }
                else {
                    ans += "c";
                }
            }
        }
        cout << ans << "\n";
    }
}
