/**
* @file K_Karamelos_at_São_João.cpp
* @author GabrielCampelo
* Created on 2026-08-24 at 15:09:13
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
    int a, x;
    cin >> a >> x;

    int z = 1;
    for (int y = 1; y <= 10000000; y++) {
        if (x * y >= a && x * y % a == 1) {
            cout << y << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}