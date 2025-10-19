// Codeforces Round 1060 (Div. 2) C1
// https://codeforces.com/contest/2154/problem/C1

#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    int limit = 2e5+1;
    vector<bool> isPrime(limit, true);
    isPrime[0] = isPrime[1] = false;
    vector<int> LPF(limit, 1);

    vector<int> primes;
    int size = 0;
    map<int, int> primeToIndex;
    for (int p = 2; p*p <= limit; p++) {
        if (isPrime[p]) {
            for (int i = p * p; i < limit; i += p) {
                isPrime[i] = false;
                LPF[i] = p;
            }
        }
    }
    for (int p = 2; p <= limit; p++) {
        if (isPrime[p]) {
            LPF[p] = p;
            primes.push_back(p);
            primeToIndex.insert({p, size});
            size++;
        }
    }
    for (int t1 = 0; t1 < t; t1++) {
        int n;
        cin >> n;
        vector<int> a(n);
        int p = (int) primes.size();
        vector<int> counts(p, 0);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) {
            int a0 = a[i];
            while (a0 > 1) {
                int p1 = LPF[a0];
                while (a0 % p1 == 0) {
                    a0 /= p1;
                }
                counts[primeToIndex[p1]]++;
            }
            int b;
            cin >> b;
        }
        int ans = -1;
        for (int i = 0; i < p; i++) {
            if (counts[i] > 1) {
                ans = 0;
                break;
            }
        }
        if (ans == 0) {
            cout << 0 << "\n";
            continue;
        }
        if (counts[0] != 0) {
            cout << 1 << "\n";
            continue;
        }

        bool done = false;
        for (int i = 0; i < n; i++) {
            int a0 = a[i]+1;
            while (a0 > 1) {
                int p1 = LPF[a0];
                if (a0 % p1 == 0 && counts[primeToIndex[p1]] == 1) {
                    done = true;
                    ans = 1;
                    break;
                }
                while (a0 % p1 == 0) {
                    a0 /= p1;
                }
            }
            if (done) break;
        }
        if (done) {
            cout << 1 << "\n";
        }
        else {
            cout << 2 << "\n";
        }
    }
}
