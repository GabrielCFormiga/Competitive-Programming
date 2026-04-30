/**
* @file I_AM_VERY_BUSY.cpp
* @author GabrielCampelo
* Created on 2026-03-01 at 18:28:53
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

int main() { _
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;

        vector<pair<int, int>> vec(n);
        for (int i = 0; i < n; i++) {
            int l, r;
            cin >> l >> r;
            vec[i] = {l, r};
        }

        sort(all(vec), [](pair<int, int> &a, pair<int, int> &b) {
            if (a.second == b.second) {
                return a.first < b.first;
            }
            return a.second < b.second;
        });

        int curr = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (vec[i].first >= curr) {
                ans++;
                curr = vec[i].second;
            }
        }

        cout << ans << endl;
    } 
    
    return 0;
}