#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m, q; cin >> n >> m >> q;

    const double henr = 1.82;

    vector<vector<ll>> dist(n, vector<ll> (n, LINF));
    for (int i = 0; i < n; i++){
        dist[i][i] = 0;
    }
    
    for (int i = 0; i < m; i++){
        ll x, y, d;
        cin >> x >> y >> d;
        double h; cin >> h;

        if (h > 0 && h / henr < 1.25) continue;

        x--, y--;
        dist[x][y] = min(dist[x][y], d);
        dist[y][x] = min(dist[y][x], d);
    }

    for (int k = 0; k < n; k++){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int start = 0;
    while(q--){
        int x; cin >> x;
        x--;

        if (dist[start][x] == LINF){
            cout << -1 << "\n";
            continue;
        }

        cout << dist[start][x] << "\n";

        start = x;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}