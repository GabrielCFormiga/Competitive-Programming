/**
* @file Curious_Robin_Hood.cpp
* @author GabrielCampelo
* Created on 2025-12-13 at 02:50:43
*/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef unsigned long long llu;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct BIT {
	vector<ll> bit;
	int n;

	BIT(int n) {
		this->n = n;
		bit.assign(n, 0);
	}

	BIT(vector<ll> const &a) : BIT(a.size()) {
		for (int i = 0; i < a.size(); ++i) {
			bit[i] += a[i];
			int r = i | (i + 1);
			if (r < n) bit[r] += bit[i];
		}
	}

	ll sum(int r) {
		ll ret = 0;
		for (; r >= 0; r = (r & (r + 1)) - 1)
			ret += bit[r];
		return ret;
	}

	ll sum(int l, int r) {
		return sum(r) - sum(l - 1);
	}

	void add(int idx, ll delta) {
		for (; idx < n; idx = idx | (idx + 1))
			bit[idx] += delta;
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
        for (int i = 0; i < n; i++) cin >> vec[i];

        BIT bit(vec);

        while (q--) {
            int op;
            cin >> op;

            if (op == 1) {
                int i;
                cin >> i;
                ll x = bit.sum(i, i);
                cout << x << endl;
                bit.add(i, -x);
            } else if (op == 2) {
                int i, v;
                cin >> i >> v;
                bit.add(i, v);
            } else {
                int i, j;
                cin >> i >> j;
                cout << bit.sum(i, j) << endl;
            }
        }
    } 
    
    
    return 0;
}