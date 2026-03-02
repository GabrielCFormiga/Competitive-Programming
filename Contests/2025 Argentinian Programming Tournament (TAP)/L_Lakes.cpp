/**
* @file L_Lakes.cpp
* @author GabrielCampelo
* Created on 2026-02-12 at 12:38:31
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

const int MAX_N = 100100;
ll dp[2][MAX_N];

int main() { _
    int n, g;
    cin >> n >> g;
    
    vector<int> vec(n + 1);
    vector<ll> prefix(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> vec[i];
        prefix[i] = prefix[i - 1] + vec[i];
    }

    ll ans = 0;
    int kmax = sqrt(2 * n);
    for (int j = 1; j <= n; j++) {
        if (j < kmax) dp[kmax % 2][j] = 0;
        else dp[kmax % 2][j] = g - (prefix[j] - prefix[j - kmax]);
        ans = max(ans, dp[kmax % 2][j]);
    }

    for (int k = kmax - 1; k >= 1; k--) {
        int curr = k % 2;
        int prev = 1 - curr; 

        for (int j = 1; j < k; j++) {
            dp[curr][j] = 0;
        }

        for (int j = k; j <= n; j++) {
            dp[curr][j] = g - (prefix[j] - prefix[j - k]);
            if (j + k + 1 <= n) dp[curr][j] = max(dp[curr][j], dp[curr][j] + dp[prev][j + k + 1]);
            ans = max(ans, dp[curr][j]);
        }
    }

    cout << ans << endl;

    return 0;
}