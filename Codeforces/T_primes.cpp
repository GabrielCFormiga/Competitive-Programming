/**
* @file T_primes.cpp
* @author GabrielCampelo
* Created on 2026-02-19 at 16:55:26
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

bool isprime(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return x > 1;
}

bool ispersqr(ll x) {
    ll s = sqrt(x) + 0.001;
    return s * s == x;
}

int main() { _
    int n;
    cin >> n;

    while (n--) {
        ll x;
        cin >> x;
        if (ispersqr(x) && isprime(sqrt(x) + 0.001)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}