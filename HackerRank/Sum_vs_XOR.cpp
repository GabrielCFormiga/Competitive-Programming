/**
* @file Sum_vs_XOR.cpp
* https://www.hackerrank.com/challenges/sum-vs-xor/problem
*
* Created on 2024-11-15 at 15:25:35
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

/* 
    n + x >= n
    n ^ x >= n se x soh tem os bits desligados de n ligados
 */

int main() { _
    ll n;
    cin >> n;

    ll ans = 1;

    while (n > 0) {
        ll bit = n & 1;
        if (bit == 0) ans *= 2;
        n >>= 1;
    }

    cout << ans << endl;

    return 0;
}