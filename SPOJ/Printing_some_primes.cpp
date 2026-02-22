/**
* @file Printing_some_primes.cpp
* @author GabrielCampelo
* Created on 2026-02-21 at 20:39:14
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

const int MAXN = 1e8;

int main() { _
    vector<bool> isprime(MAXN, true);
    vector<int> primes;
    primes.pb(2);
    
    for (int i = 3; i < MAXN; i += 2) {
        if (isprime[i]) {
            primes.pb(i);
            for (ll j = 1LL * i * i; j < MAXN; j += i) {
                isprime[j] = false;
            }
        }
    }

    for (int i = 0; i < primes.size(); i += 100) {
        cout << primes[i] << endl;
    }
    
    return 0;
}