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

ll __lcm(ll a, ll b) {
    return a / __gcd(a, b) * b;
}

bool isprime(ll x) {
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
    ll lcm = 1;
    set<ll> st;
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
        lcm = __lcm(lcm, vec[i]);
        st.insert(vec[i]);
    }

    sort(all(vec));

    if (vec[0] != 1) {
        cout << vec[n - 1] << ' ' << 1 << endl;
        return 0;
    }

    if (n == 1) {
        cout << '*' << endl;
        return 0;
    }

    // caso especial p p^2 p^3 ... p^n-1 : falta p^n
    if (isprime(vec[1])) {
        ll p = vec[1];
        bool valid = true;
        for (int i = 2; i < n; i++) {
            if (vec[i - 1] * p != vec[i]) {
                valid = false;
                break;
            }
        }
        if (valid) {
            cout << p * vec[n - 1] << ' ' << p * vec[n - 1] << endl;
            return 0;
        }       
    }

    if (st.find(lcm) == st.end()) {
        cout << lcm << ' ' << lcm << endl;
    } else {
        for (int i = 0; i < n; i++) {
            if (st.find(lcm / vec[i]) == st.end()) {
                cout << lcm << ' ' << lcm / vec[i] << endl;
                return 0;
            }
        }
        cout << lcm << ' ' << (ll)round(sqrt(lcm)) << endl;
    }

    return 0;
}