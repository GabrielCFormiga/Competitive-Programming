/**
* @file Prime_Factorization_(Medium).cpp
* https://codeforces.com/group/OyefIGO3t4/contest/447287/problem/F
*
* Created on 2024-11-12 at 19:17:42
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

#define MAX_N 10'000'000
#define MAX_P 3162

int main() { _
    vector<bool> is_prime(MAX_P + 1, true);
    vector<int> primes;

    primes.pb(2);

    // O(sqrt(n)log(log(sqrt(n))))
    for (int i = 3; i <= MAX_P; i += 2) {
        if (is_prime[i]) {
            primes.pb(i);
            for (int j = i * i; j <= MAX_P; j += i) is_prime[j] = false;
        }
    }

    int q, n;
    bool first;

    cin >> q;
    while (q--) {
        cin >> n;

        first = true;

        for (int i = 0; i < primes.size(); i++) {
            if (primes[i] > n) break;

            while (n % primes[i] == 0) {
                n /= primes[i];

                if (first) {
                    first = false;
                    cout << primes[i];
                } else {
                    cout << ' ' << primes[i];
                }
            }
        }

        if (n > 1) {
            if (first) cout << n << endl;
            else cout << ' ' << n << endl;
        } else cout << endl;
    }

    
    return 0;
}