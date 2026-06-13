/**
* @file List_Removals.cpp
* @link https://cses.fi/problemset/task/1749
* @author GabrielCampelo
* Created on 2026-06-12 at 11:15:24
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
struct Node {
    int val = 0;
    Node() = default;
    Node(int v) : val(v) {}
    Node operator+(const Node &rhs) const { return Node(val + rhs.val); }
};

template <typename Node>
struct SegTree {
    int n;
    vector<Node> t;
    
    SegTree(int n) : n(n), t(4 * n) {}
    SegTree(const vector<int> &a) : SegTree(a.size()) {
        build(1, 0, n - 1, a);
    }

    void build(int pos, int tl, int tr, const vector<int> &a) {
        if(tl == tr) { t[pos] = Node(1); return; }
        int tm = (tl + tr) / 2;
        build(2 * pos, tl, tm, a);
        build(2 * pos + 1, tm + 1, tr, a);
        t[pos] = t[2 * pos] + t[2 * pos + 1];
    }

    void update(int i, int new_val, int pos, int tl, int tr) {
        if(tl == tr) { t[pos] = Node(new_val); return; }
        int tm = (tl + tr) / 2;
        if(i <= tm) update(i, new_val, 2 * pos, tl, tm);
        else update(i, new_val, 2 * pos + 1, tm + 1, tr);
        t[pos] = t[2 * pos] + t[2 * pos + 1];
    }
    void update(int i, int new_val) { update(i, new_val, 1, 0, n - 1); }

    Node query(int l, int r, int pos, int tl, int tr) {
        if(r < tl || tr < l) return Node();
        if(l <= tl && tr <= r) return t[pos];
        int tm = (tl + tr) / 2;
        return query(l, r, 2 * pos, tl, tm) + query(l, r, 2 * pos + 1, tm + 1, tr);
    }
    Node query(int l, int r) { return query(l, r, 1, 0, n - 1); }

    int bs(int x, int pos, int tl, int tr) {
        if (t[pos].val < x) return -1;
        if (tl == tr) return tl;
        int tm = (tl + tr) / 2;
        if (t[2 * pos].val < x) return bs(x - t[2 * pos].val, 2 * pos + 1, tm + 1, tr);
        else return bs(x, 2 * pos, tl, tm);
    }
    int bs(int x) { return bs(x, 1, 0, n - 1); }
};

int main() { _
    int n;
    cin >> n;

    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    
    SegTree<Node> seg(vec);
    
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        int idx = seg.bs(p);
        cout << vec[idx] << (i == n - 1 ? endl : ' ');
        seg.update(idx, 0);
    }

    return 0;
}