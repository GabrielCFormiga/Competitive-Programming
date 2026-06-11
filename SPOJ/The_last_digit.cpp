/**
* @file The_last_digit.cpp
* @link https://www.spoj.com/problems/LASTDIG/
* @author GabrielCampelo
* Created on 2026-06-11 at 11:43:29
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

ll binpow(ll a, ll b, ll m) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = ret * a % m;
        a = a * a % m;
        b /= 2;
    }
    return ret;
}

int main() { _
    int tt;
    cin >> tt;
    while (tt--) {
        ll a, b;
        cin >> a >> b;
        ll ans = binpow(a, b, 1000);
        cout << ans % 10 << endl;
    } 
    
    return 0;
}