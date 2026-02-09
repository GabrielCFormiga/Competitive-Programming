/**
* @file Removal_Game.cpp
* @author GabrielCampelo
* Created on 2026-02-09 at 13:36:45
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

const int MAXN = 5100;

ll dp[MAXN][MAXN];

int main() { _
    int n;
    cin >> n;

    vector<int> vec(n + 1);
    ll sum = 0;

    for (int i = 1; i <= n; i++) {
        cin >> vec[i];
        sum += vec[i];
    }

    for (int l = n; l >= 1; l--) {
        for (int r = l; r <= n; r++) {
            if (l == r) {
                dp[l][r] = vec[l];
            } else {
                dp[l][r] = max(vec[l] - dp[l + 1][r], vec[r] - dp[l][r - 1]);
            }
        }
    }

    cout << (sum + dp[1][n]) / 2 << endl;

    return 0;
}