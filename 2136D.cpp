#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int t1 = 0; t1 < t; t1++) {
        int n; cin >> n;
        long long closestXPP;
        long long closestYPP;
        long long closestMPP = 4000000000;
        long long closestXPN;
        long long closestYPN;
        long long closestMPN = 4000000000;
        for (int i = 0; i < n; i++) {
            long long x, y;
            cin >> x >> y;
            long long m1 = (1000000000-x) + (1000000000-y);
            long long m2 = (1000000000-x) + (y+1000000000);
            if (m1 < closestMPP) {
                closestMPP = m1;
                closestXPP = x;
                closestYPP = y;
            }
            if (m2 < closestMPN) {
                closestMPN = m2;
                closestXPN = x;
                closestYPN = y;
            }
        }
        long long s;
        cout << "? U " << 1000000000 << endl;
        cout.flush();
        cin >> s;
        cout << "? U " << 1000000000 << endl;
        cout.flush();
        cin >> s;
        cout << "? R " << 1000000000 << endl;
        cout.flush();
        cin >> s;
        cout << "? R " << 1000000000 << endl;
        cout.flush();
        cin >> s;
        long long topD = s;

        cout << "? D " << 1000000000 << endl;
        cout.flush();
        cin >> s;
        cout << "? D " << 1000000000 << endl;
        cout.flush();
        cin >> s;
        cout << "? D " << 1000000000 << endl;
        cout.flush();
        cin >> s;
        cout << "? D " << 1000000000 << endl;
        cout.flush();
        cin >> s;
        long long bottomD = s;

        long long a = (long long) ((topD + bottomD + closestXPP+closestYPP+closestXPN-closestYPN-4e9) / 2);
        long long b = (long long) ((topD - bottomD + closestXPP+closestYPP-closestXPN+closestYPN+4e9) / 2);

        cout << "! " << to_string((long long) (a - 2e9)) << " " << to_string((long long) (b - 2e9)) << endl;
        cout.flush();
    }
}