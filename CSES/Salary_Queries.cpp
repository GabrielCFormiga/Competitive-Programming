/**
* @file Salary_Queries.cpp
* @author GabrielCampelo
* Created on 2026-03-08 at 21:28:33
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
    ll val;
    node() {
        val = 0;
    }
    node(int val) : val(val) {
    }
    node operator + (const node &rhs) const {
        return node(val + rhs.val);
        // return node(val op rhs.val);
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


int main() { _
    int n, q;
    cin >> n >> q;

    vector<int> vec(n);
    vector<int> coords;
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
        coords.pb(vec[i]);
    }

    vector<pair<char, pair<int, int>>> queries;
    for (int i = 0; i < q; i++) {
        char op;
        cin >> op;
        if (op == '!') {
            int k, x;
            cin >> k >> x;
            k--;
            queries.pb({op, {k, x}});
            coords.pb(x);
        } else {
            int a, b;
            cin >> a >> b;
            queries.pb({op, {a, b}});
            coords.pb(a);
            coords.pb(b);
        }
    }

    CoordinateCompression<int> cc(coords);
    vector<int> cnt(cc.d.size(), 0); 
    for (int i = 0; i < n; i++) {
        vec[i] = cc.get_id(vec[i]);
        cnt[vec[i]]++;
    }

    SegTree seg(cnt);

    for (int i = 0; i < q; i++) {
        char op = queries[i].first;

        if (op == '!') {
            int k = queries[i].second.first, x = queries[i].second.second;
            int qtd = seg.query(vec[k], vec[k]).val;
            seg.update(vec[k], qtd - 1);

            x = cc.get_id(x);
            vec[k] = x;
            qtd = seg.query(x, x).val;
            seg.update(x, qtd + 1);
        } else {
            int a = queries[i].second.first, b = queries[i].second.second;
            a = cc.get_id(a);
            b = cc.get_id(b);
            cout << seg.query(a, b).val << endl;
        }
    }
    
    return 0;
}