/**
* @file Money_Sums.cpp
* @author GabrielCampelo
* Created on 2026-02-09 at 13:28:03
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

const int MAX_X = 100100;

bool dp[2][MAX_X];

int main() { _
    int n;
    cin >> n;

    dp[0][0] = dp[1][0] = true;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        int curr = i % 2;
        int prev = 1 - curr;

        for (int j = 0; j < MAX_X; j++) {
            dp[curr][j] = dp[prev][j];

            if (j >= x) {
                dp[curr][j] |= dp[prev][j - x];
            }
        }
    }

    vector<int> ans;

    for (int j = 1; j < MAX_X; j++) {
        if (dp[(n - 1) % 2][j]) {
            ans.pb(j);
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << (i == ans.size() - 1? endl : ' ');
    }

    return 0;
}