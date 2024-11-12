/**
* @file Primality_Test_(Easy).cpp
* https://codeforces.com/group/OyefIGO3t4/contest/447287/problem/C
*
* Created on 2024-11-12 at 18:46:55
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

    if (n % 2 == 0) {
        if (n == 2) cout << "YES" << endl;
        else cout << "NO" << endl;
        return 0;
    }

    for (ll i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;

    return 0;
}