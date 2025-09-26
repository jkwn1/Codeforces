#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;
const long long MAXN = 2*1e5;

long long fac[MAXN + 1];
long long inv[MAXN + 1];

long long exp(long long x, long long n) {
    x %= MOD;
    long long res = 1;
    while (n > 0) {
        if (n % 2 == 1) res = res * x % MOD;
        x = x * x % MOD;
        n /= 2;
    }
    return res;
}

long long choose(long long n, long long r) {
    return fac[n] * inv[r] % MOD * inv[n - r] % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fac[0] = 1;
    for (int i = 1; i <= MAXN; i++) { fac[i] = fac[i - 1] * i % MOD; }
    inv[MAXN] = exp(fac[MAXN], MOD - 2);
    for (int i = MAXN; i >= 1; i--) { inv[i - 1] = inv[i] * i % MOD; }

    int t; cin >> t;
    for (int t1 = 0; t1 < t; t1++) {
        int n;
        cin >> n;
        vector<int> arr(n);
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            sum += arr[i];
        }
        if (sum != n) {
            cout << "0\n";
            continue;
        }
        int currSum = 0;
        int currOpen = 0;
        long long ans = 1;
        bool poss = true;
        int toRemove = 0;
        for (int i = (n-1)/2; i >= 0; i--) {
            currSum += arr[i];
            currOpen = arr[i];
            toRemove += 2;
            if (2 * i == n - 1) {
                toRemove--;
            }
            if (currOpen > toRemove) {
                poss = false;
                break;
            }
            ans = (ans * choose(toRemove, toRemove - currOpen)) % MOD;
            toRemove -= currOpen;
        }
        if (poss && currSum == n) {
            cout << ans << "\n";
        }
        else {
            cout << "0\n";
        }
    }
}