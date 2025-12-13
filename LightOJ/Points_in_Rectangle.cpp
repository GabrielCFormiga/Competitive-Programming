/**
* @file Points_in_Rectangle.cpp
* @author GabrielCampelo
* Created on 2025-12-13 at 03:00:29
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

struct BIT2D {
	vector<vector<ll>> bit;
	int n, m;

	BIT2D(int n, int m) {
		this->n = n;
        this->m = m;
		bit.assign(n, vector<ll>(m, 0));
	}

	BIT2D(vector<vector<ll>> const &a) : BIT2D(a.size(), a[0].size()) {
		for (int i = 0; i < a.size(); ++i) {
            for (int j = 0; j < a[0].size(); ++j) {
                bit[i][j] += a[i][j];
                int r = i | (i + 1);
                int c = j | (j + 1);
                if (r < n) bit[r][j] += bit[i][j];
                if (c < m) bit[i][c] += bit[i][j];
                if (r < n && c < m) bit[r][c] -= bit[i][j];
            }
        }
	}

	ll sum(int x, int y) {
		ll ret = 0;
		for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
            for (int j = y; j >= 0; j = (j & (j + 1)) - 1)
                ret += bit[i][j];
        return ret;
	}

    ll sum(int x1, int y1, int x2, int y2) {
        return sum(x2, y2) - sum(x1 - 1, y2) - sum(x2, y1 - 1) + sum(x1 - 1, y1 - 1);
    }

	void add(int x, int y, ll delta) {
        for (int i = x; i < n; i = i | (i + 1))
            for (int j = y; j < m; j = j | (j + 1))
                bit[i][j] += delta;
	}
};


int main() { _
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) {
        cout << "Case " << t << ":\n";

        int q;
        cin >> q;

        BIT2D bit(1001, 1001);

        while (q--) {
            int op;
            cin >> op;

            if (op == 0) {
                int x, y;
                cin >> x >> y;

                if (bit.sum(x, y, x, y) == 0) {
                    bit.add(x, y, 1);
                }

            } else {
                int x1, y1, x2, y2;
                cin >> x1 >> y1 >> x2 >> y2;

                cout << bit.sum(x1, y1, x2, y2) << endl;
            }
        }
    } 
    
    return 0;
}