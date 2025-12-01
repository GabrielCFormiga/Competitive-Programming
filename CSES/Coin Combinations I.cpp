/**
* @file Coin Combinations I.cpp
* @author GabrielCampelo
* Created on 2025-11-30 at 23:46:44
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

const int MOD = 1e9 + 7;

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

    dp[0] = 1;
    for (int i = 0; i <= x; i++) {
        for (int c = 0; c < n; c++) {
            if (i + coins[c] > x) break;
            dp[i + coins[c]] = (dp[i + coins[c]] + dp[i]) % MOD;
        }
    }

    cout << dp[x] << endl;
    return 0;
}