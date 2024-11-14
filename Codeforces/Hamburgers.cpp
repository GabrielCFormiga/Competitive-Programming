/**
* @file Hamburgers.cpp
* https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/H
*
* Created on 2024-11-14 at 02:19:03
* @author GabrielCampelo
*/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long llu;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

string recipe;
ll nb, ns, nc, pb, ps, pc, r;
ll b = 0, s = 0, c = 0;

bool good(ll k) {
    ll cost = 0;
    ll buy;

    // bread
    buy = b * k - nb;
    if (buy < 0) buy = 0;
    cost += pb * buy;

    // sausage
    buy = s * k - ns;
    if (buy < 0) buy = 0;
    cost += ps * buy;

    // chease
    buy = c * k - nc;
    if (buy < 0) buy = 0;
    cost += pc * buy;

    return cost <= r;
}

int main() { _
    cin >> recipe >> nb >> ns >> nc >> pb >> ps >> pc >> r;

    for (int i = 0; i < recipe.size(); i++) {
        if (recipe[i] == 'B') b++;
        else if (recipe[i] == 'S') s++;
        else c++;
    }

    ll l = 0, r = 1e12 + 100;
    ll m, ans;
    while (l <= r) {
        m = l + (r - l) / 2;

        if (good(m)) {
            ans = m;
            l = m + 1;
        }
        else r = m - 1;
    }

    cout << ans << endl;

    return 0;
}