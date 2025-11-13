/**
* @file d.cpp
*
* Created on 2025-06-10 at 15:08:08
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
    int n, m, p, s;
    cin >> n >> m >> p >> s;

    int MAX_MASK = (1 << n) - 1;
    vector<int> verifica(MAX_MASK + 1, true);

    for (int mask = 0; mask <= MAX_MASK; mask++) {
        int cnt_p = 0;
        for (int j = 0; j < p; j++) {
            if (mask & (1 << j)) cnt_p++;
        }

        int cnt_s = 0;
        for (int j = p; j < p + s; j++) {
            if (mask & (1 << j)) cnt_s++;
        }

        if (cnt_p == 0 || cnt_p > 1 || cnt_s > 1 || cnt_s == 0) verifica[mask] = false;
    }

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;

        for (int mask = 0; mask <= MAX_MASK; mask++) {
            if ((mask & (1 << (x - 1))) && (mask & (1 << (y - 1)))) {
                verifica[mask] = false;
            }
        }
    }
    
    int ans = 0;

    for (int i = 0; i < verifica.size(); i++) {
        if (verifica[i]) ans++;
    }

    cout << ans << endl;

    return 0;
}