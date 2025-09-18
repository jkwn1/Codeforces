#include <bits/stdc++.h>
using namespace std;

long long fac[100001];
long long inv[100001];

long long exp(long long x, long long n) {
    x %= 1000000007;
    long long res = 1;
    while (n > 0) {
        if (n % 2 == 1) { res = res * x % 1000000007; }
        x = x * x % 1000000007;
        n /= 2;
    }
    return res;
}

void factorial() {
    fac[0] = 1;
    for (int i = 1; i <= 100000; i++) { fac[i] = fac[i - 1] * i % 1000000007; }
}

void inverses() {
    inv[100000] = exp(fac[100000], 1000000005);
    for (int i = 100000; i >= 1; i--) { inv[i - 1] = inv[i] * i % 1000000007; }
}

int main() {
    factorial();
    inverses();
    int t;
    cin >> t;
    for (int t1 = 0; t1 < t; t1++) {
        long long a, b, k;
        cin >> a >> b >> k;
        long long rows = (a-1) * k + 1;
        rows %= 1000000007;
        long long top = 1;
        for (long long i = rows; i > rows - a; i--) {
            top = (top * i) % 1000000007;
        }
        top = (top * inv[a]) % 1000000007;
        top = (top * k) % 1000000007;
        top = (top * (b-1)) % 1000000007;
        top = (top + 1) % 1000000007;

        cout << rows << " " << top << "\n";
    }
}