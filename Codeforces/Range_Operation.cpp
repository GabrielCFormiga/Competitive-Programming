/**
* @file c.cpp
* @author GabrielCampelo
* Created on 2025-11-14 at 12:00:51
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

        vector<ll> prefix(n + 1);
        vector<int> vec(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> vec[i];
            prefix[i] = prefix[i - 1] + vec[i];
        }

        ll ans = -LINF;

        // para um intervalo [l, r] 
        // curr =  1ll * (r - l + 1) * (l + r) - (prefix[r] - prefix[l - 1]
        // curr = rl + rr - ll - rl + l + r - prefix[r] + prefix[l - 1]
        // curr = (rr + r - prefix[r]) - (ll - l - prefix[l - 1]) 

        vector<ll> mn(n + 1);
        for (int i = 1; i <= n; i++) {
            mn[i] = min(mn[i - 1], 1ll * i * i - i - prefix[i - 1]); 
        }

        for (int r = 1; r <= n; r++) {
            ans = max(ans, 1ll * r * r + r - prefix[r] - mn[r]);
        }

        cout << prefix[n] + ans << endl;        
    } 
    
    return 0;
}