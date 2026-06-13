/**
* @file Hotel_Queries.cpp
* @author GabrielCampelo
* Created on 2026-06-11 at 13:39:16
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
        val = -1;
    }
    node(ll val) : val(val) {
    }
    node operator + (const node &rhs) const {
        return node(max(val, rhs.val));
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

    void build(int pos, int tl, int tr, vector<int> &a) {
        if(tl == tr) {
            t[pos] = node(a[tl]);
            return; 
        }
        int tm = (tl + tr) / 2;
        build(2 * pos, tl, tm, a);
        build(2 * pos + 1, tm + 1, tr, a);
        t[pos] = t[2 * pos] + t[2 * pos + 1];
    }

    void update(int i, int new_val, int pos, int tl, int tr) {
        if(tl == tr) {
            t[pos] = node(new_val);
            return;
        }
        int tm = (tl + tr) / 2;
        if(i <= tm) update(i, new_val, 2 * pos, tl, tm);
        else update(i, new_val, 2 * pos + 1, tm + 1, tr);
        t[pos] = t[2 * pos] + t[2 * pos + 1];
    }
    void update(int i, int new_val) { 
        update(i, new_val, 1, 0, n - 1);
    }

    node query(int l, int r, int pos, int tl, int tr) {
        if(r < tl || tr < l) return node();
        if(l <= tl && tr <= r) return t[pos];
        int tm = (tl + tr) / 2;
        return query(l, r, 2 * pos, tl, tm) + query(l, r, 2 * pos + 1, tm + 1, tr);
    }
    node query(int l, int r) {
        return query(l, r, 1, 0, n - 1);
    }
};

int main() { _
    int n, m;
    cin >> n >> m;

    vector<int> rooms(n);
    vector<int> groups(m);

    for (int i = 0; i < n; i++) {
        cin >> rooms[i];
    }
    
    SegTree seg(rooms);

    for (int i = 0; i < m; i++) {
        cin >> groups[i];

        int l = 0, r = n;
        int mid;
        while (l < r) {
            mid = l + (r - l) / 2;
            if (seg.query(0, mid).val >= groups[i]) r = mid;
            else l = mid + 1;
        }
        int ans;
        if (l == n) {
            ans = 0;
        } else {
            ans = l + 1;
            seg.update(l, seg.query(l, l).val - groups[i]);
        }
        cout << ans << (i == m - 1 ? endl : ' '); 
    }
    
    return 0;
}