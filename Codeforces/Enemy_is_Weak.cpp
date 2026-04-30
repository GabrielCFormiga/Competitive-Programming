/**
* @file Enemy_is_weak.cpp
* @author GabrielCampelo
* Created on 2026-03-09 at 09:46:55
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
    int n;
    vector<int> compressed;
    vector<T> original;

    CoordinateCompression(const vector<T> &vec) {
        n = vec.size();
        original = vec;
        compressed.assign(n, 0);
        vector<pair<T, int>> pairs(n);
        for (int i = 0; i < n; ++i) {
            pairs[i] = {vec[i], i};
        }
        sort(pairs.begin(), pairs.end());
        int nxt = 0;
        for (int i = 0; i < n; ++i) {
            if(i > 0 && pairs[i-1].first != pairs[i].first) nxt++;
            compressed[pairs[i].second] = nxt;
        }
    }
};

struct node {
    ll val;
    node() {
        val = 0;
    }
    node(ll val) : val(val) {
    }
    node operator + (const node &rhs) const {
        return node(val + rhs.val);
        // return node(val op rhs.val);
    }
};

struct SegTree {
    int n;
    vector<node> t;

    SegTree(int n) : n(n) {
        t.assign(4 * n, 0);
    }

    SegTree(vector<int> &a) {
        n = a.size();
        t.resize(4 * n);
        build(1, 0, n - 1, a);
    }

    void build(int pos, int l, int r, vector<int> &a) {
        if(l == r) {
            t[pos] = node(a[l]);
            return; 
        }
        int m = (l + r) / 2;
        build(2 * pos, l, m, a);
        build(2 * pos + 1, m + 1, r, a);
        t[pos] = t[2 * pos] + t[2 * pos + 1];
    }

    void update(int i, int val, int pos, int l, int r) {
        if(l == r) {
            t[pos] = node(val);
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
    int n;
    cin >> n;

    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    CoordinateCompression<int> cc(vec);
    vec = cc.compressed;

    SegTree aux(n);
    vector<int> parcial(n);  
    for (int j = n - 1; j >= 0; j--) {
        parcial[j] = aux.query(0, vec[j] - 1).val;
        aux.update(vec[j], 1);
    }

    vector<ll> ans(n);
    SegTree cnt(n);
    ll sum = 0;
    for (int i = n - 1; i >= 0; i--) {
        ans[i] = cnt.query(0, vec[i] - 1).val;
        sum += ans[i];
        cnt.update(vec[i], parcial[i]);
    }

    cout << sum << endl;

    return 0;
}