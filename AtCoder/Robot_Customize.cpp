/**
* @file Robot Customize.cpp
*
* Created on 2025-11-12 at 16:33:05
* @author GabrielCampelo
*/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef unsigned long long llu;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() { _
    int n;
    cin >> n;
    ll total_w = 0;
    ll ans = 0;
    vector<int> w(n + 1), h(n + 1), b(n + 1), diff(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> h[i] >> b[i];
        total_w += w[i];
        diff[i] = h[i] - b[i];
        ans += b[i];
    }

    // Knapsack
    vector<vector<ll>> dp(n + 1, vector<ll>(total_w/2 + 1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < w[i]; j++) dp[i][j] = dp[i - 1][j];
        for (int j = w[i]; j <= total_w/2; j++) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + diff[i]);     
    }    

    cout << ans + dp[n][total_w/2] << endl;

    return 0;
}