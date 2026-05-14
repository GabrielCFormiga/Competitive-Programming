/**
* @file Curious_Robin_Hood.cpp
* @author GabrielCampelo
* Created on 2026-05-11 at 17:02:39
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

struct BIT {
	int n;
	vector<ll> t;

	BIT(int n) : n(n) {
		t.assign(n, 0);
	}
	BIT(vector<ll> const &a) {
		n = a.size();
		t.assign(n, 0);
		for (int i = 0; i < a.size(); ++i) {
			t[i] += a[i];
			int r = i | (i + 1);
			if (r < n) t[r] += t[i];
		}
	}
	
	ll query(int r) {
		ll ret = 0;
		for (; r >= 0; r = (r & (r + 1)) - 1) ret += t[r];
		return ret;
	}
	ll query(int l, int r) {
		return query(r) - query(l - 1);
	}

	void update(int i, ll add) {
		for (; i < n; i = i | (i + 1)) t[i] += add;
	}
};

int main() { _
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) {
        cout << "Case " << t << ":\n";

        int n, q;
        cin >> n >> q;

        vector<ll> vec(n);
        for (int i = 0; i < n; i++) {
            cin >> vec[i];
        }

        BIT bit(vec);

        while (q--) {
            int op;
            cin >> op;

            if (op == 1) {
                int i;
                cin >> i;
                cout << vec[i] << endl;
                bit.update(i, -vec[i]);
                vec[i] = 0;
            } else if (op == 2) {
                int i, v;
                cin >> i >> v;
                bit.update(i, v);
                vec[i] += v;
            } else {
                int i, j;
                cin >> i >> j;
                cout << bit.query(i, j) << endl;
            }
        }
    }
    
    return 0;
}