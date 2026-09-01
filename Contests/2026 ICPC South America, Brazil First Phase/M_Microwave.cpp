#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

using ll = long long;

#define INF 0x3fffffffffffffff
const int N = 1e5+10;
const int K = 15;
ll dist[N][K];

void solve() {

    for (int i = 0; i < N; i++) for (int j = 0; j < K; j++)
        dist[i][j] = INF;

    int n,m,k;
    cin>>n>>m>>k;

    struct P {
        int v,w,f;
    };
    vector<vector<P>> g(n+5);

    for (int i = 0; i < m; i++) {
        int u,v,f,w;
        cin>>u>>v>>f>>w;
        g[u].push_back({v,f,w});
        g[v].push_back({u,f,w});
    }

    using edge = tuple<ll,ll,ll>;

    priority_queue<edge, vector<edge>, greater<edge>> q;
    dist[1][0] = 0;
    q.emplace(0,1,0);
    while (!q.empty()) {
        auto [w,u,c] = q.top();
        q.pop();

        if (dist[u][c] < w) continue;
        for (auto [v,F,W] : g[u]) {
            if (w+F < dist[v][c]) {
                dist[v][c] = w+F;
                q.emplace(w+F,v,c);
            }
            if (c+1 <= k && W != -1 && W < F && w+W < dist[v][c+1]) {
                dist[v][c+1] = w+W;
                q.emplace(w+W,v,c+1);
            }
        }
    }

    ll ans = INF;
    for (int i = 0; i <= k; i++)
        ans = min(ans, dist[n][i]);
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}