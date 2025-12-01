/**
* @file Minimizing Coins.cpp
* @author GabrielCampelo
* Created on 2025-11-30 at 23:35:21
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

#define MAX_N 1000100

int dp[MAX_N];
int coins[MAX_N];

int main() { _
    int n, x;
    cin >> n >> x;

    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    sort(coins, coins + n);

    for (int i = 1; i <= x; i++) {
        dp[i] = INF;
    }

    for (int i = 0; i <= x; i++) {
        for (int c = 0; c < n; c++) {
            if (i + coins[c] > x) break;
            dp[i + coins[c]] = min(dp[i + coins[c]], dp[i] + 1);
        }
    }

    cout << (dp[x] == INF ? -1 : dp[x]) << endl;

    return 0;
}