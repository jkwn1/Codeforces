#include <bits/stdc++.h>
using namespace std;

struct segTreeMin {
    vector<int> tree;
    int n;

    segTreeMin(int size) {
        n = size;
        tree = vector<int>(4 * n, n + 1);
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = min(tree[node], val);
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid) {
                update(2 * node, start, mid, idx, val);
            } else {
                update(2 * node + 1, mid + 1, end, idx, val);
            }
            tree[node] = min(tree[2 * node], tree[2 * node + 1]);
        }
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            return n + 1;
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        return min(query(2 * node, start, mid, l, r),
                   query(2 * node + 1, mid + 1, end, l, r));
    }

    void update(int idx, int val) {
        update(1, 1, n, idx, val);
    }

    int minimum(int l, int r) {
        if (l >= r) return n + 1;
        return query(1, 1, n, l, r - 1);
    }
};

struct segTreeRMQ {
    vector<long long> tree;
    int n;

    segTreeRMQ(vector<int>& arr) {
        n = arr.size();
        tree = vector<long long>(2*n);
        for (int i = 0; i < n; i++) {
            tree[n + i] = arr[i];
        }
        for (int i = n - 1; i > 0; i--) {
            tree[i] = min(tree[2*i], tree[2*i + 1]);
        }
    }

    long long minimum(int l, int r) {
        long long s = LLONG_MAX;
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l & 1) s = min(s, tree[l++]);
            if (r & 1) s = min(s, tree[--r]);
        }
        return s;
    }
};

vector<int> findLeftmostDecreasingSubseq(vector<int>& arr) {
    int n = arr.size();
    vector<int> leftmost(n, n);
    vector<int> closestLeft(n, n);

    vector<pair<int, int>> valueIndexPairs;
    for (int i = 0; i < n; i++) {
        valueIndexPairs.push_back({arr[i], i});
    }
    sort(valueIndexPairs.begin(), valueIndexPairs.end());

    set<int> processedIndices;

    for (int k = 0; k < n; k++) {
        int i = valueIndexPairs[k].second;

        auto it = processedIndices.upper_bound(i);
        if (it != processedIndices.end()) {
            closestLeft[i] = *it;
        }

        processedIndices.insert(i);
    }

    segTreeMin segTree(n);

    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] > 1) {
            int minClosestLeft = segTree.minimum(1, arr[i]);
            if (minClosestLeft < n) {
                leftmost[i] = minClosestLeft;
            }
        }
        
        segTree.update(arr[i], closestLeft[i]);
    }

    return leftmost;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int t1 = 0; t1 < t; t1++) {
        int n;
        cin >> n;
        int q;
        cin >> q;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        vector<int> leftmost = findLeftmostDecreasingSubseq(arr);

        segTreeRMQ querySegTree(leftmost);
        for (int i = 0; i < q; i++) {
            int l, r;
            cin >> l >> r;
            l--;
            r--;

            if (r - l + 1 < 3) {
                cout << "YES\n";
                continue;
            }

            long long minLeftmost = querySegTree.minimum(l, r - 1);

            if (minLeftmost <= r) {
                cout << "NO\n";
            } else {
                cout << "YES\n";
            }
        }
    }
}