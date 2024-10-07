/**
* @file And_Or.cpp
* https://vjudge.net/problem/UVA-12898
*
* Created on 2024-10-07 at 09:26:34
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
    b = X1B
    a = X0A
    
    OR:
    a|(a + 1)|(a + 2)|...|b = X11111...
    
    AND:
    a&(a + 1)&(a + 2)&...&b = X00000...    
*/  

ll get_bit(ll x, int at) {
    return x & (1LL << at);    
}

ll solve_or(ll a, ll b) {
    if (a == b) return a;

    ll res = 0;
    int at = 62;
    while (get_bit(a, at) == get_bit(b, at)) {
        res |= get_bit(a, at);
        at--;
    }

    return res + (1LL << ++at) - 1;

}

ll solve_and(ll a, ll b) {
    if (a == b) return a;

    ll res = 0;
    int at = 62;
    while (get_bit(a, at) == get_bit(b, at)) {
        res |= get_bit(a, at);
        at--;
    }

    return res;
}

int main() { _
    int tt;
    ll a, b;
    
    cin >> tt;
    for (int i = 1; i <= tt; i++) {
        cin >> a >> b;
        cout << "Case " << i << ": ";
        cout << solve_or(a, b) << " " << solve_and(a, b) << endl;
    }

    return 0;
}