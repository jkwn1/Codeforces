#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    string input1 = "? 100000";
    for (int i = 0; i < 100000; i++) {
        input1 += " 1";
    }
    for (int t1 = 0; t1 < t; t1++) {
        cout << input1 << endl;
        cout.flush();
        int k;
        cin >> k;
        if (k == 1) {
            cout << "! 100000" << endl;
            cout.flush();
            continue;
        }
        int lowerBound = (100000 + k - 1) / k;
        int upperBound = (100000 - 1) / (k-1);
        if (lowerBound == upperBound) {
            cout << "! " << to_string(upperBound) << endl;
            cout.flush();
            continue;
        }
        string input2 = "? " + to_string(2 * (upperBound - lowerBound));
        for (int i = 1; i <= upperBound - lowerBound; i++) {
            input2 += " " + to_string(lowerBound);
            input2 += " " + to_string(i);
        }
        cout << input2 << endl;
        cout.flush();
        int l;
        cin >> l;
        cout << "! " << to_string(2 * upperBound - lowerBound - l) << endl;
        cout.flush();
    }
}