/**
* @file M_Medical_Parity.cpp
* @author GabrielCampelo
* Created on 2025-12-17 at 08:01:37
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

const int MAX_N = 1000100;

string x, y;
int dp[MAX_N][2];

int main() { _
    int tt;
    cin >> tt;
    while (tt--) {
        cin >> x >> y;

        if (x[0] == y[0]) {
            dp[0][x[0] - '0'] = 0;
            dp[0][(x[0] - '0') ^ 1] = 2;
        } else {
            dp[0][x[0] - '0'] = 1;
            dp[0][(x[0] - '0') ^ 1] = 1;
        }

        for (int i = 1; i < x.size(); i++) {
            if (x[i] == y[i]) {
                if (x[i] == '1') {
                    dp[i][1] = min(dp[i - 1][0], dp[i - 1][1] + 1);
                    dp[i][0] = min(dp[i - 1][0] + 2, dp[i - 1][1] + 1);
                } else { 
                    dp[i][0] = min(dp[i - 1][0], dp[i - 1][1] + 1);
                    dp[i][1] = min(dp[i - 1][1] + 1, dp[i - 1][0] + 2);
                }
            } else {
                if (x[i] == '1') {
                    dp[i][1] = min(dp[i - 1][1] + 2, dp[i - 1][0] + 1);
                    dp[i][0] = min(dp[i - 1][0] + 1, dp[i - 1][1]);
                } else {
                    dp[i][0] = min(dp[i - 1][0] + 1, dp[i - 1][1] + 2);
                    dp[i][1] = min(dp[i - 1][1], dp[i - 1][0] + 1);
                }
            }
        }

        cout << min(dp[x.size() - 1][0], dp[x.size() - 1][1]) << endl;
    } 
    
    return 0;
}