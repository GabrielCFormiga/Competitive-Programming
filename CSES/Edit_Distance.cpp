/**
* @file Edit Distance.cpp
* @author GabrielCampelo
* Created on 2025-12-01 at 18:15:35
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
    string a, b;
    cin >> a >> b;

    vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1, INF));

    dp[0][0] = 0;

    for (int i = 0; i <= a.size(); i++) {
        for (int j = 0; j <= b.size(); j++) {
            if (i != 0) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
            }

            if (j != 0) {
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
            }

            if (i != 0 && j != 0) {
                int tmp = dp[i - 1][j - 1] + (a[i - 1] != b[j - 1]);
				dp[i][j] = min(dp[i][j], tmp);
            }
        }
    }

    cout << dp[a.size()][b.size()] << endl;

    return 0;
}