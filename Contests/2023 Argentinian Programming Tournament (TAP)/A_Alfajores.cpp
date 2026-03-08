/**
* @file A_Alfajores.cpp
* @author GabrielCampelo
* Created on 2026-03-08 at 09:00:51
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
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> e(m);
    for (int i = 0; i < m; i++) {
        cin >> e[i];
    }

    vector<int> vec;
    vec.pb(e[0]);
    int curr = e[0];
    for (int i = 1; i < m; i++) {
        if (e[i] >= curr) continue;
        vec.pb(e[i]);
        curr = e[i];
    }

    for (int i = 0; i < n; i++) {
        int ans = a[i];
        while (ans > 0) {
            int l = 0, r = vec.size();
            int m;
            while (l < r) {
                m = l + (r - l) / 2;
                if (vec[m] > ans) l = m + 1;
                else r = m;
            }
            if (l == vec.size()) break;
            ans = ans % vec[l];
        }
        cout << ans << (i == n - 1 ? endl : ' ');
    }
    
    return 0;
}