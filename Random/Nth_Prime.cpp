/**
* @file Nth_Prime.cpp
* @author GabrielCampelo
* Created on 2026-02-19 at 12:41:10
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

const int MAX_N = 10000000;

int main() { _
    int n;
    cin >> n;

    vector<bool> isprime(MAX_N, true);
    vector<int> primes;
    for (ll i = 2; i < INF; i++) {
        if (isprime[i]) {
            primes.pb(i);
            if (primes.size() == n) {
                cout << primes.back() << endl;
                return 0;
            }
            for (ll j = i * i; j < MAX_N; j += i) {
                isprime[j] = false;
            }
        }
    }

    return 0;
}