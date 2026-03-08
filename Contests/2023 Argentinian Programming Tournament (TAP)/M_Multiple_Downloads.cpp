#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<ll> v64;
typedef vector<int> v32;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define INF 0x3fffffff
#define LLINF 0x3fffffffffffffff
#define PI 3.14159265358979323846
#define endl '\n'
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define pb push_back
#define fcin                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);
template<class T> using ordered_set = 
tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

const double inf = 1e18;

void solve() {
    int n;
    double sp;
    cin>>n>>sp;
    multiset<double> pri, npri;
    for (int i = 0; i < n; i++) {
        char c;
        double k;
        cin>>c>>k;
        if (c == 'P') pri.insert(k);
        else npri.insert(k);
    }

    double time = 0;
    while (true) {
        int p = sz(pri), np = sz(npri);
        if (p == 0 && np == 0) break;

        double ps, nps;
        if (p && np) {
            ps = sp * .75 / p;
            nps = sp * .25 / np;
        }
        else if (p) {
            ps = sp / p;
        }
        else if (np) {
            nps = sp / np;
        }

        double t = inf;
        for (auto k : pri) {
            t = min(t, k/ps);
        }
        for (auto k : npri) {
            t = min(t, k/nps);
        }
        if (abs(t-inf) <= 1e-9) break;

        multiset<double> nw1, nw2;
        for (auto k : pri) {
            double dw = max(0.0, k - t*ps);
            if (abs(dw) <= 1e-9) continue;
            nw1.insert(dw);
        }
        for (auto k : npri) {
            double dw = max(0.0, k - t*nps);
            if (abs(dw) <= 1e-9) continue;
            nw2.insert(dw);
        }
        pri = nw1;
        npri = nw2;
        time += t;
    }
    cout << fixed << setprecision(10) << time << endl;
}

int main() {
    fcin;
    solve();
}