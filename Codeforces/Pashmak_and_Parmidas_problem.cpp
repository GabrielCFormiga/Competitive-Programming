/**
* @file Pashmak_and_Parmidas_problem.cpp
* @author GabrielCampelo
* Created on 2026-05-14 at 18:28:27
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
    int m;
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
        m = nxt + 1;
    }
};

struct BIT {
	int n;
	vector<ll> t;

	BIT(int n) : n(n) {
		t.assign(n + 1, 0);
	}
	BIT(vector<int> const &a) {
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
    
    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    CoordinateCompression<int> cc(vec);

    vector<int> total_freq(cc.m);
    int mx = 0;
    for (int &x : cc.compressed) {
        total_freq[x]++;
        mx = max(mx, total_freq[x]);
    }

    vector<int> freq(cc.m);
    vector<int> fl(n);
    vector<int> fr(n);

    for (int i = 0; i < n; i++) {
        freq[cc.compressed[i]]++;
        fl[i] = freq[cc.compressed[i]];
        fr[i] = total_freq[cc.compressed[i]] - fl[i] + 1;
    }

    BIT bit(mx + 1);
    for (int i = 0; i < n; i++) {
        bit.update(fr[i], 1);
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        bit.update(fr[i], -1);
        ans += bit.query(0, fl[i] - 1);
    }

    cout << ans << endl;

    return 0;
}
