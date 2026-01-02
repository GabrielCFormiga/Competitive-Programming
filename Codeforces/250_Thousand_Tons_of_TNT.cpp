/**
* @file 250 Thousand Tons of TNT.cpp
* @author GabrielCampelo
* Created on 2026-01-02 at 14:00:43
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
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;

        vector<int> k_candidates;

        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                k_candidates.pb(i);
                if (n / i != i) k_candidates.pb(n / i);
            }
        }

        vector<int> boxes(n + 1);
        vector<ll> prefix(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> boxes[i];
            prefix[i] = prefix[i - 1] + boxes[i];
        }

        ll ans = 0;

        for (int &k : k_candidates) {
            ll mn = LINF, mx = 0;
            
            for (int i = k; i <= n; i += k) {
                mn = min(mn, prefix[i] - prefix[i - k]);
                mx = max(mx, prefix[i] - prefix[i - k]);
            }

            ans = max(ans, mx - mn);
        }

        cout << ans << endl;
    } 
    
    return 0;
}