/**
* @file Snuke_Festival.cpp
*
* Created on 2025-10-27 at 16:05:16
* @author GabrielCampelo
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

    vector<vector<int>> vec(3, vector<int>(n + 1));
    
    for (int i = 0; i < 3; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> vec[i][j];
        }
    }

    sort(all(vec[0]));
    sort(all(vec[1]));
    sort(all(vec[2]));

    vector<ll> prefix(n + 1);

    for (int j = 1; j <= n; j++) {
        int x = vec[1][j];

        int l = 1, r = n + 1;
        int m;

        while (l < r) {
            m = l + (r - l) / 2;

            if (vec[2][m] > x) r = m;
            else l = m + 1;
        }

        prefix[j] = (n + 1) - l + prefix[j - 1];
    }

    ll ans = 0;

    for (int j = 1; j <= n; j++) {
        int x = vec[0][j];

        int l = 1, r = n + 1;
        int m;

        while (l < r) {
            m = l + (r - l) / 2;

            if (vec[1][m] > x) r = m;
            else l = m + 1;
        }

        if (r == n + 1) break;

        ans += prefix[n] - prefix[r - 1];
    }

    cout << ans << endl;

    return 0;
}   