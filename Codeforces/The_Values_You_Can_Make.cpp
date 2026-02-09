/**
* @file The_Values_You_Can_Make.cpp
* @author GabrielCampelo
* Created on 2026-02-05 at 17:36:46
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

const int MAX_N = 550;

bool dp[2][MAX_N][MAX_N]; // dp[i][j] = true -> exists a subset of sum i that has a subset of sum j

int main() { _
    int n, k;
    cin >> n >> k;
    
    dp[0][0][0] = dp[1][0][0] = true;

    for (int i = 0; i < n; i++) {
        int coin;
        cin >> coin;
        
        int curr = i % 2;
        int prev = 1 - curr;
    
        for (int i = 0; i <= k; i++) {
            for (int j = 0; j <= i; j++) {
                dp[curr][i][j] = dp[prev][i][j];

                if (i >= coin) {
                    dp[curr][i][j] |= dp[prev][i - coin][j];

                    if (j >= coin) {
                        dp[curr][i][j] |= dp[prev][i - coin][j - coin];
                    }
                }
            }
        }
    }

    vector<int> ans;

    for (int j = 0; j <= k; j++) {
        if (dp[(n - 1) % 2][k][j]) {
            ans.pb(j);
        }
    }

    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << (i == ans.size() - 1? endl : ' ');
    }

    return 0;
}