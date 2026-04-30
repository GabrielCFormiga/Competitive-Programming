/**
* @file Inversion Count.cpp
* @author GabrielCampelo
* Created on 2025-11-19 at 12:15:33
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
    while (tt--) {
        int n;
        cin >> n;

        map<int, int> ind;
        vector<int> vec(n);
        vector<int> aux(n);

        for (int i = 0; i < n; i++) {
            cin >> vec[i];
            aux[i] = vec[i];
        }

        sort(all(aux));

        for (int i = 0; i < n; i++) {
            ind[aux[i]] = i;
        }

        BIT bit(n);
        ll ans = 0;

        for (int i = 0; i < n; i++) {
            if (ind[vec[i]] < n - 1) ans += bit.sum(ind[vec[i]], n - 1);
            bit.add(ind[vec[i]], 1);
        }

        cout << ans << endl;
    } 
    
    return 0;
}