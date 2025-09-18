
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int t1 = 0; t1 < t; ++t1) {
        int n;
        cin >> n;

        vector<string> grid = {"0"};
        for (int i = 1; i < n; i++) {
            vector<string> grid2(i+1, "");
            if (i % 2 != 0) {
                int maxVal = (i+1) * (i+1) - 1;
                for (int j = 0; j < i; j++) {
                    grid2[j] = grid[j] + " " + to_string(maxVal - j);
                }
                grid2[i] = to_string(i * i);
                for (int j = 1; j <= i; j++) {
                    grid2[i] += " " + to_string(i * i + j);
                }
            }
            else {
                grid2[0] = to_string(i * i + i);
                for (int j = i-1; j >= 0; j--) {
                    grid2[0] += " " + to_string(i * i + j);
                }
                for (int j = 1; j <= i; j++) {
                    grid2[j] = to_string(i * i + i + j) + " " + grid[j-1];
                }
            }
            grid = grid2;
        }

        for (int i = 0; i < n; i++) {
            cout << grid[i] << "\n";
        }
    }
}