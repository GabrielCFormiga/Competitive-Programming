/**
* @file L_Games.cpp
* @author GabrielCampelo
* Created on 2026-03-01 at 09:32:31
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

bool ispot2(ll n) {
    ll pot = 2;
    while (pot < n) pot *= 2;
    return pot == n;
}

int main() { _
    int n, q;
    cin >> n >> q;

    vector<ll> vec(n + 1);
    vector<ll> pot2(n + 1), odd(n + 1), qtd1(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> vec[i];
        pot2[i] = pot2[i - 1] + (ispot2(vec[i]) ? vec[i] : 0);
        odd[i] = odd[i - 1] + ((vec[i] % 2 == 1 && vec[i] != 1) ? vec[i] : 0);
        qtd1[i] = qtd1[i - 1] + (vec[i] == 1);
    }

    while (q--) {
        int l, r;
        cin >> l >> r;

        ll q1 = qtd1[r] - qtd1[l - 1];
        ll p2 = pot2[r] - pot2[l - 1];
        ll od = odd[r] - odd[l - 1];

        ll A = (q1 + 1) / 2 + p2;
        ll B = q1 / 2 + od;

        // cout << "A = " << A << " B = " << B << endl;

        if (A > B) cout << 'A' << endl;
        else if (A < B) cout << 'B' << endl;
        else cout << 'E' << endl;
    }
    
    return 0;
}