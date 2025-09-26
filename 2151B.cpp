// Codeforces Round 1053 (Div. 2) B
// https://codeforces.com/contest/2151/problem/B
#include <bits/stdc++.h>
using namespace std;

int findNextWhite(long long pos, const set<int>& black) {
    pos++;

    auto it = black.lower_bound(pos);

    if (it == black.end() || *it > pos) {
        return pos;
    }

    long long current = pos;
    while (it != black.end() && *it == current) {
        current++;
        ++it;
    }

    return current;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    for (int t1 = 0; t1 < t; t1++) {
        int n, m;
        string s;
        cin >> n >> m;
        cin >> s;
        set<int> black;
        for (int i = 0; i < m; i++) {
            int a;
            cin >> a;
            black.insert(a);
        }

        int currPos = 1;
        char prev = 'A';
        for (int i = 0; i < n; i++) {
            if (prev == 'B') {
                currPos = findNextWhite(currPos, black);
                if (s[i] == 'A') {
                    currPos++;
                }
                else {
                    currPos = findNextWhite(currPos, black);
                }
                black.insert(currPos);
            }
            else {
                if (s[i] == 'A') {
                    currPos++;
                }
                else {
                    currPos = findNextWhite(currPos, black);
                }
                black.insert(currPos);
            }
            prev = s[i];
        }
        cout << black.size() << "\n";
        for (int i: black) {
            cout << i << " ";
        }
        cout << "\n";

    }
}
