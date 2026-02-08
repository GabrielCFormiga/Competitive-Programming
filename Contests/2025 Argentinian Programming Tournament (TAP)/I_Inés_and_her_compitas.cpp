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

void solve() {
    int n,m;
    cin>>n>>m;
    vector<pii> r(m);
    vector<v32> g(m,v32(n));
    for (int i = 0; i < 2*m; i++) {
        cin>>r[i].F>>r[i].S;
        for (int j = 0; j < n; j++)
            cin>>g[i][j];
    }
    ll ans = 0;
    v64 val(n);
    for (int i = 0; i < m; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (g[i][j] == 1) cnt++;
            else val[j] += r[i].S;
        }
        if (r[i].F/(cnt+1) >= r[i].S) {
            cnt++;
            ans += r[i].F/cnt;
        }
        else ans += r[i].S;
        for (int j = 0; j < n; j++) {
            if (g[i][j] == 1) val[j] += r[i].F/cnt;
        }
    }
    for (ll i : val) cout << i << ' ';
    cout << ans << endl;
}

int main() {
    fcin;
    solve();
}