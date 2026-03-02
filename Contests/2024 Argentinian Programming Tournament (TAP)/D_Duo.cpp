/**
* @file D_Duo.cpp
* @author GabrielCampelo
* Created on 2026-03-01 at 08:27:16
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
    int a, b, c;
    cin >> a >> b >> c;

    if (c >= a + b || a >= b + c || b >= a + c) cout << 'S' << endl;
    else cout << "N" << endl;
    return 0;
}