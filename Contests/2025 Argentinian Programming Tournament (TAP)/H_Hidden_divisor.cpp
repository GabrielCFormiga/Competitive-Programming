/**
* @file H_Hidden_divisor.cpp
* @author GabrielCampelo
* Created on 2026-02-08 at 11:34:38
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

ll isqrt(ll n) {
    ll x = (ll)sqrt((double)n);
    while (x > 0 && x * x > n) x--;
    while ((x + 1) * (x + 1) <= n) x++;
    return x;
}

bool is_prime(ll x) {
    if (x < 2) return false;
    for (ll i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() { _
    int n;
    cin >> n;
    
    vector<ll> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    sort(all(vec));

    if (vec[0] != 1) {
        cout << vec[n - 1] << ' ' << 1 << endl;
        return 0;
    }

    if (vec[0] == 1 && n == 1) {
        cout << '*' << endl;
        return 0;
    }

    if (n == 2) {
        // 1 p p*p
        if (is_prime(vec[1])) {
            // p*p = vec[1] * vec[1]
            cout << vec[1] * vec[1] << ' ' << vec[1] * vec[1] << endl;
        } else {
            // p*p = vec[1]
            cout << vec[1] << ' ' << isqrt(vec[1]) << endl;
        }
        return 0;
    }

    if (n == 3) {
        if (vec[2] % vec[1] == 0) {
            cout << vec[2] << ' ' << vec[2] / vec[1] << endl;
        } else {
            cout << vec[2] * vec[1] << ' ' << vec[2] * vec[1] << endl;
        }
        return 0;
    }

    bool ans_nao_aparece = true;
    ll ans = vec[n - 1] * vec[1];
    int l = 2, r = n - 2;
    while (l <= r) {
        if (vec[l] * vec[r] != ans) {
            ans_nao_aparece = false;
        }
        l++;
        r--;
    }

    if (ans_nao_aparece) {
        cout << ans << ' ' << ans << endl;
        return 0;
    } else {
        ll ans = vec[n - 1];
        map<ll, ll> mp;
        for (int i = 0; i < n; i++) {
            mp[vec[i]] = ans / vec[i];
        }
        
        for (auto p : mp) {
            if (mp.find(p.second) == mp.end()) {
                cout << ans << ' ' << p.second << endl;
                return 0;
            }
        }

        cout << ans << ' ' << isqrt(ans) << endl;
    }

    return 0;
}