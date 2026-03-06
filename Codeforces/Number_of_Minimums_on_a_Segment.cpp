/**
* @file Number_of_Minimums_on_a_Segment.cpp
* @author GabrielCampelo
* Created on 2026-03-06 at 15:30:08
*/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()

using namespace std;

using ll = long long;
using llu = unsigned long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct node {
    pair<ll, int> val;
    node() {
        val.first = INF;
        val.second = 1;
    }
    node(pair<ll, int> val) : val(val) {
    }
    node operator + (const node &rhs) const {
        if (val.first < rhs.val.first) {
            return node(val);
        } else if (val.first > rhs.val.first) {
            return node(rhs.val);
        } else {
            return node({val.first, val.second + rhs.val.second});
        }
    }
};

struct SegTree {
    int n;
    vector<node> t;

    SegTree(vector<int> &a) {
        n = a.size();
        t.resize(4 * n);
        build(1, 0, n - 1, a);
    }

    void build(int pos, int l, int r, vector<int> &a) {
        if(l == r) {
            t[pos] = node({a[l], 1});
            return; 
        }
        int m = (l + r) / 2;
        build(2 * pos, l, m, a);
        build(2 * pos + 1, m + 1, r, a);
        t[pos] = t[2 * pos] + t[2 * pos + 1];
    }

    void update(int i, int val, int pos, int l, int r) {
        if(l == r) {
            t[pos] = node({val, 1});
            return;
        }
        int m = (l + r) / 2;
        if(i <= m) update(i, val, 2 * pos, l, m);
        else update(i, val, 2 * pos + 1, m + 1, r);
        t[pos] = t[2 * pos] + t[2 * pos + 1];
    }
    void update(int i, int val) { 
        update(i, val, 1, 0, n - 1);
    }

    node query(int i, int j, int pos, int l, int r) {
        if(j < l || r < i) return node();
        if(i <= l && r <= j) return t[pos];
        int m = (l + r) / 2;
        return query(i, j, 2 * pos, l, m) + query(i, j, 2 * pos + 1, m + 1, r);
    }
    node query(int i, int j) {
        return query(i, j, 1, 0, n - 1);
    }
};

int main() { _
    int n, q;
    cin >> n >> q;
    
    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    SegTree seg(vec);

    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int i, v;
            cin >> i >> v;
            seg.update(i, v);
        } else {
            int l, r;
            cin >> l >> r;
            cout << seg.query(l, r - 1).val.first << ' ' << seg.query(l, r - 1).val.second << endl;
        }
    }

    return 0;
}