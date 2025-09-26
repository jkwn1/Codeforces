// Codeforces Round 1053 (Div. 2) 
// https://codeforces.com/contest/2151/problem/A
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    for (int t1 = 0; t1 < t; t1++) {
        int n, m;
        cin >> n >> m;
        vector<int> arr(m);
        for (int i = 0; i < m; i++) {
            cin >> arr[i];
        }
        bool poss = true;
        int flips = 0;
        int lastEnd = -1;
        for (int i = 1; i < m; i++) {
            if (arr[i] != arr[i-1]+1) {
                if (arr[i] == 1) {
                    flips++;
                    if (lastEnd == -1) {
                        lastEnd = arr[i-1];
                    }
                    else {
                        if (lastEnd + 1 == arr[i-1]) {
                            lastEnd++;
                        }
                        else {
                            poss = false;
                            break;
                        }
                    }
                }
                else {
                    poss = false;
                    break;
                }
            }
        }
        if (lastEnd == -1) {
            lastEnd = arr[m-1];
        }
        else {
            if (lastEnd + 1 >= arr[m-1]) {
                lastEnd++;
            }
            else {
                poss = false;
            }
        }

        if (poss) {
            if (lastEnd <= n) {
                if (flips == 0) {
                    cout << 1 + n - lastEnd << "\n";
                }
                else {
                    cout << 1 << "\n";
                }
            }
            else {
                cout << "0\n";
            }
        }
        else {
            cout << "0\n";
        }
    }
}
