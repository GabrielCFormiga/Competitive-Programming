/**
* @file Little_Girl_and_Maximum_XOR.cpp
* https://codeforces.com/problemset/problem/276/D
*
* Created on 2024-10-07 at 03:37:22
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

llu get_bit(llu x, int at) {
    return x & (1ULL << at);    
}

llu solve(ll l, ll r) {
    if (l == r) return 0;

    int at = 62;
    while (get_bit(l, at) == get_bit(r, at)) {
        at--;
    }

    return (1ULL << ++at) - 1;
}

int main() { _
    llu l, r;
    cin >> l >> r;

    cout << solve(l, r) << endl;
    
    return 0;
}