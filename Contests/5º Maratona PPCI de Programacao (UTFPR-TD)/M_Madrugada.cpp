/**
* @file M_Madrugada.cpp
* @author GabrielCampelo
* Created on 2026-07-25 at 09:59:37
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
    int n, b, v;
    cin >> n >> b >> v;

    b = b - v;

    if (b >= n && b % n == 0) {
        cout << b / n << endl;
    } else {
        cout << -1 << endl;
    }
    
    return 0;
}