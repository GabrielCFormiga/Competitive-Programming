/**
* @file Klee's_SUPER_DUPER_LARGE_Array!!!.cpp
* https://codeforces.com/contest/2009/problem/E
*
* Created on 2024-11-24 at 03:46:17
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
    int tt;
    cin >> tt;
    while (tt--) {
        ll n, k;
        cin >> n >> k;

        ll l = 1, r = n;
        ll m;

        ll sn = (2 * k + n - 1) * n / 2;

        ll ans = LINF;
        while (l <= r) {
            m = l + (r - l) / 2;

            // 2 * si
            ll si = (2 * k + m - 1) * m;

            if (si >= sn) {
                ans = min(ans, si - sn);
                r = m - 1;
            } else {
                ans = min(ans, sn - si);
                l = m + 1;
            } 
        }

        cout << ans << endl;
    } 
    
    return 0;
}