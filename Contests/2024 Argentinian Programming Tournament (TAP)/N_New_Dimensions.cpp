/**
* @file N_New_Dimensions.cpp
* @author GabrielCampelo
* Created on 2026-03-01 at 08:33:28
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
    int n;
    cin >> n;

    vector<ll> vec(n);
    ll mn = INF;
    ll mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
        mn = min(mn, vec[i]);
        mx = max(mx, vec[i]);
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ll k1 = vec[i];
            ll k2 = vec[j];
            ll sum = k1*k1 + k2*k2 - k1*k2;
            sum += max(mn*(mn - k1 - k2), mx*(mx - k1 - k2));
            ans = max(ans, sum);
        }
    }

    cout << ans << endl;
    
    return 0;
}