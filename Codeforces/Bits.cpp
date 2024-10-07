/**
* @file Bits.cpp
* https://codeforces.com/problemset/problem/484/A
*
* Created on 2024-10-07 at 02:30:39
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

ll get_bit(ll x, int at) {
    return x & (1LL << at);
}

ll solve(ll l, ll r) {
    if (l == r) return l;
    
    int at = 62;
    ll candidato = 0;
    while (get_bit(l, at) == get_bit(r, at)) {
        candidato |= get_bit(l, at);
        at--;
    }

    // 2^at = 1000..., 2^at - 1 = 0111...
    candidato |= (1LL << at) - 1;
    return (__builtin_popcountll(r) > __builtin_popcountll(candidato) ? r : candidato); 

} 

int main() { _
    int q;
    ll l, r;
    
    cin >> q;
    while (q--) {
        cin >> l >> r;
        cout << solve(l, r) << endl;
    }
    
    return 0;
}