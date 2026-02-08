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

int lg(ull x) {
    return x ? __builtin_clzll(1) - __builtin_clzll(x) : -1;
}

vector<v32> g;
v32 first, height, euler;

const int N = 4e5+10;
const int K = 20;
int rmq[K][N];

void dfs(int u, int h, int p = -1) {
    first[u] = sz(euler);
    height[u] = h;
    euler.pb(u);
    for (int x : g[u]) {
        if (x == p) continue;
        dfs(x,h+1,u);
        euler.pb(u);
    }
}

int lca(int a, int b) {
    a = first[a];
    b = first[b];
    if (a > b) swap(a,b);
    int i = lg(b-a+1);
    return min(rmq[i][a], rmq[i][b-(1<<i)+1]);
}

void solve() {
    int n;
    cin>>n;
    g.resize(n);
    v32 v(n);
    for (int i = 1; i < n; i++) cin>>v[i];
    for (int i = 0; i < n-1; i++) {
        int u,v;
        cin>>u>>v;
        u--,v--;
        g[u].pb(v);
        g[v].pb(u);
    }

    first.assign(n,INF);
    height.resize(n);
    dfs(0,0);
    for (int i = 0; i < sz(euler); i++) rmq[0][i] = height[euler[i]];
    for (int i = 1; i < K; i++) {
        for (int j = 0; j + (1<<i) <= sz(euler); j++) {
            rmq[i][j] = min(rmq[i-1][j], rmq[i-1][j+(1<<(i-1))]);
        }
    }
    
    pll ans;

    vector<bool> vis(n);
    for (int x : g[0]) {
        queue<tuple<int,int,int>> q;
        q.push({0,x,0});
        vis[x] = true;
        int lst = 0, f = 0, h = 0;
        ll sum = 0;
        while (!q.empty()) {
            auto [a,b,c] = q.front();
            q.pop();
            if (a > lst) {
                if (sum > ans.F) {
                    ans.F = sum;
                    ans.S = height[f]-h;
                }
                else if (sum == ans.F && height[f]-h < ans.S) ans.S = height[f]-h;
                lst = a;
                f = b;
                sum = 0;
            } 
            if (v[b] > 0) {
                if (sum == 0) f = b;
                h = lca(f,b);
                sum += v[b];
            }
            for (int i : g[b]) {
                if (i == c || vis[i]) continue;
                vis[i] = true;
                q.push({a+1,i,b});
            }
        }
        if (sum > ans.F) {
            ans.F = sum;
            ans.S = height[f]-h;
        }
        else if (sum == ans.F && height[f]-h < ans.S) ans.S = height[f]-h;
    }
    cout << ans.F << ' ' << ans.S+1 << endl;
}

int main() {
    fcin;
    solve();
}