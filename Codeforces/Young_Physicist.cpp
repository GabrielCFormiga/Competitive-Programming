/**
* @file Young_Physicist.cpp
* https://codeforces.com/problemset/problem/69/A
*
* Created on 2025-03-01 at 01:37:24
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

int main() { _
    int n, sx = 0, sy = 0, sz = 0, aux;

    cin >> n;

    while (n--) {
        cin >> aux;
        sx += aux;
        cin >> aux;
        sy += aux;
        cin >> aux;
        sz += aux;
    }

    if (sx == sy && sx == sz && sx == 0) {
        cout << "YES" << endl;
    } else cout << "NO" << endl;

    return 0;
}