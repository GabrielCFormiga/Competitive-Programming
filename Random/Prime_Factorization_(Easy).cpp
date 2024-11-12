/**
* @file Prime_Factorization_(Easy).cpp
* https://codeforces.com/group/OyefIGO3t4/contest/447287/problem/D
*
* Created on 2024-11-12 at 18:52:49
* @author GabrielCampelo
*/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;

typedef long long ll;

int main() { _
    ll n;
    cin >> n;

    bool first = true;

    for (ll i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            n /= i;
            
            if (first) {
                cout << i;
                first = false;
            } else {
                cout << ' '  << i;
            }
        }
    }

    if (n > 1) {
        if (first) cout << n << endl;
        else cout << ' ' << n << endl;
    }
    
    return 0;
}