/**
* @file Serval_and_The_Formula.cpp
*
* Created on 2025-03-23 at 21:38:20
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

int main() { _
    int tt;
    cin >> tt;
    while (tt--) {
        ll x, y;
        cin >> x >> y;

        if (x == y) {
            cout << -1 << endl;
            continue;
        }

        if (x + y == (x ^ y)) {
            cout << 0 << endl;
            continue;
        }

        ll k = 1;
        while (k < max(x, y)) k <<= 1;
        k = k - max(x, y);

        cout << k << endl; 
    } 
    
    return 0;
}

        