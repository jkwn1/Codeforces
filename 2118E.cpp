// Codeforces Round 1030 (Div. 2) E
// https://codeforces.com/contest/2118/problem/E
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    for (int t1 = 0; t1 < t; t1++) {
        int n, m; cin >> n >> m;
        int x = (n+1)/2;
        int y = (m+1)/2;
        cout << to_string(x) << " " << to_string(y) << "\n";
        int maxSquare = min((n-1)/2, (m-1)/2);

        for (int i = 1; i <= maxSquare; i++) {
            cout << to_string(x) << " " << to_string(y+i) << "\n";
            cout << to_string(x) << " " << to_string(y-i) << "\n";
            for (int j = 1; j < i; j++) {
                cout << to_string(x+j) << " " << to_string(y+i) << "\n";
                cout << to_string(x-j) << " " << to_string(y-i) << "\n";
                cout << to_string(x-j) << " " << to_string(y+i) << "\n";
                cout << to_string(x+j) << " " << to_string(y-i) << "\n";
            }

            cout << to_string(x+i) << " " << to_string(y) << "\n";
            cout << to_string(x-i) << " " << to_string(y) << "\n";
            for (int j = 1; j < i; j++) {
                cout << to_string(x+i) << " " << to_string(y+j) << "\n";
                cout << to_string(x-i) << " " << to_string(y-j) << "\n";
                cout << to_string(x+i) << " " << to_string(y-j) << "\n";
                cout << to_string(x-i) << " " << to_string(y+j) << "\n";
            }

            cout << to_string(x-i) << " " << to_string(y+i) << "\n";
            cout << to_string(x-i) << " " << to_string(y-i) << "\n";
            cout << to_string(x+i) << " " << to_string(y-i) << "\n";
            cout << to_string(x+i) << " " << to_string(y+i) << "\n";
        }
        if (n > m) {
            for (int i = maxSquare+1; i <= (n-1)/2; i++) {
                cout << to_string(x+i) << " " << to_string(y) << "\n";
                cout << to_string(x-i) << " " << to_string(y) << "\n";
                for (int j = 1; j <= maxSquare; j++) {
                    cout << to_string(x+i) << " " << to_string(y+j) << "\n";
                    cout << to_string(x-i) << " " << to_string(y-j) << "\n";
                    cout << to_string(x+i) << " " << to_string(y-j) << "\n";
                    cout << to_string(x-i) << " " << to_string(y+j) << "\n";
                }
            }
        }
        else if (n < m){
            for (int i = maxSquare+1; i <= (m-1)/2; i++) {
                cout << to_string(x) << " " << to_string(y+i) << "\n";
                cout << to_string(x) << " " << to_string(y-i) << "\n";
                for (int j = 1; j <= maxSquare; j++) {
                    cout << to_string(x+j) << " " << to_string(y+i) << "\n";
                    cout << to_string(x-j) << " " << to_string(y-i) << "\n";
                    cout << to_string(x-j) << " " << to_string(y+i) << "\n";
                    cout << to_string(x+j) << " " << to_string(y-i) << "\n";
                }
            }
        }
        cout << "\n";
    }
}
