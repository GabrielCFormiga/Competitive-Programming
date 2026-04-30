/**
* @file Integer_Factorization_(15_digits).cpp
* @author GabrielCampelo
* Created on 2026-02-21 at 21:10:40
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

int main() { _
    ll n;
    while (cin >> n && n != 0) {
        bool first = true;
        for (ll i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                int pot = 0;
                while (n % i == 0) {
                    pot++;
                    n /= i;
                }

                if (first) {
                    cout << i << '^' << pot;
                    first = false; 
                } else {
                    cout << ' ' << i << '^' << pot;
                }
            }
        }
        if (n > 1) {
            if (first) cout << n << '^' << 1;
            else cout << ' ' << n << '^' << 1;
        }
        cout << endl;
    }
    
    return 0;
}