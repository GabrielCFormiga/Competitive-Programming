/**
* @file Card_Trick.cpp
* @author GabrielCampelo
* Created on 2025-12-13 at 21:45:09
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

const int MAXN = 20100;
int ans[MAXN];

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

        BIT bit(n);
        
        for (int i = 0; i < n; i++) {
            bit.add(i, 1); // posicao livre
        }

        int curr = 0;

        for (int i = 1; i <= n; i++) {
            int empty = n - (i - 1);

            curr = (curr + i) % empty;

            int k = curr + 1; // quero colocar o elemento na k-ésima posição livre

            int l = 0, r = n - 1;
            int m;

            while (l < r) {
                m = l + (r - l) / 2;
                if (bit.sum(m) >=  k) r = m;
                else l = m + 1;
            }

            ans[l] = i;
            bit.add(l, -1);
        }

        for (int i = 0; i < n; i++) {
            cout << ans[i] << (i == n - 1 ? endl : ' ');
        }
    } 
    
    return 0;
}