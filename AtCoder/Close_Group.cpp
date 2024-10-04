/**
* @file Close_Group.cpp
* https://atcoder.jp/contests/abc187/tasks/abc187_f
*
* Created on 2024-10-04 at 14:37:34
* @author GabrielCampelo
*/

#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;
const int INF = 0x3f3f3f3f;

#define N_MAX 18

int adj[N_MAX][N_MAX];

int main() { _
    int n, m, u, v;
    cin >> n >> m;

    while (m--) {
        cin >> u >> v;
        u--;
        v--;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    
    vector<int> dp((1 << n), INF);
    dp[0] = 0;

    // verificar cliques
    vector<bool> is_clique((1 << n));
    for (int i = 1; i < (1 << n); i++) {
        vector<int> nodes;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) nodes.pb(j);
        }

        is_clique[i] = true;
        for (int j = 0; j < nodes.size(); j++) {
            for (int k = j + 1; k < nodes.size(); k++) {
                if (adj[nodes[j]][nodes[k]] == 0) {
                    is_clique[i] = false;
                    break;
                }
            }
            if (!is_clique[i]) break;
        }
    } 

    // iterar pelas mascaras e por suas submascaras
    for (int i = 1; i < (1 << n); i++) {
        // mascara
        if (is_clique[i]) dp[i] = 1;

        for (int s = i; s > 0; s = (s - 1) & i) {
            // submascara
            dp[i] = min(dp[i], dp[s] + dp[i^s]);
        }
    }

    cout << dp[(1 << n) - 1] << endl;

    return 0;
}