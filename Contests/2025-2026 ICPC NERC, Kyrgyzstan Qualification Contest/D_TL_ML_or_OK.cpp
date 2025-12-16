/**
* @file D_TL_ML_or_OK.cpp
* @author GabrielCampelo
* Created on 2025-12-16 at 01:59:31
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
    ll n;
    cin >> n;

    ll q;
    cin >> q;

    ll k;
    cin >> k;

    ll op = n * (2 * q + 5 * k);

    string s;
    cin >> s;

    string ans;

    if (s == "cpp") {
        if (op <= 5e8) ans = "OK";
        else ans = "TL";
    } else  if (s == "java") {
        if (op <= 1e8) ans = "OK";
        else ans = "TL";
    } else {
        if (op <= 2e7) ans = "OK";
        else ans = "TL";
    }

    ll memo = n * k;

    if (memo > 2e7) {
        if (ans == "OK") ans = "ML";
        else ans += " and ML";
    }

    cout << ans << endl;
    
    return 0;
}