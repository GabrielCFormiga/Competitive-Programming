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
    int n,k;
    string s;
    cin>>n>>k>>s;
    string t = s;
    for (int i = 0; i < n; i++) {
        char c = t[i];
        if (c == 'A') {
            t[i] = 'T';
        }
        if (c == 'T') {
            t[i] = 'A';
        }
        if (c == 'C') {
            t[i] = 'G';
        }
        if (c == 'G') {
            t[i] = 'C';
        }
    }

    for (int i = 0; i < n; i++) {
        int val = 0;
        if (s[i] == 'A') val = 0;
        if (s[i] == 'C') val = 1;
        if (s[i] == 'G') val = 2;
        if (s[i] == 'T') val = 3;

        int ms = 0;
        if (t[i] == 'A') ms = 0;
        if (t[i] == 'C') ms = 1;
        if (t[i] == 'G') ms = 2;
        if (t[i] == 'T') ms = 3;

        k ^= val;
        ms = (ms + k) % 4;

        if (ms == 0) t[i] = 'A';
        if (ms == 1) t[i] = 'C';
        if (ms == 2) t[i] = 'G';
        if (ms == 3) t[i] = 'T';
    }
    cout << t << endl;
}

int main() {
    fcin;
    solve();
}