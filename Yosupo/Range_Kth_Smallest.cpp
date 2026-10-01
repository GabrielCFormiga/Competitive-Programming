/**
* @file Range_Kth_Smallest.cpp
* https://judge.yosupo.jp/problem/range_kth_smallest
* @author GabrielCampelo
* Created on 2026-10-01 at 02:30:12
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
    int n;

    CoordinateCompression(const vector<T> &vec) {
        d = vec;
        sort(d.begin(), d.end());
        d.erase(unique(d.begin(), d.end()), d.end());
        n = d.size();
    }

    int get_id(T x) {
        return lower_bound(d.begin(), d.end(), x) - d.begin();
    }

    T get_value(int id) {
        return d[id];
    }
};

struct Node {
    vector<int> inds;
    Node operator+(const Node &rhs) const {
        Node ret;
        ret.inds.resize(inds.size() + rhs.inds.size());
        merge(all(inds), all(rhs.inds), ret.inds.begin());
        return ret; 
    }
    int count(int l, int r) const {
        return upper_bound(all(inds), r) - lower_bound(all(inds), l);
    }
};

template <typename Node>
struct Wavelet {
    int n;
    vector<Node> t;
    
    Wavelet(const vector<int> &a, int sigma) : n(sigma), t(4 * sigma) {
        vector<vector<int>> ap(sigma);
        for (int i = 0; i < a.size(); i++) ap[a[i]].pb(i);
        build(1, 0, n - 1, ap);
    }

    void build(int pos, int tl, int tr, const vector<vector<int>> &ap) {
        if(tl == tr) { 
            t[pos].inds = ap[tl];
            return; 
        }
        int tm = (tl + tr) / 2;
        build(2 * pos, tl, tm, ap);
        build(2 * pos + 1, tm + 1, tr, ap);
        t[pos] = t[2 * pos] + t[2 * pos + 1];
    }

    int query(int l, int r, int k, int pos, int tl, int tr) {
        if (tl == tr) return tl;
        int tm = (tl + tr) / 2;
        int left = t[2 * pos].count(l, r);    
        if (left >= k) return query(l, r, k, 2 * pos, tl, tm);
        else return query(l, r, k - left, 2 * pos + 1, tm + 1, tr);
    }
    int query(int l, int r, int k) { return query(l, r, k, 1, 0, n - 1); }
};

int main() { _
    int n, q;
    cin >> n >> q;
    
    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    CoordinateCompression<int> cc(vec);
    
    vector<int> compressed(n);
    for (int i = 0; i < n; i++) {
        compressed[i] = cc.get_id(vec[i]);
    }

    Wavelet<Node> wv(compressed, cc.n);

    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;
        r--;
        k++;
        cout << cc.get_value(wv.query(l, r, k)) << endl;
    }

    return 0;
}