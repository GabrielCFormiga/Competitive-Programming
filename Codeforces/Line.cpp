/**
* @file Line.cpp
* https://codeforces.com/problemset/problem/7/C
*
* Created on 2024-11-10 at 01:30:59
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

// ax + by = gcd(a, b)
ll exgcd(ll a, ll b, ll *x, ll *y) {
    if (a == 0) {
        *x = 0;
        *y = 1;
        return b;
    }

    ll x1, y1;
    ll gcd = exgcd(b % a, a, &x1, &y1);

    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}

// ax + by = gcd(a, b)
ll eexgcd(ll a, ll b, ll &x, ll &y){
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}

	ll d = eexgcd(b, a % b, x, y);
	ll z = x;
	x = y;
	y = z - (a / b) * y;
	return d;
}

int main() { _
    ll a, b, c;
    cin >> a >> b >> c;

    // xa + yb = -c
    c = -c;

    ll x, y;
    ll g = exgcd(a, b, &x, &y);

    if (c % g == 0) cout << x * (c / g) << ' ' << y * (c / g) << endl;
    else cout << -1 << endl;
    
    return 0;
}