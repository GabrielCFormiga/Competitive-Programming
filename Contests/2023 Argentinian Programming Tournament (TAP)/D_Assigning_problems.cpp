/**
* @file D_Assigning_problems.cpp
* @author GabrielCampelo
* Created on 2026-03-08 at 09:18:53
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

int k;
vector<int> c;
vector<int> p;

bool possible(int x) {
    ll curr = 0;
    for (int i = 1; i <= k; i++) {
        curr += p[i];
        // need c[i] * x
        if (curr < 1ll * c[i] * x) return false;
        curr -= 1ll * c[i] * x;
    }
    return true;
}

int main() { _
    cin >> k;

    c.resize(k + 1);
    for (int i = 1; i <= k; i++) {
        cin >> c[i];
    }

    p.resize(k + 1);
    for (int i = 1; i <= k; i++) {
        cin >> p[i];
    }

    int l = 0, r = INF;
    int m;
    while (l < r) {
        m = l + (r - l + 1)/2;
        if (possible(m)) l = m;
        else r = m - 1;
    }
    
    cout << l << endl;

    return 0;
}