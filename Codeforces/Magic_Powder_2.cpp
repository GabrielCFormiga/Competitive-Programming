/**
* @file Magic_Powder_2.cpp
* https://codeforces.com/problemset/problem/670/D2
*
* Created on 2024-11-17 at 15:58:30
* @author GabrielCampelo
*/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;

typedef long long ll;

#define MAX_N 1000100 

ll n, k;
ll a[MAX_N], b[MAX_N];

bool possible(ll x) {
    ll k_used = 0;

    for (ll i = 0; i < n; i++) {
        if (x * a[i] > b[i]) k_used += x * a[i] - b[i];
        if (k_used > k) return false;
    }

    return true;
}

int main() { _
    cin >> n >> k;

    for (ll i = 0; i < n; i++) cin >> a[i];
    for (ll i = 0; i < n; i++) cin >> b[i];

    ll l = 0, r = 1e10;
    ll m;

    while (l < r) {
        // cout << "l = l" << " r = " << r << endl;
        m = l + (r - l + 1) / 2;

        if (possible(m)) l = m;
        else r = m - 1;
    }

    cout << l << endl;

    return 0;
}