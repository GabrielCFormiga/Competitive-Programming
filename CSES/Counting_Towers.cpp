/**
* @file Counting Towers.cpp
* @author GabrielCampelo
* Created on 2025-12-01 at 17:40:13
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

ll dp[2][MAX_N];

int main() { _
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;

        dp[0][1] = dp[1][1] = 1;

        for (int i = 2; i <= n; i++) {
            dp[0][i] = (2 * dp[0][i - 1] + dp[1][i - 1]) % MOD;
            dp[1][i] = (4 * dp[1][i - 1] + dp[0][i - 1]) % MOD;
        }

        cout << (dp[0][n] + dp[1][n]) % MOD << endl;
    } 
    
    return 0;
}