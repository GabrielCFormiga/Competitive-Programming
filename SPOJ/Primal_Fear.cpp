/**
* @file Primal_Fear.cpp
* @author GabrielCampelo
* Created on 2026-02-21 at 20:45:17
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

const int MAXN = 1e6 + 5;

int main() { _
    vector<bool> isprime(MAXN, true);
    isprime[0] = isprime[1] = false;
    vector<int> primes;
    
    for (int i = 2; i < MAXN; i++) {
        if (isprime[i]) {
            primes.pb(i);
            for (ll j = 1LL * i * i; j < MAXN; j += i) {
                isprime[j] = false;
            }
        }
    }

    vector<int> afraid;
    for (int &p : primes) {
        string pp = to_string(p);
        if (pp.find('0') != string::npos) continue;
        
        bool afraidof = true;
        for (int i = 10; i < MAXN; i *= 10) {
            if (!isprime[p % i]) {
                afraidof = false;
                break;
            }
        }

        if (afraidof) afraid.pb(p);
    }

    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;

        int l = -1, r = afraid.size() - 1;
        int m;

        while (l < r) {
            m = l + (r - l + 1) / 2;
            if (afraid[m] <= n) l = m;
            else r = m - 1;
        }

        cout << l + 1 << endl;
    } 
    
    return 0;
}