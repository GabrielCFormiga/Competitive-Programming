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
    int n;
    cin>>n;

    int ans = 0;
    int p = n;
    while (p) {
        if (p%10 > 0 && n%(p%10) == 0) ans++;
        p /= 10;
    }
    cout << ans << endl;
}

int main() {
    fcin;
    solve();
}