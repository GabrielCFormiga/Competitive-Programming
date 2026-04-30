/**
* @file Iroha and a Grid.cpp
*
* Created on 2025-11-10 at 13:44:10
* @author GabrielCampelo
*/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;

int main() { _
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    // fat
    vector<int> fat(n + m);
    fat[0] = fat[1] = 1;
    for (int i = 2; i < n + m; i++) {
        fat[i] = 1ll * fat[i - 1] * i % MOD;
    }

    // inv
    vector<int> inv(n + m);
    inv[0] = inv[1] = 1;
    for (int i = 2; i < n + m; i++) {
        inv[i] = MOD - 1ll * (MOD / i) * inv[MOD % i] % MOD;
    }

    // fatinv
    vector<int> fatinv(n + m);
    fatinv[0] = fatinv[1] = 1;
    for (int i = 2; i < n + m; i++) {
        fatinv[i] = 1ll * fatinv[i - 1] * inv[i] % MOD;
    }

    ll ans = 0;
    for (int i = 1; i <= n - a; i++) {
        ans += (1ll * fat[b + i - 2] * fatinv[b - 1] % MOD * fatinv[i - 1] % MOD) 
        * (1ll * fat[n + m - b - i - 1] * fatinv[n - i] % MOD * fatinv[m - b - 1] % MOD);
        ans %= MOD; 
    }

    cout << ans << endl;

    return 0;
}