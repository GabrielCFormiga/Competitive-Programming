/**
* @file Two_Sets_II.cpp
* @author GabrielCampelo
* Created on 2026-02-09 at 16:38:53
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
const int MAX_N = 510;

int dp[2][(MAX_N + 1) * MAX_N / 2 + 1];

// debbug
void printdp(int n) {
    for (int i = 0; i <= n % 2; i++) {
        for (int j = 0; j <= (1 + n) * n / 2; j++) {
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }
}

int inv(int a, int m){
    return a <= 1 ? a : m - (long long)(m / a) * inv(m % a, m) % m;
}

int main() { _
    int n;
    cin >> n;

    dp[0][0] = dp[1][0] = 1;

    for (int i = 1; i <= n; i++) {
        int curr = i % 2;
        int prev = 1 - curr;
        for (int j = 0; j < (MAX_N + 1) * MAX_N / 2 + 1; j++) {
            dp[curr][j] = dp[prev][j];
            if (j >= i) {
                dp[curr][j] = (dp[curr][j] + dp[prev][j - i]) % MOD;
            }
        }
        // printdp(n);
    }

    if ((1 + n) * n / 2 % 2 != 0) {
        cout << 0 << endl;
    } else {
        cout << 1ll * dp[n % 2][(1 + n) * n / 4] * inv(2, MOD) % MOD << endl;
    }

    return 0;
}