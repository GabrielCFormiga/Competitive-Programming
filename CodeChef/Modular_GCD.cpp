/**
* @file Modular_GCD.cpp
*
* Created on 2025-06-10 at 01:15:34
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

const int MOD = 1e9 + 7;

ll binpow(ll b, ll p, ll m) {
	ll res = 1;
	while (p) {
		if (p & 1) res = (__int128) res * b % m;
		b = (__int128) b * b % m;
		p >>= 1;
	}
	return res;
}

ll gcd(ll a, ll b){
    if(b == 0) return a;
    else return gcd(b, a % b);
}

int main() { _
    int tt;
    cin >> tt;
    
    ll a, b, n;
    while (tt--) {
        cin >> a >> b >> n;

        if (a < b) swap(a, b);
        
        ll m = (a == b ? MOD : a - b);
        ll lhs = (binpow(a, n, m) + binpow(b, n, m)) % m;

        cout << gcd(lhs, a - b) % MOD << endl;

    } 
    
    return 0;
}