/**
* @file Lucky_Numbers_(easy).cpp
* https://codeforces.com/contest/96/problem/B
*
* Created on 2024-11-14 at 23:57:00
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
    47   -> 01
    4747 -> 0101 

 */

int main() { _
    string s;
    ll n;
    int len;

    cin >> s;
    len = s.size();
    n = stoll(s);

    ll ans = LINF;
    if (len % 2 == 1) {
        // a resposta tem len + 1 digitos
        for (ll mask = (1LL << len + 1) - 1; mask > 0; mask--) {
            if (__builtin_popcount(mask) == (len + 1) / 2) {
                // lucky number
                ll candidato = 0;

                for (int j = 0; j < len + 1; j++) {
                    if (mask & (1LL << j)) candidato += 7 * pow(10, j);
                    else candidato += 4 * pow(10, j);
                }

                if (candidato >= n) ans = min(ans, candidato);
            }
        }
    } else {
        // a resposta tem len ou len + 2 digitos
        for (ll mask = (1LL << len + 2) - 1; mask > 0; mask--) {
            if (__builtin_popcount(mask) == (len + 2) / 2) {
                // lucky number
                ll candidato = 0;

                for (int j = 0; j < len + 2; j++) {
                    if (mask & (1LL << j)) candidato += 7 * pow(10, j);
                    else candidato += 4 * pow(10, j);
                }

                if (candidato >= n) ans = min(ans, candidato);
            }
        }

        for (ll mask = (1LL << len) - 1; mask > 0; mask--) {
            if (__builtin_popcount(mask) == len / 2) {
                // lucky number
                ll candidato = 0;

                for (int j = 0; j < len; j++) {
                    if (mask & (1LL << j)) candidato += 7 * pow(10, j);
                    else candidato += 4 * pow(10, j);
                }

                if (candidato >= n) ans = min(ans, candidato);
            }
        }
    }

    cout << ans << endl;

    return 0;
}