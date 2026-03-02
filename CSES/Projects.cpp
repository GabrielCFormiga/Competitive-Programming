/**
* @file Projects.cpp
* @author GabrielCampelo
* Created on 2026-03-01 at 19:49:54
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

const int MAXN = 200100;

int main() { _
    int n;
    cin >> n;

    vector<int> a(n), b(n), p(n);
    set<int> st;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> p[i];
        st.insert(a[i]);
        st.insert(b[i]);
    }

    map<int, int> compress;
    int sz = 1;
    for (int s : st) {
        compress[s] = sz++;
    }

    vector<vector<pair<int, int>>> projects(sz + 1); // {b, p}
    for (int i = 0; i < n; i++) {
        projects[compress[a[i]]].pb({compress[b[i]], p[i]});
    }

    vector<ll> dp(sz + 1); // dp[i] := max earned being free in day i ans just working before day i
    for (int i = 1; i <= sz; i++) {
        dp[i] = max(dp[i], dp[i - 1]);
        for (int j = 0; j < projects[i].size(); j++) {
            dp[projects[i][j].first + 1] = max(dp[projects[i][j].first + 1], dp[i] + projects[i][j].second);
        }
    }

    cout << dp[sz] << endl;

    return 0;
}