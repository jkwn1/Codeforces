#include <bits/stdc++.h>
using namespace std;


int main() {
    int t;
    cin >> t;

    // digit -> 81 at most
    // digit -> 16 at most
    // -8 -> 1 ... 8
    // -4 -> 1 ... 4
    // -2 -> 1 ... 2
    // -1 -> 1
    // add (n-1);

    for (int t1 = 0; t1 < t; ++t1) {
        int n;
        int var;
        cin >> n;
        cout << "digit" << endl;
        cout.flush();
        cin >> var;

        cout << "digit" << endl;
        cout.flush();
        cin >> var;

        cout << "add -8" << endl;
        cout.flush();
        cin >> var;

        cout << "add -4" << endl;
        cout.flush();
        cin >> var;

        cout << "add -2" << endl;
        cout.flush();
        cin >> var;

        cout << "add -1" << endl;
        cout.flush();
        cin >> var;

        string in = "add ";
        in += to_string((n-1));
        cout << in << endl;
        cout.flush();
        cin >> var;

        cout << "!" << endl;
        cout.flush();
        cin >> var;
    }
}