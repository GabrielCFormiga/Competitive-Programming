/**
* @file Crayon.cpp
* https://www.spoj.com/problems/CRAYON/
* @author GabrielCampelo
* Created on 2026-05-14 at 16:55:02
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

struct BIT {
	int n;
	vector<ll> t;

	BIT(int n) : n(n) {
		t.assign(n + 1, 0);
	}
	BIT(vector<ll> const &a) {
		n = a.size();
		t.assign(n + 1, 0);
		for (int i = 1; i <= n; ++i) {
			t[i] += a[i - 1];
			int j = i + (i & -i);
			if (j <= n) t[j] += t[i];
		}
	}

	ll query(int i) {
		ll ret = 0;
		for (++i; i > 0; i -= i & -i) ret += t[i];
		return ret;
	}
	ll query(int l, int r) {
		return query(r) - query(l - 1);
	}

	void update(int i, ll add) {
		for (++i; i <= n; i += i & -i) t[i] += add;
	}
};

int main() { _
    int n;
    cin >> n;

    vector<tuple<char, int, int>> queries(n);
    vector<pair<int, int>> segments; 
    vector<int> coords;

    for (int i = 0; i < n; i++) {
        char op;
        cin >> op;

        if (op == 'D') {
            int l, r;
            cin >> l >> r;
            coords.pb(l);
            coords.pb(r);
            queries[i] = make_tuple(op, l, r);
            segments.pb({l, r});
        } else if (op == 'C') {
            int idx;
            cin >> idx;
            queries[i] = make_tuple(op, idx, 0);
        } else {
            int l, r;
            cin >> l >> r;
            coords.pb(l);
            coords.pb(r);
            queries[i] = {op, l, r};
        }
    }

    CoordinateCompression<int> cc(coords);
    BIT L(coords.size()), R(coords.size());

    int qtd = 0;
    for (auto q : queries) {
        char op = get<0>(q);
        int l = get<1>(q);
        int r = get<2>(q);
        if (op == 'D') {
            L.update(cc.get_id(l), 1);
            R.update(cc.get_id(r), 1);
            qtd++;
        } else if (op == 'C') {
            int idx = l - 1;
            int l = segments[idx].first;
            int r = segments[idx].second;
            L.update(cc.get_id(l), -1);
            R.update(cc.get_id(r), -1);
            qtd--;
        } else {
            int lft = (cc.get_id(l) - 1 >= 0 ? R.query(0, cc.get_id(l) - 1): 0);
            int rgh = (cc.get_id(r) + 1 < coords.size() ? L.query(cc.get_id(r) + 1, coords.size() - 1): 0);
            cout << qtd - lft - rgh << endl;
        }
    }
    return 0;
}