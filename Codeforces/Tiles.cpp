/**
* @file Tiles.cpp
* @link https://codeforces.com/contest/1178/problem/C
* @author GabrielCampelo
* Created on 2026-06-11 at 11:50:09
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

const int MOD = 998244353;

ll binpow(ll a, ll b, ll m) {    
    ll ret = 1;
    while (b) {
        if (b & 1) ret = ret * a % m;
        a = a * a % m;
        b /= 2;
    }
    return ret;
}

int main() { _
    int w, h;
    cin >> w >> h;
    cout << binpow(2, w + h, MOD) << endl;
    return 0;
}