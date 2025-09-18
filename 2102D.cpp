#include <bits/stdc++.h>
using namespace std;

struct segTreeSum {
    vector<int> tree; int n;

    segTreeSum(int size) {
        n = size;
        tree = vector<int>(2*size);
    }

    void build() {
        for (int i = n - 1; i > 0; i--) {
            tree[i] = tree[i<<1] + tree[i<<1|1];
        }
    }

    void update(int node, int value) {  // set value at node
        for (tree[node += n] += value; node > 1; node /= 2) {
            tree[node/2] = tree[node] + tree[node^1];
        }
    }

    int sum(int l, int r) {  // sum on interval [l, r)
        int s = 0;
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l & 1) s += tree[l++];
            if (r & 1) s += tree[--r];
        }
        return s;
    }
};

int main() {
    int t;
    cin >> t;
    for (int t1 = 0; t1 < t; ++t1) {
        int n;
        cin >> n;

        vector<int> even;
        vector<int> odd;

        int invE = 0;
        int invO = 0;
        segTreeSum stsE = segTreeSum(n);
        segTreeSum stsO = segTreeSum(n);
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            if (i % 2 == 0) {
                even.push_back(a);
                invE += stsE.sum(a, n);
                stsE.update(a-1, 1);
            }
            else {
                odd.push_back(a);
                invO += stsO.sum(a, n);
                stsO.update(a-1, 1);
            }
        }

        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end());
        if ((invE + invO) % 2 != 0) {
            if (n % 2 == 0) {
                int temp = odd[odd.size() - 2];
                odd[odd.size() - 2] = odd[odd.size() - 1];
                odd[odd.size() - 1] = temp;
            }
            else {
                int temp = even[even.size() - 2];
                even[even.size() - 2] = even[even.size() - 1];
                even[even.size() - 1] = temp;
            }
        }

        string res = "";
        int oddIndex = 0;
        for (int k: even) {
            res += to_string(k) + " ";
            if (oddIndex < odd.size()) {
                res += to_string(odd[oddIndex]) + " ";
                oddIndex++;
            }
        }
        cout << res + "\n";
    }
}
