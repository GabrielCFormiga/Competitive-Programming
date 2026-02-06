/**
* @file Vacation.cpp
* @author GabrielCampelo
* Created on 2026-02-05 at 18:08:24
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
    int n;
    cin >> n;
    
    vector<tuple<int, int, int>> vec(n);

    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        vec[i] = make_tuple(a, b, c);
    }

    vector<vector<int>> dp(n, vector<int>(3));
    
    dp[0][0] = get<0>(vec[0]);
    dp[0][1] = get<1>(vec[0]);
    dp[0][2] = get<2>(vec[0]);

    for (int i = 1; i < n; i++) {
        dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + get<0>(vec[i]);
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + get<1>(vec[i]);
        dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + get<2>(vec[i]);
    }

    cout << max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]}) << endl;

    return 0;
}