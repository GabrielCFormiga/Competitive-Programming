/**
* @file e.cpp
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

        if (y == 1) {
            cout << -1 << endl;
            continue;
        }

        for (ll i = 0; i < x;) {
            ll add = (k - 1) / (y - 1);
            if (add == 0) break;
            
            ll k_ = (add + 1) * (y - 1) + 1;
            ll cnt = (k_ - k + add - 1) / add;
            cnt = min(cnt, x - i);

            k = k + add * cnt;
            i += cnt;
            
            if (k > MX) break;
        }
        
        cout << (k > MX ? -1 : k) << endl;
    } 
    
    return 0;
}