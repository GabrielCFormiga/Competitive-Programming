/**
* @file K_query.cpp
* @author GabrielCampelo
* Created on 2026-03-09 at 13:39:44
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

template <typename T>
struct CoordinateCompression {
    vector<T> d;

    CoordinateCompression(const vector<T> &vec) {
        d = vec;
        sort(d.begin(), d.end());
        d.erase(unique(d.begin(), d.end()), d.end());
    }

    int get_id(T x) {
        return lower_bound(d.begin(), d.end(), x) - d.begin();
    }

    T get_value(int id) {
        return d[id];
    }
};

struct node {
    vector<int> vals;
    node() {
        vals.clear();
    }
    node(vector<int> vals) : vals(vals) {
    }
    node operator + (const node &rhs) const {
        // implement merge here
        vector<int> ret;
        int i = 0, j = 0;
        while (i < vals.size() || j < rhs.vals.size()) {
            if (i < vals.size() && j < rhs.vals.size()) {
                if (vals[i] < rhs.vals[j]) ret.pb(vals[i++]);
                else ret.pb(rhs.vals[j++]);
            } else {
                while (i < vals.size()) ret.pb(vals[i++]);
                while (j < rhs.vals.size()) ret.pb(rhs.vals[j++]);
            }
        }

        return node(ret);
        // return node(val op rhs.val);
    }
};

struct SegTree {
    int n;
    vector<node> t;

    SegTree(int n) : n(n) {
        t.assign(4 * n, node());
    }

    SegTree(vector<int> &a) {
        n = a.size();
        t.resize(4 * n);
        build(1, 0, n - 1, a);
    }

    void build(int pos, int l, int r, vector<int> &a) {
        if(l == r) {
            t[pos] = node({a[l]});
            return; 
        }
        int m = (l + r) / 2;
        build(2 * pos, l, m, a);
        build(2 * pos + 1, m + 1, r, a);
        t[pos] = t[2 * pos] + t[2 * pos + 1];
    }

    void update(int i, int val, int pos, int l, int r) {
        if(l == r) {
            t[pos] = node({val});
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

    int get_qtd(node v, int k) {
        auto it = upper_bound(v.vals.begin(), v.vals.end(), k);
        return v.vals.end() - it;
    }

    int query(int i, int j, int k, int pos, int l, int r) {
        if(j < l || r < i) return 0;
        if(i <= l && r <= j) return get_qtd(t[pos], k);
        int m = (l + r) / 2;
        return query(i, j, k, 2 * pos, l, m) + query(i, j, k, 2 * pos + 1, m + 1, r);
    }
    int query(int i, int j, int k) {
        return query(i, j, k, 1, 0, n - 1);
    }
};


int main() { _
    int n;
    cin >> n;

    vector<int> vec(n);
    vector<int> coords;
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
        coords.pb(vec[i]);
    }

    int q;
    cin >> q;

    vector<tuple<int, int, int>> queries(q);
    for (int i = 0; i < q; i++) {
        int l, r, k;
        cin >> l >> r >> k;
        l--;
        r--;
        coords.pb(k);
        queries[i] = {l, r, k};
    }

    CoordinateCompression<int> cc(coords);
    for (int i = 0; i < n; i++) {
        vec[i] = cc.get_id(vec[i]);
    }

    SegTree seg(vec);

    for (auto &tp : queries) {
        int l = get<0>(tp);
        int r = get<1>(tp);
        int k = get<2>(tp);
        k = cc.get_id(k);
        cout << seg.query(l, r, k) << endl;
    }

    return 0;
}