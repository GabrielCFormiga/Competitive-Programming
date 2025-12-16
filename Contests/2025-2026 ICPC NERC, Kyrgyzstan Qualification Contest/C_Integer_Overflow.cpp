/**
* @file C_Integer_Overflow.cpp
* @author GabrielCampelo
* Created on 2025-12-16 at 01:42:09
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
    ll a, b;
    cin >> a >> b;

    int ta = 32;
    if (a > 2147483647) ta = 64;

    int tb = 32;
    if (b > 2147483647) tb = 64;
    
    int tc;
    int mx = max(ta, tb);

    if (mx == 32) {
        if (a * b <= 2147483647) {
            tc = 32;
        } else {
            tc = 64;
        }
    } else {
        const ll UB = 9223372036854775807LL;
        // UB >= a * b -> UB / a >= b
        if (UB / a >= b) tc = mx;
        else tc = 128; 
    }

    if (ta != tc && tb != tc) {
        if (tc + tb + tc <= ta + tc + tc) {
            ta = tc;
        } else {
            tb = tc;
        }
    }

    cout << ta << endl;
    cout << tb << endl;
    cout << tc << endl;

    return 0;
}