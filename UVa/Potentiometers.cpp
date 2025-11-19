/**
* @file Potentiometers.cpp
* @author GabrielCampelo
* Created on 2025-11-18 at 17:43:22
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
    for (int tt = 1; tt < 3; tt++) {
        int n;
        cin >> n;

        if (n == 0) break;
        if (tt > 1) cout << endl;
        cout << "Case " << tt << ":" << endl;

        vector<ll> resistance(n);

        for (int i = 0; i < n; i++) {
            cin >> resistance[i];
        }

        BIT bit(resistance);

        string op;
        int x, y;

        while (cin >> op && op != "END") {
            cin >> x >> y;
            
            if (op == "S") {
                x--;
                int og = bit.sum(x, x);
                bit.add(x, y - og);
            } else {
                x--;
                y--;
                cout << bit.sum(x, y) << endl;
            }
        }


    }
    
    return 0;
}