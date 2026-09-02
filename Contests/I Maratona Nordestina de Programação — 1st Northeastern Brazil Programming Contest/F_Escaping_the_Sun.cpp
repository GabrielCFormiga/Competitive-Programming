/**
* @file F_Escaping_the_Sun.cpp
* @author GabrielCampelo
* Created on 2026-08-24 at 16:18:56
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

int n, h;

vector<double> dist;
vector<vector<pair<int, double>>> adj; // {to, dist}

double getdist(ll x1, ll y1, ll r1, ll x2, ll y2, ll r2) {
    ll x = x1 - x2;
    ll y = y1 - y2;
    ll dd = x * x + y * y;
    return max(0.0, sqrt(dd) - r1 - r2);
};

const double EPS = 1e-9;

void dijkstra(int s) {
    dist[s] = 0.0;

    using pi = pair<double, int>;
    priority_queue<pi, vector<pi>, greater<pi>> q;
    q.emplace(0,s);
    while (!q.empty()) {
        auto [w,u] = q.top();
        q.pop();

        if (u == n + 1) break;
        if (w > dist[u] + EPS) continue;

        for (auto [v,W] : adj[u]) {
            if (w+W < dist[v]) {
                dist[v] = w+W;
                q.emplace(w+W,v);
            }
        }
    }
}

int main() { _
    cin >> n >> h;
    
    adj.resize(n + 2);
    dist.assign(n + 2, LINF);

    adj[0].pb({n + 1, h});
    adj[n + 1].pb({0, h});

    vector<pair<pair<int, int>, int>> vec(n + 2); //{{x, y}, r}

    for (int i = 1; i <= n; i++) {
        int x, y, r;
        cin >> x >> y >> r;
        vec[i] = {{x, y}, r};

        // MAR
        double d = max(0, y - r);
        adj[0].pb({i, d});
        adj[i].pb({0, d});

        // CALC
        d = max(0, h - y - r);
        adj[n + 1].pb({i, d});
        adj[i].pb({n + 1, d});
    }

    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            double d = getdist(
                vec[i].first.first,
                vec[i].first.second,
                vec[i].second,
                vec[j].first.first,
                vec[j].first.second,
                vec[j].second
            );
            adj[i].pb({j, d});
            adj[j].pb({i, d});
        }
    }

    dijkstra(0);

    cout << fixed << setprecision(10) << dist[n + 1] << endl;

    return 0;
}