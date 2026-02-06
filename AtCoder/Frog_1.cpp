/**
* @file Frog_1.cpp
* @author GabrielCampelo
* Created on 2026-02-05 at 14:46:22
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
    
    vector<int> h(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }

    vector<int> dp(n + 1);
    dp[2] = abs(h[2] - h[1]);

    for (int i = 3; i <= n; i++) {
        dp[i] = min(abs(h[i] - h[i - 1]) + dp[i - 1], abs(h[i] - h[i - 2]) + dp[i - 2]);
    }
    
    cout << dp[n] << endl;

    return 0;
}