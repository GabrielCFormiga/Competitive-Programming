/**
* @file Grid Paths I.cpp
* @author GabrielCampelo
* Created on 2025-12-01 at 00:25:00
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

#define MAX_N 1100

int n;
string grid[MAX_N];
int dp[MAX_N][MAX_N];

int main() { _
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    if (grid[0][0] != '*') dp[0][0] = 1;  
    for (int j = 1; j < n; j++) {
        if (grid[0][j] == '*') break;
        dp[0][j] = dp[0][j - 1];
    }

    for (int i = 1; i < n; i++) {
        if (grid[i][0] != '*') {
            dp[i][0] = dp[i - 1][0];
        }
        
        for (int j = 1; j < n; j++) {
            if (grid[i][j] == '*') continue;
            dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % MOD;       
        }
    }

    cout << dp[n - 1][n - 1] << endl;
    
    return 0;
}