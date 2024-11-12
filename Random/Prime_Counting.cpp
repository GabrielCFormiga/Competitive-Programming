/**
* @file Prime_Counting.cpp
* https://codeforces.com/group/OyefIGO3t4/contest/447287/problem/E
*
* Created on 2024-11-12 at 18:58:36
* @author GabrielCampelo
*/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

using namespace std;

typedef long long ll;

#define MAX_N 100000000

int main() { _
    vector<bool> is_prime(MAX_N + 1, true);
    vector<int> primes;

    is_prime[0] = is_prime[1] = false;

    primes.pb(2);
    for (int i = 3; i <= MAX_N; i += 2) {
        if (is_prime[i]) {
            primes.pb(i);
            for (ll j = (ll) i * i; j <= MAX_N; j += i) is_prime[j] = false;
        }
    }

    int n;
    cin >> n;

    int ans = 0;
    for (int i = 0; i < primes.size(); i++) {
        if (primes[i] > n) break;
        ans++;
    }

    cout << ans << endl;

    return 0;
}