/**
* @file d.cpp
* @author GabrielCampelo
* Created on 2025-11-14 at 12:16:57
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

const ll MX = 1000'000'000'000;

int main() { _
    int tt;
    cin >> tt;
    while (tt--) {
        ll x, y, k;
        cin >> x >> y >> k;

        ll n = MX;

        for (int i = 0; i < x; i++) {
            n -= n / y;
        }

        if (n < k) {
            cout << -1 << endl;
            continue; 
        }

        for (int i = 0; i < x; i++) {
            ll l = 1, r = MX;
            ll m;
            while (l < r) {
                m = l + (r - l) / 2;
                if (m - m / y >= k) r = m; 
                else l = m + 1;
            }
            k = l;
        }

        cout << k << endl;
    } 
    
    return 0;
}