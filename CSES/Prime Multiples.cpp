/**
* @file Prime Multiples.cpp
*
* Created on 2025-11-05 at 01:09:25
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

ll n;
int k;
ll ans = 0;

vector<ll> primes;

void solve(ll curr, int idx, int sig) {
    if (idx == k) {
        if (curr == 1) return;
        ans += sig * (n / curr);
        return;
    }

    if (curr <= n / primes[idx]) solve(curr * primes[idx], idx + 1, sig * -1);
    solve(curr, idx + 1, sig);
}

int main() { _
    cin >> n >> k;

    primes.resize(k);

    for (int i = 0; i < k; i++) cin >> primes[i];

    solve(1, 0, -1);

    cout << ans << endl;

    return 0;
}