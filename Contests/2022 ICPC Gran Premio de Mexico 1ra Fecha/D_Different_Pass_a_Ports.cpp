/**
* @file D_Different_Pass_a_Ports.cpp
* @author GabrielCampelo
* Created on 2026-03-15 at 10:05:09
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

const int MAXN = 101;
const int MAXK = 100001;
const int MOD = 1e9 + 7;

vector<vector<int>> adj;
int dp[2][MAXN];

int main() { _
    int n, m, k;
    cin >> n >> m >> k;

    adj.resize(n);

    for (int i = 0; i < n; i++) {
        dp[i][0] = 1;
    }

    while (m--) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    
    for (int i = 0; i < n; i++) dp[0][i] = 1;
    //cout << solve(0, k) << endl;
    for (int i = 1; i <= k; i++) {
        int cur = i%2;
        int prv = (i-1)%2;
        for (int j = 0; j < n; j++) {
            ll sum = 0;
            for (int u : adj[j]) {
                sum += dp[prv][u];
            }
            while (sum >= MOD) sum -= MOD;
            dp[cur][j] = sum;
        }
    }

    cout << dp[k%2][0] << endl;

    return 0;
}