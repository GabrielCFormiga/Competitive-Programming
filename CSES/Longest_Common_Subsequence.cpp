/**
* @file Longest Common Subsequence.cpp
* @author GabrielCampelo
* Created on 2025-12-10 at 18:47:34
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

int n, m;
vector<int> a, b;

int solve(int i, int j, vector<vector<int>> &dp) {
    if (dp[i][j] != -1) return dp[i][j];

    if (i == 0 || j == 0) return dp[i][j] = 0;

    if (a[i - 1] == b[j - 1]) return dp[i][j] = 1 + solve(i - 1, j - 1, dp);
    
    return dp[i][j] = std::max(solve(i - 1, j, dp), solve(i, j - 1, dp));
}

int main() { _
    cin >> n >> m;
    a.resize(n);
    b.resize(m);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    cout << solve(n, m, dp) << endl;

    stack<int> lcs;
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            lcs.push(a[i - 1]);
            i--;
            j--;
        } else if (dp[i - 1][j] >= dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    while (!lcs.empty()) {
        cout << lcs.top() << " ";
        lcs.pop();
    }
    cout << endl;

    return 0;
}