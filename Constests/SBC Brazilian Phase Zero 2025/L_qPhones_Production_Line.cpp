/**
* @file l.cpp
*
* Created on 2025-05-24 at 14:05:04
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
    ll m;
    cin >> m;

    // m mega bytes => m * 10^6 bytes => m * 8 * 10^6 bits
    ll memo = m * 8 * 1000000;
    ll ans = 1;
    ll pot = 2;

    while (pot < memo) {
        pot *= 2;
        ans++;
    }
    
    cout << ans << endl;
    
    return 0;
}