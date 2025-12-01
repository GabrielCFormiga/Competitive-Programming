/**
* @file Array Description.cpp
* @author GabrielCampelo
* Created on 2025-12-01 at 00:43:43
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

#define MAX_N 100100

int n, ub;
int ar[MAX_N];
int dp[MAX_N][102];

int main() { _
    cin >> n >> ub;

    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }

    if (ar[0] != 0) {
        dp[0][ar[0]] = 1;
    } else {
        for (int i = 1; i <= ub; i++) {
            dp[0][i] = 1;
        }
    }

    for (int i = 1; i < n; i++) {
        if (ar[i] != 0) {
            dp[i][ar[i]] = ((dp[i - 1][ar[i] - 1] + dp[i - 1][ar[i] + 1]) % MOD + dp[i - 1][ar[i]]) % MOD; 
        } else {
            for (int j = 1; j <= ub; j++) {
                dp[i][j] = ((dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD + dp[i - 1][j]) % MOD;
            }
        }
    }

    int ans = 0;

    for (int j = 1; j <= 100; j++) {
        ans = (ans + dp[n - 1][j]) % MOD;
    }

    cout << ans << endl;
    
    return 0;
}