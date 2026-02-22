/**
* @file Orac_and_LCM.cpp
* @author GabrielCampelo
* Created on 2026-02-20 at 09:04:51
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

ll lcm(ll a, ll b) {
    return a / __gcd(a, b) * b;
}

int main() { _
    int n;
    cin >> n;
    
    vector<ll> vec(n + 1);
    vector<ll> prefix(n + 1);
    vector<ll> suffix(n + 2);

    for (int i = 1; i <= n; i++) {
        cin >> vec[i];
    }

    prefix[1] = vec[1];
    suffix[n] = vec[n];

    for (int i = 2; i <= n; i++) {
        prefix[i] = __gcd(prefix[i - 1], vec[i]);
    }

    for (int i = n - 1; i >= 1; i--) {
        suffix[i] = __gcd(suffix[i + 1], vec[i]);
    }

    ll ans = lcm(suffix[2], prefix[n - 1]);
   
    for (int i = 2; i <= n - 1; i++) {
        ll gcd = __gcd(prefix[i - 1], suffix[i + 1]);
        ans = lcm(ans, gcd);
    }

    cout << ans << endl;
    
    return 0;
}