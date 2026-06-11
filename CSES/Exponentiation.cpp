/**
* @file Exponentiation.cpp
* @link https://cses.fi/problemset/task/1095
* @author GabrielCampelo
* Created on 2026-06-09 at 15:19:26
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

const int MOD = 1e9 + 7;

ll binpow(ll a, ll b) {    
    ll ret = 1;
    while (b) {
        if (b & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        b /= 2;
    }
    return ret;
}

int main() { _
    int tt;
    cin >> tt;
    while (tt--) {
        int a, b;
        cin >> a >> b;
        cout << binpow(a, b) << endl;
    } 
    
    return 0;
}