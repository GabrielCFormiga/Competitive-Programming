/**
* @file Knapsack_1.cpp
* @author GabrielCampelo
* Created on 2026-02-05 at 14:36:22
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
    int n, w;
    cin >> n >> w;

    vector<pair<int, int>> vec(n + 1); // {w, v}

    for (int i = 1; i <= n; i++) {
        cin >> vec[i].first >> vec[i].second;
    }

    vector<vector<ll>> dp(n + 1, vector<ll>(w + 1));

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= w; j++) {
            if (vec[i].first > j) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - vec[i].first] + vec[i].second);
            }
        }
    }
    
    cout << dp[n][w] << endl;

    return 0;
}